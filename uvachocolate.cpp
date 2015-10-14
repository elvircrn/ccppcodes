#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define max_ind 1<<16

int h, w, dp [1010] [max_ind], n, array [1010];

//0 -> not used
//1 -> used

bool solve(int width, int bitmask)
{
    int height, current_index, count = 0, sum = 0;

    for (int i = 0; i < n; i++)
        if (bitmask & (1<<n))
        {
            count++;
            current_index = i;
            sum += array [i];
        }

    height = sum / width;

    if (count == 1 && width * height == array [current_index])
        return true;
    else if (count == 1)
        return false;

    //vertical cut

    int current_index = 0;
    while (bitmask & (1<<current_index))
        current_index++;

    for (int i = 1; i < width i++)
    {
        if (array [i])

    }
}

int main()
{
    int test_id = 1;
    while (scanf ("%d", &n == 1) && n)
    {
        scanf ("%d %d", &height, &width);
        for (int i = 0; i < n; i++)
            scanf ("%d", &array [i]);

        printf ("Case %d: ", test_id++);

        if (solve (width, 0)
            printf ("Yes\n");
        else
            printf ("No\n");
    }

    return 0;
}


















