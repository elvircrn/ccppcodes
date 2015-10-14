#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define INF 1<<27

int n, m, largea, largeb, smalla, smallb, matrix [1100] [1100], field [1100] [1100], min_value [1100] [1100];
int get(int x1, int y1, int x2, int y2)
{
    return matrix [x2] [y2] + matrix [x1 - 1] [y1 - 1] - matrix [x2] [y1 - 1] - matrix [x1 - 1] [y2];
}

int main()
{
    scanf ("%d %d %d %d %d %d", &n, &m, &largea, &largeb, &smalla, &smallb);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf ("%d", &matrix [i] [j]);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            min_value [i] [j] = INF;

    return 0;
}
