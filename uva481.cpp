#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int array [1001000], S_id [1001000], S [1001000], top_index, current_index, start_index, solution, parent [2010000];
vector <int> sol;

int main()
{
    int ii(0);
    while (scanf ("%d", &array [ii]) == 1/* && array [ii]*/)
        ii++;

    for (int i = 0; i < ii; i++)
    {
        current_index = lower_bound(S, S + top_index, array [i]) - S;
/*
        printf ("current_index: %d\n", current_index);
*/
        S [current_index] = array [i];
        S_id [current_index] = i;

        if (current_index > 0)
            parent [i] = S_id [current_index - 1];
        else
            parent [i] = -1;

        if (current_index == top_index)
        {
            solution = top_index + 1;
            top_index++;
            start_index = i;
        }
/*
        for (int j = 0; j <= top_index; j++)
            printf ("%d ", S_id [j]); printf ("\n");
*/
    }
/*
    printf ("\n\nstart_index: %d\n\n", start_index);

    printf ("\n\nparent: %d\n\n", parent [start_index]);
*/
    printf ("%d\n-\n", solution);

    while (start_index >= 0)
    {
        sol.push_back (array [start_index]);
        start_index = parent [start_index];
    }

    for (int i = sol.size() - 1; i > -1; i--)
        printf ("%d\n", sol [i]);

    return 0;
}
/*
1
4
7
10
3
11
0



1
2
3
4
5
4
6
0


-7
10
9
2
3
8
8
1
0
*/


