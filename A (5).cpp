#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;



int main()
{
    int n, m;
    scanf ("%d %d", &n, &m);

    int res = n * m;

    if (n == 1 || m == 1)
    {
        printf ("Akshat\n");
        return 0;
    }

    if (res % 2 == 0)
        printf ("Malvika\n");
    else
        printf ("Akshat\n");

    return 0;
}
