#include<iostream>
#include<math.h>
using namespace std;
int main()
{

          int x;
          long long int rj,p1=0,cnt=1,cnt2=-1,p2=1,f,i,j;
          cin>>x;
          for(i=1;i<=200000;i++){
                               cnt++;
                               cnt2--;
                               f=p1+p2;
                               p1=p2;
                               p2=f;
                               if(x==1 || x==-1){
                                        f=1;
                                        cout<<f<<endl;
                                        break;
                                        }
                               if(x==0){
                                          f=0;
                                          cout<<f<<endl;
                                          break;
                                          }
                               if(cnt==x){
                                          cout<<f<<endl;
                                          break;
                                          }
                               if(cnt2==x && cnt%2!=0){
                                          cout<<f<<endl;
                                          break;
                                          }
                               if(cnt2==x && cnt2%2==0){
                                           cout<<"-"<<f<<endl;
                                           break;
                                           }
                                          }
          //system("PAUSE");
}
