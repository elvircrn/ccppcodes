#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int total, n, m, a, b, solution, outdegree [1010], maximum, max_index;
bool matrix[1010] [1010];

vector <pair <int, int > > edges;

int main()
{
    int viska(0);
    scanf ("%d %d", &n, &m);
    total = n;
    for (int i = 0; i < m; i++)
    {
        scanf ("%d %d", &a, &b);
        outdegree [a]++;

        if (outdegree [a] > maximum)
        {
            maximum = outdegree [a];
            max_index = a;
        }

        matrix [a] [b] = true;

        if (matrix [a] [b])
            edges.push_back (make_pair (a, b));
        else
            viska++;
    }

    int relevant = 0, fali = 0;

    for (int i = 0; i < m; i++)
    {
        if (edges [i].first == edges [i].second)
            relevant++;
        else if (edges [i].first == max_index || edges [i].second == max_index)
            relevant++;
        else if (edges [i].first != max_index && edges [i].second != max_index)
            viska++;
    }

    int total = n + 2 * (n - 1);

    fali = total - relevant;

    printf ("%d\n", fali + viska);

    return 0;
}
/*
4 11
1 1
2 2
3 3
4 4
1 3
3 1
2 3
3 2
4 3
3 4
1 2
*/



