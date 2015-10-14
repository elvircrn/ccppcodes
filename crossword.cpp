#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

vector <pair<int, int> > points;
int n, m;
char matrix[100] [100];

int main()
{
    freopen("crosswords.in", "r", stdin);
    freopen("crosswords.out", "w", stdout);

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            matrix[i] [j] = '#';

    scanf ("%d %d", &n, &m); getchar();
    for (int i = 1; i <= n; i++, getchar())
        for (int j = 1; j <= m; j++)
            matrix[i] [j] = getchar();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (matrix [i] [j] == '.')
            {
                //horizontal
                if (matrix[i] [j - 1] == '#' && matrix[i] [j + 1] == '.' && matrix[i] [j + 2] == '.' ||
                    matrix[i - 1] [j] == '#' && matrix[i + 1] [j] == '.' && matrix[i + 2] [j] == '.')
                    points.push_back(make_pair(i, j));
            }
        }
    }

    printf("%d\n", (int)points.size());

    for (int i = 0; i < points.size(); i++)
        printf ("%d %d\n", points[i].first, points[i].second);

    return 0;
}
