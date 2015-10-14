#include<iostream>
#include<cstdio>
using namespace std;

int O,S,M,a;

int fpow(int stepen)
{
  if (stepen == 0) return 1;
  if (stepen == 1) return O;
  if (stepen % 2 == 0)
  {
  int t = fpow (stepen / 2);
  return t * t;
  }
  else return fpow(stepen - 1)*O;
}

int main()
{
    cin>>O>>S>>M;
  a = fpow(S);
  cout<<a<<endl;
}
