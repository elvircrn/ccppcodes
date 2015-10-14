#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n,a[500000],b[500000],r,m[500000];

int main ()
{
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        r += (i!=0) ? (abs(a[i]-a[i-1])+abs (b[i]-b[i-1])):0;
    }
        int rez=r;
        for (int i=1;i<n;i++)
        {
            rez=min(rez,r - abs (a[i]-a[i-1])-abs(b[i]-b[i-1])
            -abs(a[i]-a[i+1])-abs(b[i]-b[i+1])
            +abs(a[i+1]-a[i-1])+abs(b[i+1]-b[i-1]));
        }
        cout << rez << endl;
        return 0;
}
