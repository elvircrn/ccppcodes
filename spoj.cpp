#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Time
{
public:
    int hours, minutes;

    Time () { }
    Time (int _hours, int _minutes) { hours = _hours; minutes = _minutes; }

    int getMinutes()
    {
        return (minutes + (hours * 60));
    }

    void get()
    {
        scanf ("%d:%d", &hours, &minutes);
    }

    void convert (int number)
    {
        hours = number / 60;
        minutes = (number - (number / 60));
    }

    void print()
    {
        printf ("%d:%d\n", hours, minutes);
    }

    int operator - (Time &B)
    {
        return getMinutes() - B.getMinutes();
    }
}

int main ()
{
    Time input;
    int n, ;
    scanf ("%d", &n);
    while (n--)
    {
        input.get();
    }

    return 0;
}
