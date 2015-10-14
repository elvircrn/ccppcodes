O#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int n, t;
	scanf ("%d %d", &n, &t);
	if (n == 1 && t == 10)
	{
		printf ("-1\n");
		return 0;
	}
	if (t == 10)
		printf ("1");
	else
		printf ("%d", t);
	for (int i = 0; i < n - 1; i++)
		printf ("0");
	printf ("\n");
	return 0;
}
