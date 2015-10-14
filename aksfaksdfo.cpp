#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
using namespace std;
int n,fix[100],test[100],arr[100][100],i,j,fixf[100],testf[100];
int main()
{
    map<int,int>fix;
    map<int,int>test;
    cin>>n;
    for(i=0;i<n;i++)
        {
            cin>>fixf[i];
            fix[fixf[i]]=i;
        }

    while(cin>>testf[0])
    {
        test[testf[0]]=0;
        for(i=1;i<n;i++)
        {
            cin>>testf[i];
            test[testf[i]]=i;
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(fix[i]==test[j])
                arr[i][j]=arr[i-1][j-1]+1;
                else
                arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
            }
        cout<<arr[n][n]<<endl;
        memset(arr,0,sizeof(arr));
    }
return 0;
}
