#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using  namespace std;

typedef long long int ll;

ll current_sol, sum, n, k, array [10100000];

vector <ll> sums;
vector <ll> indexes;
vector <ll> new_indexes;

int check(ll limit)
{
    ll counter(0), brackets(0);
    for (int i = 0; i < n; i++)
    {
        counter += array [i];

        if (counter > limit)
        {
            brackets++;
            counter = array [i];
        }
    }

    if (brackets < k - 1)
        return -1;

    if (counter > limit)
        return false;

    return (brackets == k - 1);
}

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%lld %lld", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lld", &array [i]);
        sum += array [i];
    }

    ll left(0), right(sum), pivot;

    while (left <= right)
    {
        pivot = (left + right) / 2;

        #ifdef DEBUG

        printf ("left: %lld pivot: %lld right: %lld\n", left, pivot, right);

        #endif

        ll chk = check (pivot);

        if (chk > 0)
        {
            current_sol = pivot;
            right = pivot - 1;
        }
        else if (chk == -1)
            right = pivot - 1;
        else
            left = pivot + 1;

        #ifdef DEBUG
        printf ("check: %d\n", chk);
        #endif
    }


    ll counter(0);

    #ifdef DEBUG
    printf ("\n\nsolution: %d\n\n", current_sol);
    #endif

    for (int i = 0; i < n; i++)
    {
        counter += array [i];
        if (counter > current_sol)
        {
            indexes.push_back (i);
            cout<<"/ ";
            sums.push_back (counter - array [i]);
            counter = array [i];
        }

        cout<<array [i]<<" ";
    } cout<<endl;

    if (counter <= current_sol)
        sums.push_back (counter);

    for (int i = 0; i < indexes.size(); i++)
        cout<<indexes [i]<<endl; cout<<endl;

    for (int i = 0; i < sums.size(); i++)
        printf ("%lld\n", sums [i]);

    int current_index = 0;
    counter = 0;

    cout<<endl<<endl<<endl;

    for (int i = 0; i < indexes.size(); i++)
    {

    }

    cout<<"new_index: "<<sums[0]<<endl;

    return 0;
}



// 1 2 3 / 1 2 3 / 1 2 3











