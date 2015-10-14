#include <fstream.h>
#include <string.h>

long N,A[50],R[50];

int ImaJe(void) {
  long I;
  for(I=0;I<N;I++)
    if(R[I]>0) return 1;
  return 0;
}

long Br(long B) {
  long I,Rez=1;
  for(I=B;I<N;I++)
    Rez*=(A[I]+(I!=B));
  return Rez;
}

int main(void) {
  long I,J,Poz,H[26];
  char S1[50],S2[50];
  ifstream Ulaz("STRING.IN");
  ofstream Izlaz("STRING.OUT");
  Ulaz>>S1>>S2;
  I=0; A[0]=1; H[S2[0]-'A']=0;
  for(J=1;J<strlen(S2);J++) {
    if(S2[J]!=S2[J-1]) {
      A[++I]=0; H[S2[J]-'A']=I;
    }
    A[I]++;
  }
  N=I+1;
  for(I=0;I<N;I++) R[I]=0;
  for(I=0;I<strlen(S1);I++) R[H[S1[I]-'A']]++;
  Poz=0;
  while(ImaJe()) {
    Poz++; I=0;
    while(!R[I]) Poz+=Br(I++);
    R[I]--; A[I]--;
    for(J=0;J<I;J++) A[J]=0;
  }
  Izlaz<<Poz;
  return 0;
}
