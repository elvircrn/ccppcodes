#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

long long int n, numbers [100100], solution, counter;

int main()
{
	cin>>n;
	solution = 1;
	counter = 1;
	for (int i = 0; i < n; i++)
		cin>>numbers [i];

	for (int i = 1; i < n; i++)
	{
		if (numbers [i] >= numbers [i - 1])
			counter++;
		else
			counter = 1;

		solution = max (solution, counter);
	}

	cout<<solution<<endl;
	return 0;
}
