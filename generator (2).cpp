#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define n 4
#define m 10

char matrix [n] [m];

int percentage = 30;

int get_number(int limit)
{
    return rand() % limit;
}

int neg()
{
    int num = get_number (1000);

    if (num % 2 == 0)
        return 1;
    else
        return -1;
}

int main()
{
    freopen ("in.txt", "w", stdout);
    srand (time (0));

    printf ("%d %d %d\n", n, -1, 3);

    for (int i = 0; i < n; i++)
        printf ("%d\n", get_number (5) * neg());

    return 0;
}






