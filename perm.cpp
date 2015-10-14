#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool check(int i)
{
    char str [10];

    sprintf (str, "%d", i);


    if ((str [0] == '2' || str [0] == '3' || str [0] == '5' || str [0] == '7') && (str [2] == '2' || str [2] == '3' || str [2] == '5' || str [2] == '7'))
    {
        if (str [0] != str [1] && str [0] != str [2] && str [1] != str [2])
            return true;
    }

    return false;
}

int main()
{
    int counter = 0;
    for (int i = 100; i <= 999; i++)
        counter += check(i);

    printf ("%d\n", counter);

    return 0;
}
