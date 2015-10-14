//---------------------------------------------------------------------------

#include <vcl.h>
#include <vfw.h>
#include <stdio.h>
#include <jpeg.hpp>
#include <fstream.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner), capwin( 0 ), inSession( 0 ), peerAddress( "" ), status( 0 ), video( 0 ), slika( 0 )
{
	DoubleBuffered = true;

	ServerSocket1 -> Active = true;
    paintbox = new TPaintBox( this );
    paintbox -> Parent = GroupBox2;
    paintbox -> Width = 320;
    paintbox -> Height = 240;
    paintbox -> Left = 11;
    paintbox -> Top = 18;
    paintbox -> Visible = true;

    video = new Graphics::TBitmap;
    video -> Width = 320;
    video -> Height = 240;

    slika = new TJPEGImage;
}
//---------------------------------------------------------------------------


LRESULT PASCAL noob32(HWND hWnd, LPVIDEOHDR lpVHdr)
{
    static char buffer[1000001];

    if ( !hWnd || !Form1 -> inSession ) return FALSE;

    char filenameBMP[] = "outFrame.bmp";
    char filenameJPG[] = "outFrame.jpg";       
    Graphics::TBitmap * bmp = 0;
    TJPEGImage * jpeg = 0;                   

    capFileSaveDIB( hWnd, filenameBMP );

    try {
    	bmp = new Graphics::TBitmap;     
    	jpeg = new TJPEGImage;

    	bmp -> LoadFromFile( filenameBMP );
	    jpeg -> Assign( bmp );
	    jpeg -> SaveToFile( filenameJPG );
    }
    catch ( Exception & e ) {
	    delete bmp;
    	delete jpeg;
    	return FALSE;
    }
	delete bmp;
    delete jpeg;

    int len = 0;
    FILE * fin = fopen( filenameJPG, "rb" );
    if ( fin ) {
	    while ( !feof( fin ) ) { buffer[ len++ ] = fgetc( fin ); }
    	fclose( fin );

    	String size = String("<") + IntToStr( len ) + String(">");
    	Form1 -> ClientSocket1 -> Socket -> SendBuf( size.c_str(), size.Length() );

    	int num = 0;
    	while ( num < len ) {
    		int sent = Form1 -> ClientSocket1 -> Socket -> SendBuf( buffer + num, len - num );
    	    if ( sent < 1 ) break;
    	    num += sent;
    	}
    }      
    
    return (LRESULT) TRUE;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Button2Click( 0 );

	capwin = capCreateCaptureWindow( "YGP!", WS_CHILD | WS_VISIBLE, 10, 16, 200, 150, GroupBox1 -> Handle, 1 );
    capDriverConnect( capwin, 0 );

    BITMAPINFO binfo;
	capGetVideoFormat( capwin, &binfo, sizeof( binfo ) );
	//capDriverDisconnect( capwin ); 
    binfo.bmiHeader.biWidth = 320;
    binfo.bmiHeader.biHeight = 240;
    if ( !capSetVideoFormat( capwin, &binfo, sizeof( binfo ) ) ) MessageBox( this -> Handle, "Your camera does not support 320x240 video format. There might be trouble displaying it.", "Warning!", 0 );
    capDriverConnect( capwin, 0 );
    capPreviewRate( capwin, 100 );
    capPreviewScale( capwin, true );
    capSetCallbackOnFrame( TForm1::capwin, noob32 );
    capPreview( capwin, true );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	capPreview( capwin, false );
	capDriverDisconnect( capwin );
	capCaptureStop( capwin );
    DestroyWindow( capwin );
    capwin = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	Button2Click( 0 );

    DeleteFile( "outFrame.bmp" );
    DeleteFile( "outFrame.jpg" );
    DeleteFile( "inFrame.jpg" );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close1Click(TObject *Sender)
{
	this -> Close();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	inSession = false;
    ClientSocket1 -> Active = false;
    ClientSocket1 -> Host = Trim( Edit1 -> Text );
    status = 1;	// <CON>
    ClientSocket1 -> Active = true;   
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	StatusBar1 -> SimpleText = "Disconnected.";   
    ClientSocket1 -> Active = false;
    peerAddress = "";
    inSession = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connecting(TObject *Sender,
      TCustomWinSocket *Socket)
{
	StatusBar1 -> SimpleText = "Connecting...";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	peerAddress = Socket -> RemoteAddress;
	StatusBar1 -> SimpleText = "Connected. Calling " + peerAddress + "...";

    if ( status == 1 ) {	// <CON>
	    ClientSocket1 -> Socket -> SendBuf( "<CON>", 5 );
    }
    else if ( status == 2 ) {	// <ACC>
    	inSession = true;
        GroupBox2 -> Caption = ClientSocket1 -> Socket -> RemoteAddress;
		ClientSocket1 -> Socket -> SendBuf( "<ACC>", 5 );
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	ClientSocket1 -> Active = false;   
	StatusBar1 -> SimpleText = "Connection failed.";      
    GroupBox2 -> Caption = "No contact connected";
    peerAddress = "";	
}
//---------------------------------------------------------------------------

inline bool equalPrefix( const char * A, const char * B, const int len ) {
	for (int i = 0; i < len; i++)
    	if ( A[i] != B[i] ) return false;
	return true;
}

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
	static int pos = 0;
	static char buffer[1000001];

    int len = Socket -> ReceiveLength();
    int num = 0;

    while ( num < len ) {
    	int size = Socket -> ReceiveBuf( buffer + pos + num, len - num );
	    num += size;
    }

    pos += len;

   	if ( equalPrefix( buffer, "<CON>", 5 ) ) {	// connect command
   		if ( inSession ) return;

        for (int i = 0, j = 5; j < pos; i++, j++)
        	buffer[i] = buffer[j];
        pos -= 5;

       	ClientSocket1 -> Active = false;
       	ClientSocket1 -> Host = Socket -> RemoteAddress;
       	status = 2;	// ACC
       	ClientSocket1 -> Active = true;
    }
    else if ( equalPrefix( buffer, "<ACC>", 5 ) ) {	// accept connect
        for (int i = 0, j = 5; j < pos; i++, j++)
        	buffer[i] = buffer[j];
        pos -= 5;

    	peerAddress = Socket -> RemoteAddress;
		StatusBar1 -> SimpleText = "Connected to " + peerAddress;
       	inSession = true;
    }
    else {	// image data in buffer
        char * start = strchr( buffer, '<' );
        char * end = strchr( buffer, '>' );
        if ( !start || !end ) return;

        int fileSize = 0;
        char * it = start + 1;
        while ( it != end ) {
        	fileSize = fileSize * 10 + *it - '0';
            it++;
        }

        if ( pos - ( end + 1 - buffer ) >= fileSize ) {	// file transfer complete
        	it = end + 1;
            FILE * fout = fopen("inFrame.jpg", "wb");
            if ( fout ) {
            	while ( fileSize-- ) {
            		fputc( *it, fout );
            	    it++;
            	}
            	fclose( fout );

            	int i = 0;
            	for ( ; it != buffer + pos; it++, i++)
         			buffer[i] = *it;
            	pos = i;

                try {
	                slika -> LoadFromFile( "inFrame.jpg" );
    	            video -> Assign( slika );
        	        paintbox -> Canvas -> Draw( 0, 0, video );
                }
                catch ( Exception & e ) {
                	
                }
            }
        }


    }
}
//---------------------------------------------------------------------------


