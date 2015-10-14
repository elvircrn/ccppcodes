#include<iostream>
#include<cstdio>
#include<map>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long LL;
typedef map<LL,int>::iterator It;
int t;
void solve()
{
    scanf("[^/n]");
    int n;
    scanf("%d",&n);
    LL s=0,ans=0,t;
    map<LL,int> M;
    M[0]=1;
    REP(i,n)
    {
        scanf("%lld",&t);
        s+=t;
        It a=M.find(s-47);
        if(a!=M.end()) ans+=(*a).second;
        a=M.find(s);
        if(a!=M.end()) (*a).second++;
        else M[s]=1;
    }
    cout<<ans<<endl;
}
int main()
{
    cin>>t;
    while(t–)
    {
        solve();
    }
}
