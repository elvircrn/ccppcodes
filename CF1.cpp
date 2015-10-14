#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, c, maximum, array [200];

int main()
{
    cin>>n>>c;
    for (int i = 0; i < n; i++)
        cin>>array [i];

    for (int i = 0; i < n - 1; i++)
    {
        maximum = max ((array [i] - (array [i + 1] + c)), maximum);
    }

    printf ("%d\n", maximum);

    return 0;
}
