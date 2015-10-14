#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define weight   second
#define strength first

struct turtle
{
    int weight, strength;

    turtle() { }
    turtle(int _weight, int _strength) { weight = _weight; strength = _strength; }

    bool operator< (const turtle &B) const
    {
        return strength < B.strength;
    }

    bool get()
    {
        if (scanf ("%d %d", &weight, &strength) != 2)
            return false;

        strength -= weight;
    }
};

turtle turtles [5700];
int a, b, n, LIS [5700], sum_to [5700], solution;

int main()
{
    //freopen ("in.txt", "r", stdin);

    while (turtles [n++].get())
    {
        if (turtles [n - 1].weight > turtles [n - 1].strength)
            n--;
    }

    sort (turtles, turtles + n);

    sum_to [0] = turtles [0].weight;
    LIS [0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sum_to [j] < turtles [i].strength && LIS [i] < LIS [j] + 1)
            {
                sum_to [i] = sum_to [j] + turtles [i].weight;
                LIS [i] = LIS [j] + 1;
                solution = max (solution, LIS [j] + 1);
            }
        }
    }

    printf ("%d\n", solution);

    return 0;
}








