#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int power, pos [100001], RA [100001], len, SA [100001];
char characters[100001];

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
    scanf ("%s", &characters);
    len = strlen(characters);

    for (int i = 0; i < len; i++)
    {
        SA [i] = i;
        pos [i] = characters [i];
    }

    for (power = 1; power < len; power *= 2)
    {
        sort (SA, SA + len, cmp);

        for (int i = 0; i < len - 1; i++)
            RA [i + 1] = cmp (SA [i], SA [i + 1]) + RA [i];

        for (int i = 0; i < len; i++)
            pos [SA [i]] = RA [i];
    }

    return 0;
}







