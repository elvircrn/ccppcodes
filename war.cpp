#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <deque>

using namespace std;

#define max_people 1000

int q, c, enemies [max_people], friends [max_people], enemies [max_people], size [max_people];

int find_root_friend (int x)
{
    if (x == friends [x])
        return x;
    else
        friends [x] = find_root_friend (friends [x]);
}

bool areEnemies (int x, int y)
{

}

void setFriends (int x, int y)
{
    if (areEnemies (x, y))
    {
        printf ("-1\n");
        return;
    }

    int fX = find_root_friend (x), fY = find_root_friend (y);
    if (size [fX] < size [fY])
    {
        size [fY] += size [fX];
        friends [fX] = fY;
    }
    else
    {
        size [fX] += size [fY];
        friends [fY] = fX;
    }

    return true;
}

bool setEnemies (int x, int y)
{

}

bool areFriends (int x, int y)
{
    if (find_root_friend (x) == find_root_friend (y))
        return true;
    else
        return false;
}

int main ()
{

    int x, y;

    for (int i = 1; i <= max_people - 5; i++)
    {
        size [i] = 1;
        friends [i] = i;
    }

    scanf ("%d", &q);
    while (q--)
    {
        scanf ("%d %d %d", &c, &x, &y);

        if (c == 1)
        {
            setFriends (x, y);
        }
        else if (c == 2)
        {
            setEnemies (x, y);
        }
        else if (c == 3)
        {
            printf ("%d\n", areFriends (x, y));
        }
        else if (c == 4)
        {
            printf ("%d\n", areEnemies (x, y));
        }
        else
            break;

    }

    return 0;
}
