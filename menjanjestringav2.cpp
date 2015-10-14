#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define SHIFT 205000

int n, q, k, LEFT, Right, rLEFT, rRight;
char word [800010], rotated [800010];
bool ROTATED = false;

int main ()
{
    scanf ("%d %d", &n, &q);
    scanf ("%s", word + SHIFT);

    int len = strlen (word + SHIFT);

    LEFT = SHIFT;
    Right = SHIFT + len;
    rLEFT = SHIFT;
    rRight = SHIFT + len;

    int ind = 0;

    for (int i = SHIFT; i < SHIFT + len; i++)
        rotated [SHIFT + (i - SHIFT)] = word [(SHIFT + len) - i + SHIFT - 1];

    for (int K = 0; K < q; K++)
    {
        scanf ("%d", &k);
        int i;
        char x;
        if (k == 1)
        {
            scanf ("%d %c", &i, &x); i--;
            if (!ROTATED)
            {
                word [LEFT + i] = x;
                rotated [rRight - (i + 1)] = x;
            }
            else
            {
                word [Right - (i + 1)] = x;
                rotated [i + rLEFT] = x;
            }
        }
        else if (k == 2)
            ROTATED = !ROTATED;
        else
        {
            cin>>x;
            if (!ROTATED)
            {
                word [Right] = x;
                rotated [rLEFT - 1] = x;
                Right++;
                rLEFT--;
            }
            else
            {
                word [LEFT - 1] = x;
                rotated [rRight] = x;
                rRight++;
                LEFT--;
            }
        }
    }

    if (!ROTATED)
        for (int i = LEFT;  i < Right; i++)
            putchar (word [i]);
    else
        for (int i = rLEFT; i < rRight; i++)
            putchar (rotated [i]);

    return 0;
}

/*
5 4
abcde
1 2 n
3 f
2
1 5 c

2 10
ab
3 c
3 d
2
3 c
3 g
2
1 1 d
1 3 d
2
1 2 w

dwbacd

2 17
ab
3 c
3 d
3 c
2
1 1 w
3 d
3 c
2
3 c
2
3 g
2
1 1 d
2
1 3 z
2
1 2 w
*/
