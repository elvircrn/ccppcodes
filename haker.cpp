#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long int ll;

ll counter [10000], max_val, max_ind;

ll fakt (ll number)
{
    ll ret = 1;
    for (ll i = max_val + 1; i <= number; i++)
        ret *= i;

    return ret;
}

long long BrojKombinacija (string s)
{
    for (int i = 0; i < 1000; i++)
        counter [i] = 0;
    for (int i = 0; i < s.length(); i++)
    {
        counter [s [i]]++;
        if (max_val < counter [s [i]])
        {
            max_val = counter [s [i]];
            max_ind = s [i];
        }
    }

    ll ret = fakt (s.length());

    for (int i = 0; i < 1000; i++)
        if (counter [i] > 1 && i != max_ind)
            ret /= fakt (counter [i]);

    return ret;

    /* Ovdje napisite svoje rjesenje */
}

