#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

char matrix [1010] [1010];
int n, m, dimensions, max_width, max_height, min_width = 1010, min_height = 1010;
bool colored [1010] [1010];

char get(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return '.';
    else
        return matrix [x] [y];
}

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%s", &matrix [i]);

    //min_width
    for (int i = 0; i < n; i++)
    {
        int counter1 = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix [i] [j] == '.' && counter1)
            {
                min_width = min (min_width, counter1);
                max_width = max (max_width, counter1);
                counter1 = 0;
            }
            else if (matrix [i] [j] == '.')
                counter1 = 0;
            else
                counter1++;

        }

        if (counter1 != 0)
            min_width = min (min_width, counter1);
    }

    for (int i = 0; i < m; i++)
    {
        int counter2 = 0;
        for (int j = 0; j < n; j++)
        {

            if (matrix [j] [i] == '.' && counter2)
            {
                min_height = min (min_height, counter2);
                max_height = max (max_height, counter2);
                counter2 = 0;
            }
            else if (matrix [j] [i] == '.')
                counter2 = 0;
            else
                counter2++;
        }
        if (counter2 != 0)
            min_height = min (min_height, counter2);
    }

    dimensions = min (min_width, min_height);

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            /*
                ##
                #.
            */

            if (get(i, j) == '.' && get(i - 1, j - 1) == 'X' && get(i - 1, j) == 'X' && get(i, j - 1) == 'X')
            {
                printf ("-1\n");
                return 0;
            }
            /*
                .#
                ##
            */
            else if (get(i, j) == '.' && get(i + 1, j) == 'X' && get(i, j + 1) == 'X' && get(i + 1, j + 1) == 'X')
            {
                printf ("-1\n");
                return 0;
            }
            /*
                #.
                ##

                ##
                .#
            */
            else if (get (i, j) == '.' && get(i, j - 1) == 'X' && get(i + 1, j - 1) == 'X' && get(i + 1, j) == 'X' ||
                     get (i, j) == '.' && get(i - 1, j) == 'X' && get(i - 1, j + 1) == 'X' && get(i, j + 1) == 'X')
                found = true;
        }
    }

    if (found)
        printf ("%d\n", min(min_width, min_height) * min(min_width, min_height));
    else
        printf ("%d\n", min(min_width, min_height));

    return 0;
}



/*
5 6
......
......
......
XXX...
XXX...
Output
*/






































