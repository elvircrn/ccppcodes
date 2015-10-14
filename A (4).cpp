#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int n;
char matrix [1000000];

int main()
{
    scanf ("%d", &n);

    int counter = n / 2;
    int counterD = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 0; j < counter; j++)
            putchar ('*');

        for (int j = 0; j < counterD; j++)
            putchar ('D');

        for (int j = 0; j < counter; j++)
            putchar ('*'); printf ("\n");
        counter--;
        counterD += 2;
    }

    for (int i = 0; i < n; i++)
        putchar ('D');

    printf ("\n");

    counter = 1;
    counterD = n - 2;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 0; j < counter; j++)
            putchar ('*');

        for (int j = 0; j < counterD; j++)
            putchar ('D');

        for (int j = 0; j < counter; j++)
            putchar ('*'); printf ("\n");
        counter++;
        counterD -= 2;
    }

    return 0;
}







