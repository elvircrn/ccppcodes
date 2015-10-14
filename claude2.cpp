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

ll n;
bool found(false);

vector <ll> solution;

void find(ll progress)
{
    if (progress < 0)
        return;

    if (solution.size() == 4 && progress == 0)
    {
        sort (solution.begin(), solution.end());
        reverse (solution.begin(), solution.end());
        for (int i = 0; i < solution.size() - 1; i++)
            cout<<solution [i]<<' '; cout<<solution [solution.size() - 1]<<endl;
        //sol = solution;
        exit (0);
    }
    else if (solution.size() == 4)
        return;

    for (ll i = 0; i >= -100LL; i--)
    {
        ll a = sqrt (progress) + i;
        solution.push_back (a);

        find (progress - a * a);

        if (found)
            return;
        solution.pop_back();
    }
}

int main()
{

    vector <ll> sol;
    solution.clear();

    cin>>n;
    find (n);

    return 0;
}
//4123123131
//9223372036854765807
