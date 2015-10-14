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

struct element
{
	long long power;

	bool operator< (const element &B) const
	{
		return power % 10 < (B.power % 10);
	}
	
	void get()
	{
		cin >> power;
	}

	void print()
	{
		cout << "power: " << power << endl;
	}
};

int n;
long long solution, k;
element elements [MAXN];
priority_queue <element> Q;

int main()
{
	ios_base :: sync_with_stdio(false);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
	{
		elements [i].get();
		solution += (elements [i].power / 10);
		Q.push(elements [i]);
	}

	element help;
	while (!Q.empty() && k)
	{
		help = Q.top();
		Q.pop();

		if (help.power >= 100)
			continue;

		//help.print();

		//cout << "before: " << help.power;
		solution -= help.power / 10;

		long long c = min (k, 10 - (help.power % 10));
		
		help.power += c;
		k -= c;
		solution += help.power / 10;
		
		//cout << "after: " << help.power << endl; 

		//cout << "used: " << c << " k: " << k << endl;

		if (help.power < 100)
			Q.push(help);
	}

	cout << solution << endl;

	return 0;
}

















































