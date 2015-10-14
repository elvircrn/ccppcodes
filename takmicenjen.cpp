#include <iostream>
#include <map>
using namespace std;

int niz[1000001];

int main()
{

    int k,n,x,tmp,i,brojac;
    map<int,int>takmicari; brojac=1;


     while( k!=3 ){
            scanf("%d",&k);

            if( k==0 ){
                scanf("%d%d",&n,&tmp);  brojac++;
            }

            if( k==1 ){
                scanf("%d%d",&n,&x);
                if(niz[n]!=brojac) {
                    niz[n]=brojac;
                    takmicari[n]=tmp;
                }
                takmicari[n]+=x;
            }

            if( k==2 ){
                scanf("%d",&n);
                if(niz[n]!=brojac){
                    niz[n]=brojac;
                    takmicari[n]=tmp;
                }
                printf("%d\n",takmicari[n]);
            }
     }


//system("PAUSE");
return 0;
}
