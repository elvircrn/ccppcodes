#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;


int n, m, counter = 0;
int q[1100], w[1100];
bool visited[1100];
deque <int> known;

int main()
{
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &w [i]);
    for (int i = 1; i <= m; i++)
        scanf ("%d", &q [i]);


    int solution = 0;

    for (int i = 1; i <= m; i++)
    {

        if (visited [q [i]])
        {
            int index = -1;
            for (int j = 0; j < known.size(); j++)
            {
                if (known [j] == q [i])
                {
                    index = j;
                    break;
                }
                solution += w [known [j]];
            }

            for (int j = index; j > 0; j--)
                swap (known [j], known [j - 1]);
        }
        else
        {
            visited [q [i]] = true;
            for (int i = 0; i < known.size(); i++)
                solution += w [known[i]];
            known.push_front(q [i]);
        }
    }

    printf ("%d\n", solution);

    return 0;
}








































