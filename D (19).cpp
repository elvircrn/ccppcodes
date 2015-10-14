#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

map <ll, bool> not_prime;

int main()
{
	ll n;
	cin >> n;
	for (ll i = 2; i * i <= n; i++)
	{
		if (not_prime [i] == true)
			continue;
		for (int j = i + i; j <= n; j += i)
		{
			not_prime [j] = true;
		}
	}



	return 0;
}
