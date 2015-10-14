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
#include <climits>

using namespace std;

typedef long long ll;

struct element
{
	ll money, friendship;

	element() { }
	element(ll _money, ll _friendship) { money = _money; friendship = _friendship; }

	void get()
	{
		cin>>money>>friendship;
	}

	bool operator< (const element &B) const
	{
		return money < B.money;
	}

	void print()
	{
		cout<<"money: "<<money<<" friendship: "<<friendship<<endl;
	}
};

ll n, d, numbers [100100], prefix [100100], solution;
element elements [100100];

ll get_range(int l, int r)
{
	if (!l)
		return prefix [r];
	else
		return prefix [r] - prefix [l - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>d;
	for (int i = 0; i < n; i++)
		elements [i].get();

	sort (elements, elements + n);

	prefix [0] = elements [0].friendship;

	for (int i = 1; i < n; i++)
		prefix [i] = prefix [i - 1] + elements [i].friendship;

	//for (int i = 0; i < n; i++)
	//	elements [i].print();
	
	for (int i = 0; i < n; i++)
	{
		int left = i, right = n;
		while (left < right)
		{
			int pivot = (left + right + 1) / 2;

			if (abs (elements [pivot].money - elements [i].money < d))
				left = pivot;
			else
				right = pivot - 1;
		}
		if (left == n)
			left = n - 1;
		solution = max (solution, get_range(i, left));
		
		//cout<<"i: "<<i<<" left: "<<left<<" range: "<<get_range(i, left )<<endl;
	}

	cout<<solution<<endl;
	return 0;
}

