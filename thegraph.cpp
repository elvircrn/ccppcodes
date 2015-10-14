#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int v, e, nSource, nSink;
bool source [50010], sink [50010];

int main ()
{
    int A, B;
    memset (source, true, sizeof source);
    memset (sink, true, sizeof sink);
    scanf ("%d %d", &v, &e);
    for (int i = 0; i < e; i++)
    {
        scanf ("%d %d", &A, &B);
        source [A] = false;
        sink [B] = false;
    }

    for (int i = 1; i <= v; i++)
    {
        if (source [i])
        {
            nSource++;
        }
        if (sink [i])
        {
            nSink++;
        }
    }

    printf ("%d\n", max (nSource, nSink));

    return 0;
}
/*
7 7
1 2
3 2
2 4
4 5
5 6
6 7
7 5
*/
