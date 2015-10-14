#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int n, m, rows [1010], solution(1);
char matrix [1010] [1010];

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &matrix [i]);
        int candy(-1), dwarf(-1);
        for (int j = 0; j < m; j++)
        {
            if (matrix [i] [j] == 'S' && dwarf == -1)
            {
                printf ("-1\n");
                return 0;
            }
            else if (matrix [i] [j] == 'G')
                dwarf = j;
            else if (matrix [i] [j] == 'S')
            {
                candy = j;
                rows [i] = candy - dwarf - 1;
            }
        }
    }

    sort (rows, rows + n);

    for (int i = 1; i < n; i++)
    {

        solution += (rows [i] != rows [i - 1]);
    }

    printf ("%d\n", solution);

    return 0;
}

