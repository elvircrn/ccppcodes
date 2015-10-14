#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int x[n],y[n];
    for(int i=0;i<n;i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << (x[n-1]-x[0])+(y[n-1]-y[0]) << endl;
    return 0;
}
