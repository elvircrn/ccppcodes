#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

#define getX(x) (x) / n
#define getY(x) n - ((x) % n + 1)
#define get(X,Y) (X) * n + (Y)

FILE *out;

unsigned long long int solution;

const int dirX [4] = { -1, 0, 1, 0 };
const int dirY [4] = { 0, 1, 0, -1 };

int n, k;
int zero_count [11] [11], placed, rows_filled, columns_filled, row_count [11], column_count [11];
bool found, bits [11] [11], has_r [11], has_c [11];

int surround(int x, int y)
{
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dirX [i];
        int Y = y + dirY [i];

        if (X >= 0 && Y >= 0 && X < n && Y < n && !bits [X] [Y])
            counter++;
    }

    return counter;
}

void init(int _n, int _k)
{
    solution = 0LL;
    found = false;

    memset (row_count, 0, sizeof row_count);
    memset (column_count, 0, sizeof column_count);
    memset (bits, false, sizeof bits);
    memset (has_r, false, sizeof has_r);
    memset (has_c, false, sizeof has_c);

    placed = 0;
    rows_filled = 0;
    columns_filled = 0;

    n = _n;
    k = _k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            zero_count [i] [j] = surround(i, j);
}

void print()
{
    printf ("n: %d k: %d\n", n, k);
    for (int i = 0; i < n; i++, printf ("\n"))
        for (int j = 0; j < n; j++)
            printf ("%d ", bits [i] [j]);
}

int XX, YY;

void solve(int index)
{
    print();
    if (index == n * n && rows_filled == n && columns_filled == n)
    {
        found = true;
        print();
        return;
    }
    else if (index == n * n || (n * n - 1) - index < (n * k - placed))
        return;
    else if (column_count [getY(index)] == k || row_count [getX(index)] == k)
    {
        solve(index + 1);
        if (found)
            return;
    }
    else
    {
        if (getX(index) != (n - (getY(index) + 1)) && getX(index) != getY(index))
        {
            bool can = true;

            for (int i = 0; i < 4; i++)
            {
                XX = getX(index) + dirX [i];
                YY = getY(index) + dirY [i];

                if (XX >= 0 && YY >= 0 && XX < n && YY < n && !bits [XX] [YY] && zero_count [XX] [YY] == 1)
                    can = false;
            }

            if (can)
            {
                for (int i = 0; i < 4; i++)
                {
                    XX = getX(index) + dirX [i];
                    YY = getY(index) + dirY [i];

                    if (XX >= 0 && YY >= 0 && XX < n && YY < n && !bits [XX] [YY])
                        zero_count [XX] [YY]--;
                }


                bits [getX(index)] [getY(index)] = true;
                placed++;
                solution += (1<<index);
                column_count [getY(index)]++;
                row_count [getX(index)]++;

                if (row_count [getX(index)] == k)
                    rows_filled++;
                if (column_count [getY(index)] == k)
                    columns_filled++;

                if (row_count [getX(index)] == k && getX(index) != n - 1)
                {
                    solve (get(getX(index) + 1, 0));
                }
                else
                    solve (index + 1);

                if (found)
                    return;
            }
        }

        if (bits [getX(index)] [getY(index)] && zero_count [getX(index)] [getY(index)])
        {
            for (int i = 0; i < 4; i++)
            {
                XX = getX(index) + dirX [i];
                YY = getY(index) + dirY [i];

                if (XX >= 0 && YY >= 0 && XX < n && YY < n && !bits [XX] [YY])
                    zero_count [XX] [YY]++;
            }

            bits [getX(index)] [getY(index)] = false;
            placed--;
            solution -= (1<<index);

            row_count [getX(index)]--;
            column_count [getY(index)]--;

            if (row_count [getX(index)] == k - 1)
                rows_filled--;
            if (column_count [getY(index)] == k - 1)
                columns_filled--;

        }
            solve(index + 1);

        if (found)
            return;
    }

    return;
}

char buffer [5];

int main()
{
    init (10, 5);
    solve(0);
    print();
    return 0;
}

/*
0 0 1 1 1 1 1 1 0
0 0 1 1 1 1 1 1 0
1 1 0 0 1 1 1 0 1
1 1 0 0 1 1 0 1 1
1 1 1 1 0 0 0 1 1
1 1 1 1 0 0 1 0 1
1 1 1 0 0 1 0 1 1
1 1 0 1 1 0 1 0 1
1 0 1 1 1 1 1 1 0


0001
1000
0100
0010
*/




























