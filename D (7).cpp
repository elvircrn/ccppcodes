#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long n;
int f[20],num,m,maxn,g[10];
long long dp[1<<18][100];

int main()
{
    memset(f,0,sizeof(f));
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    num=0;

    while(n)
    {
        f[num++]=n%10;
        n=n/10;
    }
    maxn=1<<num;
    dp[0][0]=1;
    for(int k=0;k<num;k++)
        if(f[k])dp[1<<k][f[k]%m]+=dp[0][0];
    for(int i=1;i<maxn;i++)
        for(int j=0;j<m;j++)
        {
            if(!dp[i][j])continue;
            for(int k=0;k<num;k++)
                if(!(i&(1<<k)))dp[i|(1<<k)][(j*10+f[k])%m]+=dp[i][j];
        }
    memset(g,0,sizeof(g));
    for(int i=0;i<num;i++)
        g[f[i]]++;
    long long ans=dp[maxn-1][0];
    for(int i=0;i<10;i++)
        for(int j=1;j<=g[i];j++)
            ans=ans/j;

    cout<<ans;
    return 0;
}
