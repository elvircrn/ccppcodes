#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, m, t;
int mat [10010] [10010];

int main()
{
    scanf ("%d %d %d", &n, &m, &t);
    for (int i = 0; i < t; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        mat [a] [b] = -1000000;
    }
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            mat [i] [j]++;
        }
    }

    return 0;
}
