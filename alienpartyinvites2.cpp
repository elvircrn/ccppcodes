#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef char* cstring;

int n, m, array [40010], solution = 123123;
char one [10000] [22], two [40000] [22];

int cmp (const void *A, const void *B)
{
    return strcmp ((char*)B, (char*)A);
}

int find_index (int index)
{
    int Left = 0, Right = n, pivot;

    while (Left <= Right)
    {
        pivot = (Left + Right) / 2;
        int comp = strcmp (two [index], one [pivot]);

        if (comp == 0)
            return pivot;
        //str1 < str2
        else if (comp == -1)
            Right = pivot - 1;
        //str1 > str2
        else
            Left = pivot + 1;
    }

    return -1;
}

int main()
{
    //freopen ("in.txt", "r", stdin);
    int left_index = -1, right_index = -1;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%s", &one [i]);

    scanf ("%d", &m);
    for (int i = 0; i < m; i++)
        scanf ("%s", &two [i]);

    qsort (one, n, sizeof (char) * 22, (int(*)(const void *a, const void *b))(strcmp));

    int current_count = n, current_index = 0, left_bound = 0;

    while (current_index < m)
    {
        current_count = n, right_index = current_index;
        memset (array, 0, sizeof array);

        //printf ("current_index: %d\n", current_index);

        while (true)
        {
            int curr = find_index (right_index);
            right_index++;
            if (curr != -1)
            {
                array [curr]++;
                current_count -= (array [curr] == 1) ? 1 : 0;
            }

            if (current_count == 0)
                break;

            if (right_index >= m)
            {
                right_index = -1;
                break;
            }
        }

        if (right_index == -1)
            break;

        right_index--;

        //cut

        for (int i = current_index; i < m; i++)
        {
            int current_element = find_index (i);
            if (array [current_element] == 1)
            {
                left_index = i - 1;
                break;
            }
        }

        solution = min (right_index - left_index, solution);
        current_index++;
    }

    printf ("%d\n", solution);

    return 0;
}
/*
5
a
b
c
d
e
1
a

3
admin
moderator
user
8
admin
moderator
hacker
programmer
user
coder
moderator
admin


The Final Command
*/
