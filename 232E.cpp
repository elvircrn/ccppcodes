#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int n, k, p;

int main()
{
    scanf ("%d %d %d", &n, &p, &k);

    int start = p - k;
    if (start < 1)
        start = 1;

    if (start != 1)
    {
        printf ("<< ");
    }

    int end = p + k;

    if (end > n)
        end = n;

    for (int i = start; i < p; i++)
        printf ("%d ", i);

    printf ("(%d) ", p);

    for (int i = p + 1; i <= end; i++)
        printf ("%d ", i);

    if (n != end)
    {
        printf (">>");
    }

    return 0;
}
