#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

string input;
int cost, n, p, miss_match, len, left_most = 100100, right_most;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>p>>input;

    p--;

    for (int i = 0; i < input.length() / 2; i++)
    {
        miss_match += (input[i] != input [(n - 1) - i]);

        if (input[i] != input [(n - 1) - i])
        {
            left_most = min (left_most, i);
            right_most = max (right_most, i);

            int lower = min (input[i], input[(n - 1) - i]) - 'a';
            int upper = max (input[i], input[(n - 1) - i]) - 'a';

            cost += min (upper - lower, lower + 25 - upper + 1);
        }
    }

    if (cost == 0 || input.length() == 1)
    {
        printf ("0\n");
        return 0;
    }
    int l = left_most, r = right_most;

    int e = 1231231123;

    if (p > n / 2)
    {
        if (l <= n / 2 && r <= n / 2 && n / 2  <= p)
            e = abs (p - l);
    }

    if (p >= n / 2)
        p -= n / 2;


    if (l == r)
        printf ("%d\n", min (e, abs(p - l)) + cost);
    else if (l == p || r == p)
        printf ("%d\n", min (e, abs(l - r)) + cost);
    else if (p < l)
        printf ("%d\n", cost + min (e, abs(p - r)));
    else if (r < p)
        printf ("%d\n", cost + min (e, abs(p - l)));
    else
        printf ("%d\n", min (e + cost, min (cost + abs (p - l) + abs (l - r), cost + abs(p - r) + abs (r - l))));

    return 0;
}

/*
8 3
aeabcaez

*/









