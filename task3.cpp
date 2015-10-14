#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int t, q, number = 1, last = 0;
float sum = 0;

vector <int> array;

int main ()
{
    array.push_back (0);

    int a, b;

    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &q);
        if (q == 1)
        {
            scanf ("%d %d", &a, &b);
            if (number >= a)
                array [array.size() - 1] += b;
            sum += (a * b);
        }
        else if (q == 2)
        {
            scanf ("%d", &a);
            array.push_back (a);
            last = a;
            sum += a;
            number++;
        }
        else
        {
            sum -= array [array.size() - 1];
            array.pop_back();
            number--;
        }

        printf ("LAST: %d\n", array [array.size() - 1]);


        printf ("%.6f\n", sum / number);
    }


    return 0;
}
