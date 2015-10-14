#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Coin
{
public:
    char name;
    int value, index;

    Coin () { }
    Coin (int _name, int _value, int _index) {name = _name; value = _value; index = _index; }

    bool operator < (const Coin & x) const
    {
        return value < x.value;
    }
};

int n, m, B, dp [20000], choice [20000];
char A;

vector <Coin> Coins;

int main ()
{
    int big = 1000000;

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf ("%s %d", &A, &B);
        Coins.push_back (Coin (A, B, i));
    }

    sort (Coins.begin(), Coins.end());

    for (int i = 1; i <= m; i++) dp [i] = big;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - Coins [j].value < 0) break;

            int help = dp [i - Coins [j].value] + 1;

            if (help <= dp [i])
            {
                choice [i] = j;
                dp [i] = help;
            }
        }
    }

    int index = m;

    if (dp [m] == big)
    {
        putchar ('Q');
        return 0;
    }

    while (index)
    {
        putchar (Coins [choice [index]].name);
        index = index - Coins [choice [index]].value;
    }

    return 0;
}
/*
3 6
J 2
K 4
B 5
*/
