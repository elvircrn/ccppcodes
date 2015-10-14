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

int a, b;

int main()
{
	cin >> a >> b;

	cout << min (a, b) << ' ' << max (a - min (a, b), b - min (a, b)) / 2 << endl;

	return 0;
}
