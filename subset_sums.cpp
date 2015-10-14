#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int ll;

int N, array [300], dist1 [300], dist2 [300];

vector <ll> prva_polovina;
vector <ll> druga_polovina;

void pr (ll n, ll ind, bool used[])
{

    if (ind == n)
    {
        ll S = 0;

        for (ll i = 0; i < n; i++)
            if (used [i])
                S += array [i];

        prva_polovina.push_back (S);
    }
    else
    {
        used [ind] = true;
        pr (n, ind + 1, used);
        used [ind] = false;
        pr (n, ind + 1, used);
    }

    return;

}

void dr (ll n, ll ind, bool used[])
{

    if (ind == N)
    {
        ll S = 0;

        for (ll i = N / 2; i < N; i++)
            if (used [i])
                S += array [i];

        druga_polovina.push_back (S);
    }

    else
    {
        used [ind] = true;
        dr (n, ind + 1, used);
        used [ind] = false;
        dr (n, ind + 1, used);
    }

    return;

}

ll L, R, SOLUTION;

int main ()
{
    bool d [40];

    scanf ("%lld %lld %lld", &N, &L, &R);
    for (ll i = 0; i < N; i++)
        scanf ("%lld", &array [i]);

    memset (d, false, sizeof d);
    pr (N / 2, 0, d);
    memset (d, false, sizeof d);
    dr (N, N / 2, d);

    sort (prva_polovina.begin(), prva_polovina.end());
    sort (druga_polovina.begin(), druga_polovina.end());

    ll PRVA_ITERACIJA, DRUGA_ITERACIJA;

    for (ll i = 0; i < prva_polovina.size(); i++)
    {

        ll A = prva_polovina [i];
        bool found = false;

        ll pivot, leftb = 0, rightb = druga_polovina.size();

        while (leftb <= rightb)
        {
            pivot = (leftb + rightb) / 2;
            if (A + druga_polovina [pivot - 1] < L && A + druga_polovina [pivot] >= L && A + druga_polovina [pivot] <= R)
            {
                found = true;
                break;
            }
            else if (A + druga_polovina [pivot] > R)
            {
                rightb = pivot - 1;
            }
            else
            {
                leftb = pivot + 1;
            }
        }

        if (A + druga_polovina [0] >= L && A + druga_polovina [0] <= R)
        {
            found = true;
            pivot = 0;
        }

        if (found == false)
            continue;

        found = false;

        PRVA_ITERACIJA = pivot;
        leftb = 0, rightb = druga_polovina.size();

        while (leftb <= rightb)
        {
            pivot = (leftb + rightb) / 2;
            if (A + druga_polovina [pivot] >= L && A + druga_polovina [pivot] <= R && A + druga_polovina [pivot + 1] > R)
            {
                break;
            }
            else if (A + druga_polovina [pivot] < L || A + druga_polovina [pivot] >= L && A + druga_polovina [pivot] <= R)
            {
                leftb = pivot + 1;
            }
            else
            {
                rightb = pivot - 1;
            }
        }

        if (A + druga_polovina [druga_polovina.size() - 1] >= L && A + druga_polovina [druga_polovina.size() - 1] <= R)
        {
            found = true;
            pivot = druga_polovina.size() - 1;
        }

        if (found == false)
            continue;

        DRUGA_ITERACIJA = pivot;
        SOLUTION += DRUGA_ITERACIJA - PRVA_ITERACIJA + 1;

    }

    printf ("%d\n", SOLUTION);

    return 0;

}
/*
3 -1 2
1
-2
3
a wild chess game appears

♜♞♝♛♚♝♞♜
♟♟♟♟♟♟♟♟

♙♙♙♙♙♙♙♙
♖♘♗♕♔♗♘♖

ť
*/
