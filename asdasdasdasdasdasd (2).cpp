#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

int get_minutes (int h, int m)
{
    return h * 60 + m;
}

pair<int, int> get_hours (int minutes)
{
    int hours = minutes / 60;
    int asd = minutes % 60;

    return make_pair (hours, asd);
}

int main()
{
    int aa, bb, cc, dd;

    scanf ("%d:%d", &aa, &bb);
    scanf ("%d:%d", &cc, &dd);

    int one = get_minutes(aa, bb);
    int two = get_minutes(cc, dd);

    if (one >= two)
    {
         //printf ("%2d:%2d\n", get_hours(one - two).first, get_hours (one - two).second);
        int oone = get_hours(one - two).first;
        int otwo = get_hours (one - two).second;

        if (oone > 9)
            printf ("%d:", oone);
        else
            printf ("0%d:", oone);

        if (otwo < 10)
            printf ("0");
        printf ("%d", otwo);
    }
    else
    {
        int oone = get_hours(1440 + one - two).first;
        int otwo = get_hours (1440 + one - two).second;

        if (oone > 9)
            printf ("%d:", oone);
        else
            printf ("0%d:", oone);

        if (otwo < 10)
            printf ("0");
        printf ("%d", otwo);
    }

    return 0;
}

/*
00:00
00:01
*/

