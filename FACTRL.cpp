#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main () {
    long long int n=1,x;
    cin>>x;
    for(int i=1;i<=x;i++){
            n*=i;
                        while(n%10==0){
                                      n/=10;
                                      }
            n=n%100000;
            }
    cout<<n%10<<endl;
    //system("PAUSE");
}
