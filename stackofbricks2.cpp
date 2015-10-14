#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int current_bricks, n, array [200], sum, height;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array [i]);
        sum += array [i];
    }

    int moves = 0;
    height = sum / n;

    for (int i = 0; i < n; i++)
    {
        int dist = 300, ind;

        if (array [i] < height)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (array [j] > height)
                {
                    array [j] += min (height - array [j], )
                }
            }
        }
    }

    printf ("%d\n", moves);

    return 0;
}
