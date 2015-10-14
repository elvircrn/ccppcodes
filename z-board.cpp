#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dp [510] [510], n, m;
char matrix [510] [510];

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

        }
    }

    for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < m; j++)
            printf ("%d ", dp [i] [j]);

    return 0;
}
/*
4 4
.....
.....
.....
.....

4 5
....#
.....
.##..
.....
*/























