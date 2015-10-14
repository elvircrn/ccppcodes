#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

#define MAXN 1499
#define MAXM 750

int RANDOM_LETTERS [MAXN];

int main ()
{
    freopen ("test_input.txt", "w", stdout);

    srand (time (NULL));

    for (int i = 0; i < MAXN; i++)
    {
        printf ("%c", char ((rand() % 26) + 'a'));
    }
    printf ("\n");
    for (int i = 0; i < MAXM; i++)
    {
        printf ("?");
    } printf ("\n");

    return 0;
}
