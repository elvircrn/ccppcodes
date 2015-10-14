#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int ll;

ll find(ll n)
{
    ll a = (ll)sqrt (n);
    ll b = (ll)sqrt (n - (ll)sqrt (n) * (ll)sqrt (n));
    ll c = (ll)(sqrt (n - (a * a + b * b)));
    ll d = (ll)(sqrt (n - (a * a + b * b + c * c)));

    return a * a + b * b + c * c + d * d;
}

ll find2(ll n)
{
    ll a = (ll)sqrt (n) - 1;
    ll b = (ll)sqrt (n - a * a);
    ll c = (ll)(sqrt (n - (a * a + b * b)));
    ll d = (ll)(sqrt (n - (a * a + b * b + c * c)));

    if (a * a + b * b + c * c + d * d != n)
    {
        ll a = (ll)sqrt (n) - 1;
        ll b = (ll)sqrt (n - a * a) - 1;
        ll c = (ll)(sqrt (n - (a * a + b * b)));
        ll d = (ll)(sqrt (n - (a * a + b * b + c * c)));
    }

    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;

    return a * a + b * b + c * c + d * d;
}

int main()
{
    ll n;

    //scanf ("%lld", &n);
    ll a = (ll)sqrt (n);
    ll b = (ll)sqrt (n - (ll)sqrt (n) * (ll)sqrt (n));
    ll c = (ll)(sqrt (n - (a * a + b * b)));
    ll d = (ll)(sqrt (n - (a * a + b * b + c * c)));


    cout<<4123123131<<' '<<find (4123123131)<<endl;

    scanf ("%d", &n);

    /*if (find (n) != n)
    {
        find2(n);
    }*/

    for (int i = 1; i <= 100; i++)
    {
        if (find (i) != i)
        {
            cout<<find (i)<<endl;
        }
    }

    return 0;
}
//4123123131
