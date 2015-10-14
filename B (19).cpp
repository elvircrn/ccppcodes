#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define MAXN 100100

int n, a [MAXN], up_to [MAXN];

int main()
{
	ios_base :: sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a [i];

	for (int i = n - 2; i > -1; i--)
		up_to [i] = max (up_to [i + 1], a [i + 1]);

	cout << max (0, up_to [0] - a [0] + 1);

	for (int i = 1; i < n; i++)
		cout << ' ' << max (0, up_to [i] - a [i] + 1);

	cout << endl;

	return 0;
}

