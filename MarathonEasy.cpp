#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int x[500000], y[500000];
int dist;
int dp[500000];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        dist += (i != 0) ? (abs (x[i] - x[i - 1]) + abs (y[i] - y[i - 1])) : 0;
    }

    int res = dist;
    for (int i = 1; i < n - 1; i++)
        res = min(res, dist - abs (x[i] - x[i - 1]) - abs (y[i] - y[i - 1])
                     - abs (x[i] - x[i + 1]) - abs (y[i] - y[i + 1])
                     + abs (x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]));

    cout << res << endl;


    return 0;
}
