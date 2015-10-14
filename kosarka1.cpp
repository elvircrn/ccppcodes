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
        if (minutes < 10)
            printf ("0");
        printf ("%d:", minutes);
        if (seconds < 10)
            printf ("0");
        printf ("%d\n", seconds);
    }

    int toSeconds()
    {
        return minutes * 60 + seconds;
    }

    int operator- (TIME &B)
    {
        return toSeconds() - B.toSeconds();
    }
};

int getSeconds (TIME &Time)
{
    return Time.seconds + (Time.minutes * 60);
}

TIME getTime (int seconds)
{
    return TIME (seconds / 60, (seconds - (60 * (seconds / 60))));
}

int t, q, ii, scoreA, array [50000], scoreB, leadA, leadB;

TIME times [2000], last;

int main ()
{
    last = TIME (47, 59);

    scanf ("%d", &t);

    TIME input = TIME();

    while (t--)
    {
        scanf ("%d", &q);
        input.get();

        if (q == 1)
            array [input.toSeconds()]++;
        else
            array [input.toSeconds()]--;
    }

    int cnt = 0;

    for (int i = 0; i <= last.toSeconds(); i++)
    {
        cnt += array [i];

        if (cnt > 0) scoreA++;
        else if (cnt < 0) scoreB++;
    }

    getTime (scoreA).print();
    getTime (scoreB).print();

    return 0;
}
/*
3
1 01:10
2 21:10
2 31:30
*/
