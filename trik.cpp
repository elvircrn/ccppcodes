#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int signs [1000], indexes [1000];

struct Card
{
    char sign;
    int index;

    bool letter;

    Card () { }
    Card (char _sign, int _index, bool isLetter) { letter = isLetter; sign = _sign; index = _index; }

    bool operator < (const Card &B) const
    {
        if (sign != B.sign)
            return signs [sign] < signs [B.sign];
        else
            return indexes [index] < indexes [B.index];
    }
};

void Initialize()
{
    signs ['L'] = 1;
    signs ['K'] = 2;
    signs ['D'] = 3;

    for (int i = 2; i <= 10; i++)
        indexes [i] = i - 1;

    indexes ['J'] = 10;
    indexes ['Q'] = 11;
    indexes ['K'] = 12;
    indexes ['A'] = 13;
}

int n, m, number;
char c, input [10];
bool gate;

Card cards [1000100];

int main ()
{
    Initialize();

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        gate = false;

        scanf ("%s", &input);

        c = input [0];

        if (!isdigit (input [1]))
            gate = true;

        if (strlen (input) > 2)
            number = (input [1] - '0') * 10 + (input [2] - '0');
        else
            number = input [1] - '0';

        printf ("%c %d\n", c, number);

        cards [i] = Card (c, number, gate);
    }

    sort (cards, cards + n);

    if (!cards [m - 1].letter)
        printf ("%c%d", cards [m - 1].sign, cards [m - 1].index);
    else
        printf ("%c%c", cards [m - 1].sign, char (cards [m - 1].index));

    return 0;
}

/*
2
2 2 3 3
1 1 2 2
*/







