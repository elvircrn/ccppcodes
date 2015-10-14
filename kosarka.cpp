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

struct TIME
{
    int minutes, seconds;

    TIME () { }
    TIME (int _minutes, int _seconds) { minutes = _minutes; seconds = _seconds; }

    void get()
    {
        scanf ("%d:%d", &minutes, &seconds);
    }

    void print()
    {
        printf ("%d:%d\n", minutes, seconds);
    }
};

int getSeconds (TIME &Time)
{
    return Time.seconds + (Time.minutes * 60);
}

TIME getTime (int seconds)
{
    return TIME (seconds / 60, (seconds - (seconds / 60)));
}

int t, q;

int main ()
{
    scanf ("%d", &t);

    TIME input = TIME();

    while (t--)
    {
        scanf ("%d", &q);
        input.get();
        input.print();
    }

    return 0;
}
