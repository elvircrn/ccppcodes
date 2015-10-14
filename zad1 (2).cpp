#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, o;

int main()
{
    scanf ("%d %d", &n, &o);
    if (o * n % (n - 1) == 0)
        printf ("%d %d\n", (o * n) / (n - 1) - 1, (o * n) / (n - 1));
    else
        printf ("%d %d\n", (o * n) / (n - 1), (o * n) / (n - 1));

    return 0;
}
