#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

typedef long long int ll;

ll n, m, k;

ll sol, fedora, bits [2000];

ll check(int value)
{
   int index = 1, ret = 0;

   for (int i = 0; i < n; i++)
   {
        if ((index & fedora) != (index & value))
            ret++;

       index <<= 1;
   }

   return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;

    for (int i = 0; i < m; i++)
        cin>>bits [i];

    cin>>fedora;

    for (int i = 0; i < m; i++)
        sol += (check (bits [i]) <= k);

    cout<<sol<<endl;

    return 0;
}






























