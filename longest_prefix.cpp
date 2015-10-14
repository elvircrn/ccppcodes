#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int power, pos [40001], SA [40001], RA [40001], len1, len2, len;
char s1 [40001], s2 [40000];

bool cmp (int A, int B)
{
    if (pos [A] != pos [B])
        return pos [A] < pos [B];

    if (A + power >= len || B + power >= len)
        return A > B;
    else
        return pos [A + power] < pos [B + power];
}

int main()
{
    scanf ("%s", &s1);
    len1 = strlen (s1);

    s1 [len1] = '.';

    scanf ("%s", s1 + (len1 + 1));

    int len2 = strlen (s1) - (len1 + 1);

    len = len1 + len2 + 1;

    for (int i = 0; i < len; i++)
    {
        SA [i] = i;
        pos [i] = s1 [i];
    }

    printf ("len: %d\n", len);

    for (power = 1; power < len; power++)
    {
        sort (SA, SA + len, cmp);

        for (int i = 0; i < len - 1; i++)
            RA [i + 1] = RA [i] + cmp (SA [i], SA [i + 1]);

        for (int i = 0; i < len; i++)
            pos [SA [i]] = RA [i];
    }

    for (int i = 0; i < len; i++)
        printf ("%d %s\n", SA [i], s1 + SA [i]);



    return 0;
}

class Date
{
public:
    int month, int day;

    Date() { }
    Date(int _day, int _month) { day = _day; month = _month; }

    string to_string()
    {
        return to_string(day) + " " + to_string (month);
    }
};










