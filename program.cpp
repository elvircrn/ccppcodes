#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

struct TIME
{
    int hours, minutes, seconds;

    TIME () { }
    TIME (int _hours, int _minutes, int _seconds) { hours = _hours; seconds = _seconds, minutes = _minutes; }
    TIME (int S)
    {
        int k = S;
        hours = S / 3600;
        S -= ((S / 3600) * 3600);
        minutes = (S / 60);
        S -= ((S / 60) * 60);
        seconds = S;
    }

    int ToHours (int _seconds)
    {
        hours = _seconds / 3600;
        _seconds -= ((_seconds / 3600) * 3600);
        minutes = (_seconds / 60);
        _seconds -= ((_seconds / 60) * 60);
        seconds = _seconds;
    }

    int ToSeconds() const
    {
        return seconds + minutes * 60 + hours * 3600;
    }

    TIME operator- (const TIME &B) const
    {
        return TIME (ToSeconds() - B.ToSeconds() - 1);
    }

    void print (FILE *out)
    {
        fprintf (out, "%d:%d:%d,000", hours, minutes, seconds);
    }
};

char in [1000];

TIME ONE (0, 0, 1);

int main ()
{
    FILE *f = fopen ("novi.srt", "r");
    FILE *o = fopen ("novi2.srt", "w");

    TIME dif = TIME (1, 8, 24);

    int cnt = 10;

    char asd [2], c;

    while (fgets (in, 100, f))
    {
        TIME A, B, C;
        int h, m, s, dummy, h1, m1, s1;

        fprintf (o, "%s", in);
        fscanf (f, "%d:%d:%d,%d --> %d:%d:%d,%d\n", &h, &m, &s, &dummy, &h1, &m1, &s1, &dummy);
        A = TIME (h, m, s);

        B = A - dif;

        B.print (o); fprintf (o, " --> ");

        A = TIME (h1, m1, s1);

        B = A - dif;

        B.print (o); fprintf (o, "\n");

        fgets (in, 100, f);
        fprintf (o, "%s", in);

        fgets (in, 100, f);

        if (int (in [0]) >= 'A' && int (in [0]) <= 'Z' || int (in [0]) >= 'a' && int (in [0]) <= 'z')
        {
            fprintf (o, "%s", in);
            fgets (in, 100, f);
        }

        fprintf (o, "\n");
    }

    return 0;
}
