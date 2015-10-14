#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define faster_io() ios_base::sync_with_stdio(false)
#define pb push_back
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define vii vector<pair<int,int>>

const ll MOD = 1000000007;

// --------------------------------------------------------------------------

const int MAX = 100005;

int B[MAX], N;
ll DP[MAX][2];
vector<int> E[MAX];

void dfs(int n, int p)
{
    DP[n][1] = B[n];
    DP[n][0] = 1 - B[n];

    for(int v : E[n]) if(v != p)
    {
        ll old[2];
        old[0] = DP[n][0];
        old[1] = DP[n][1];

        DP[n][0] = DP[n][1] = 0;

        dfs(v,n);

        // Child v is included

        DP[n][0] += DP[v][0] * old[0];
        DP[n][0] %= MOD;
        DP[n][1] += DP[v][1] * old[0];
        DP[n][1] %= MOD;
        DP[n][1] += DP[v][0] * old[1];
        DP[n][1] %= MOD;

        // Child v is not included

        DP[n][0] += DP[v][1] * old[0];
        DP[n][0] %= MOD;
        DP[n][1] += DP[v][1] * old[1];
        DP[n][1] %= MOD;
    }
}

int main()
{
   /* cin >> N;

    f(i,2,N)
    {
        int p;
        cin >> p;
        E[p+1].pb(i), E[i].pb(p+1);
    }

    f(i,1,N) cin >> B[i];
    dfs(1,0);*/

    double a, b;

    cin>>a>>b;

    cout<<(a == b)<<endl;



    return 0;
}
/*

*/






















