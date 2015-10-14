#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

#define INF 1<<27

int n, m, v [3000];
vector <int> graph [1010];
bool visited [2010];

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &v [i]);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);

        graph [a].push_back (b);
        graph [b].push_back (a);
    }

    int solution = 0;

    int t = n - 1;

    while (t--)
    {
        int damage = INF, _damage = 0, maximum = 0, min_index;

        for (int i = 1; i <= n; i++)
        {
            if (visited [i])
                continue;

            int cnt = 0;

            _damage = 0;

            for (int j = 0; j < graph [i].size(); j++)
                if (!visited [graph [i] [j]])
                {
                    cnt += v [i];
                    _damage += v [graph [i] [j]];
                }

            //printf ("   i: %d cnt: %d damage: %d\n", i, cnt, _damage);

            if (cnt > maximum)
            {
                damage = _damage;
                maximum = cnt;
                min_index = i;
            }
            else if (cnt == maximum && _damage < damage)
            {
                min_index = i;
                damage = _damage;
            }
        }

        solution += damage;
        visited [min_index] = true;
    }

    int solution1 = 0;

    memset (visited, false, sizeof visited);
    t = n - 1;

    while (t--)
    {
        int damage = INF, _damage = 0, minimum = INF, _cnt = 0, min_index;

        for (int i = 1; i <= n; i++)
        {
            if (visited [i])
                continue;

            int cnt = 0;

            _damage = 0;

            for (int j = 0; j < graph [i].size(); j++)
                if (!visited [graph [i] [j]])
                {
                    cnt += v [i];
                    _damage += v [graph [i] [j]];
                }

            if (_damage < damage)
            {
                damage = _damage;
                _cnt = cnt;
                min_index = i;
            }
            else if (_damage == damage && cnt > _cnt)
            {
                _cnt = cnt;
                min_index = i;
            }
        }

        solution1 += damage;
        visited [min_index] = true;
    }


    printf ("%d\n", min (solution1, solution));

    return 0;
}




















