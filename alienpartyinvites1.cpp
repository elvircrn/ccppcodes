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
    int Left = 0, Right = n - 1, pivot;

    printf ("two: %s\n", one [0]);
    system ("pause");

    while (Left <= Right)
    {
        pivot = (Left + Right / 2);
        printf ("left: %d right: %d pivot: %d one [pivot]: %s\n", Left, Right, pivot, one [pivot]);
        system ("pause");
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
    int left_index = -1, right_index = -1;
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>one [i];
    /*scanf ("%d", &m);
    for (int i = 0; i < m; i++)
        scanf ("%s", &two [i]);*/


    qsort (one, n, 10000, (int(*)(const void *a, const void *b))(strcmp));

    for (int i = 0; i < n; i++)
        cout<<one [i]<<endl;

    /*
5
e
b
c
d
a
1
a
    */

    /*int current_count = n, current_index;

    while (right_index < n)
    {
        printf ("left_index: %d right_index: %d\n", left_index, right_index);
        system ("pause");
        while (current_count)
        {
            right_index++;
            current_index = find_index (right_index);
            if (current_index == -1)
                continue;
            if (!array [current_index])
                current_count--;
        }

        solution = min (solution, right_index - left_index + 1);

        while (true)
        {
            left_index++;
            current_index = find_index (left_index);
            if (current_index == -1)
                continue;
            array [current_index]--;
            if (!array [current_index])
            {
                current_count++;
                break;
            }
        }
    }

    printf ("%d\n", solution);*/

    return 0;
}
/*
1
str1 > str2
-1
str1 < str2

The Final Command

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
*/
