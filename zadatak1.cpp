#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, koko=0;
int x[500000], y[500000];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x[i] >> y[i];
        koko += (i != 0) ? (abs (x[i] - x[i-1]) + abs(y[i] - y[i-1])) : 0;
    }
    int result = koko;
    for(int i=1;i<n-1;i++)
    {
        result = min(result, koko - abs(x[i]-x[i-1]) - abs(y[i]-y[i-1])-abs(x[i]-x[i+1])-abs(y[i]-y[i+1])+abs(x[i+1]-x[i-1])+abs(y[i+1]-y[i-1]));
    }
    cout << result << endl;
    return 0;
}
