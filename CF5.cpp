#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int n, m, q, w;

map <int, int> matrix [4000001];

void set_value(int x, int y, int value)
{
    while (x <= n)
    {
        int cpy = y;
        while (cpy <= m)
        {
            cout<<"x: "<<x<<" y: "<<cpy<<endl;
            matrix [x] [cpy] += value;
            cpy += (cpy & -cpy);
        }
        x += (x & -x);
    }

    cout<<endl<<endl;
}

int get_sum(int x, int y)
{
    if (y == 0 || x == 0)
        return 0;
    int sum = 0;
    while (x > 0)
    {
        int cpy = y;
        while (cpy > 0)
        {
            cout<<"x: "<<x<<" y: "<<cpy<<endl;
            sum += matrix [x] [cpy];
            cpy -= (cpy & (-cpy));
            cout<<"x: "<<x<<" y: "<<cpy<<endl;
        }
        x -= (x & (-x));
    }
    return sum;
}

int get_square (int x1, int y1, int x2, int y2)
{
    return get_sum (x2, y2) - (get_sum (x1, y2 - 1) + get_sum (x2, y1 - 1) + get_sum (x1 - 1, y1 - 1));
}

int set_square (int x1, int y1, int x2, int y2, int value)
{
    set_value (x2, y2, value);

    if (y1 - 1 > 0)
        set_value (x2, y1 - 1, -value);
    if (x1 - 1 > 0)
        set_value (x1 - 1, y2, -value);

    if (x1 - 1 > 0 && y1 - 1 > 0)
        set_value (x1 - 1, y1 - 1, value);
}

int main()
{
    freopen ("in.txt", "r", stdin);
    int x1, y1, x2, y2, value;
    scanf ("%d %d %d", &n, &m, &w);
    /*while (w--)
    {
        scanf ("%d", &q);
        if (q == 0)
        {
            scanf ("%d %d %d %d %d", &x1, &y1, &x2, &y2, &value);
            set_square (x1, y1, x2, y2, value);
        }
        else
        {
            scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf ("%d\n", get_square (x1, y1, x2, y2));
        }
    }*/

    set_value(2, 2, 2);
    printf ("%d\n", get_sum(2, 2));

    return 0;
}






