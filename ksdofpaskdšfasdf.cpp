#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1005;

int N;
int cows [MAXN];
int best [MAXN][MAXN][2];

int main ()
{
    memset (best, 63, sizeof (best));

    scanf ("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf ("%d", cows + i);

    cows [++N] = 0;

    sort (cows + 1, cows + N + 1);

    for (int i = 1; i <= N; i++)
        if (cows [i] == 0)
            best [i][1][0] = 0;


    for (int len = 1; len < N; len++)
    {
        int ccount = N - len;

        for (int i = 1; i + len <= N + 1; i++)
        {
            printf ("%d %d\n", i, len);
        }
    }

    printf ("%d\n", best [1][N][0] < best [1][N][1]);

    return 0;
}
