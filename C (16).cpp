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

ll solution, sum_to [5101], n, k, m, numbers [5101];
ll dp [5101] [5101];

int main()
{
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++)
    {
        cin>>numbers [i];
        sum_to [i] = numbers [i] + sum_to [i - 1];
    }

    for (int i = m; i <= n; i++)
        for (int j = 1; j <= k; j++)
            dp [i] [j] = max (sum_to [i] - sum_to [i - m] + dp [i - m] [j - 1], dp [i - 1] [j]);

    cout<<dp [n] [k]<<endl;

    return 0;
}































