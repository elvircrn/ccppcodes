#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <windows.h>

using namespace std;

int get_int(int m)
{
    return rand() % 8 + 1;
}

int main()
{
    freopen ("in.txt", "w", stdout);

    srand (time (0));

    printf ("10\n");
    printf ("8 9\n");
    for (int i = 1; i <= 10; i++)
        printf ("%d\n", get_int (i));
    printf ("0\n");

    system ("start uva607a.exe");

    return 0;
}
