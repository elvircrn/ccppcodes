#include <fstream.h>
#include <string.h>

int main(void) {
  char A[102],B[102],*Ptr;
  int I,Suma,Prenos=0;
  ifstream Ulaz("OBRNUTI.IN");
  ofstream Izlaz("OBRNUTI.OUT");
  Ulaz>>A>>B;
  while(strlen(A)<strlen(B)) strcat(A,"0");
  while(strlen(B)<strlen(A)) strcat(B,"0");
  for(I=0;I<strlen(B);I++) {
    Suma=A[I]+B[I]-2*'0'+Prenos; A[I]='0'+Suma%10; Prenos=Suma/10;
  }
  if(Prenos) strcat(A,"1");
  for(Ptr=A+strlen(A)-1;*Ptr=='0';Ptr--) *Ptr=0;
  for(Ptr=A;*Ptr=='0';Ptr++);
  Izlaz<<Ptr;
  return 0;
}
