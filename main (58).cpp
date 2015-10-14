#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <cctype>

using namespace std;

int conv(char c)
{
	return c - 'a';
}

char s [100100], query [4];
int q, counter [30] [30] [30] [30];

void solve()
{
	memset (counter, 0, sizeof counter);
	scanf ("%d %s", &q, &s);

	printf ("%d\n", q);

	int len = strlen (s);

	for (int i = 0; i < len - 4; i++)
		counter [conv(s [i])] [conv(s [i + 1])] [conv(s [i + 2])] [conv(s [i + 3])]++;

	for (int i = 0; i < q; i++)
		printf ("%d\n", counter [conv (query [0])] [conv (query [1])] [conv (query [2])] [conv (query [3])]);
}

int main()
{
	freopen ("input19.txt", "r", stdin);
	//freopen ("GENERIC.txt", "w", stdout);
	solve();

	return 0;
}
