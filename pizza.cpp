#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int n, one, two, three, solution;
string input;

int main ()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>input;
        if (input == "1/4")
            one++;
        else if (input == "1/2")
            two++;
        else
            three++;
    }

    one = (one - (three + (two % 2) * 2)) ? (one - (three + (two % 2) * 2)) : 0;

    if (two > 1)
        two /= 2;

    solution = (three + two + (one / 4) + 1);

    printf ("%d\n", solution);

    return 0;
}
