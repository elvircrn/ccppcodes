#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const char *faces[6] = { "front", "back", "left", "right", "top", "bottom" };
int solution, sol_index, sol_orient, n, cubes [511] [6], dp [511], LIS [511] [6], parent [511] [6], parent_orient [511] [6];

int dance(int x)
{
    return ((x>>1)<<1) + !(x & 1);
}

void rec (int a, int b)
{

    if (a == parent [a] [b])
    {
        printf ("%d %s\n", a + 1, faces [dance (b)]);
        return;
    }

    rec (parent [a] [b], parent_orient [a] [b]);

    printf ("%d %s\n", a + 1, faces [dance (b)]);
}

int main()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out2.txt", "w", stdout);

    int case_id(1);

    scanf ("%d", &n);

    while (n)
    {
        solution = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
                scanf ("%d", &cubes [i] [j]);

        for (int i = 0; i < n; i++)
        {
            for (int si = 0; si < 6; si++)
            {
                LIS [i] [si] = 0;
                parent [i] [si] = i;
                parent_orient [i] [si] = si;

                int min_index = i, min_orient = si;

                for (int j = 0; j < i; j++)
                {
                    for (int sj = 0; sj < 6; sj++)
                    {
                        if (cubes [i] [dance (si)] == cubes [j] [sj] && LIS [j] [sj] + 1 > LIS [i] [si])
                        {
                            LIS [i] [si] = LIS [j] [sj] + 1;
                            min_index  = j;
                            min_orient = sj;
                        }
                    }
                }

                parent [i] [si]        = min_index;
                parent_orient [i] [si] = min_orient;

                if (LIS [i] [si] >= solution)
                {
                    solution = LIS [i] [si];
                    sol_index = i;
                    sol_orient = si;
                }
            }
        }

        printf ("Case #%d\n", case_id++);
        printf ("%d\n", solution + 1);

        rec (sol_index, sol_orient);

        scanf ("%d", &n);

        if (n)
            printf ("\n");
    }

    return 0;
}










