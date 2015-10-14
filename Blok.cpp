#include "Blok.h"
#include "GlavnoStanje.h"

float Blok::voda_tok;

void Blok::Init(Vec2 poz, unsigned char tip, GlavnoStanje* stanje)
{
	this->poz=poz;
	this->tip=tip;
	
	dim=Vec2(BLOKDIM,BLOKDIM);
	this->stanje=stanje;
		
	if(tip==PRAZNINA)
	{
		tex=stanje->DajMT()->DajTexturu("prazninaDiffuse.tga")->id;		
		texN=stanje->DajMT()->DajTexturu("prazninaNormal.tga")->id;
	}
	if(tip==ZID)
	{
		tex=stanje->DajMT()->DajTexturu("Block.tga")->id;
		texN=stanje->DajMT()->DajTexturu("zid1Normal.tga")->id;
	}
	if(tip==CRVENAVRATA || tip==PLAVAVRATA || tip==ZELENAVRATA)
	{
		tex=stanje->DajMT()->DajTexturu("vrataDiffuse.tga")->id;
		texN=stanje->DajMT()->DajTexturu("vrataNormal.tga")->id;
		texG=stanje->DajMT()->DajTexturu("vrataGlow.tga")->id;
	}
	if(tip==POD)	
	{		
		tex=stanje->DajMT()->DajTexturu("pod1Diffuse.tga")->id;		
		texN=stanje->DajMT()->DajTexturu("prazninaNormal2.tga")->id;
	}
	voda_tok=0.0;
}
void Blok::Render()
{	
	glColor3f(1,1,1);	
	Sprite(poz,dim,tex);
	glColor3f(1,1,1);	
}
void Blok::RenderNormal()
{	
	glColor3f(1,1,1);	
	Sprite(poz,dim,texN);
	glColor3f(1,1,1);		
}
void Blok::RenderGlow()
{
	if(tip!=PRAZNINA && (tip==CRVENAVRATA || tip==PLAVAVRATA || tip==ZELENAVRATA) )
	{
		glColor3f(1,1,1);	
		if(tip==CRVENAVRATA)
			glColor3f(1.0, 0.2, 0.2);
		if(tip==PLAVAVRATA)
			glColor3f(0.2, 0.2, 1.0);
		if(tip==ZELENAVRATA)
			glColor3f(0.2, 1.0, 0.2);
		Sprite(poz,dim,texG);
		glColor3f(1,1,1);
	}
}

		