#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 1e5 + 10

int n, t;
string a, b;

int f (const string &x, const string &y)
{
	int ret = 0;
	for (int i = 0; i < x.length(); i++)
		ret += (x [i] != y [i]);
	return ret;
}

vector <int> diff;
vector <int> same;

string s;

char solution [100050];
bool different [100050];

char get_c (char x, char y)
{
	for (char i = 'a'; i <= 'z'; i++)
		if (x != i && y != i)
			return i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> t >> a >> b;

	for (int i = 0; i < n; i++)
	{
		if (a [i] != b [i])
			diff.push_back(i);
		else
			same.push_back(i);
	}

	if (diff.size() > t)
	{
		cout << -1 << endl;
		return 0;
	}

	solution [n] = '\0';

	int t1 = t;

	for (int i = 0; i < diff.size(); i++)
	{
		if (!t1)
			break;
		else
		{
			different [diff [i]] = true;
			t1--;
		}
	}

	if (t1)
	{
		for (int i = 0; i < same.size(); i++)
		{
			if (!t1)
				break;
			else
			{
				different [same [i]] = true;
				t1--;
			}
		}
	}

	for (int i = 0; i < diff.size(); i++)
		if (different [diff [i]])
			solution [diff [i]] = get_c(a [diff [i]], b [diff [i]]);

	for (int i = 0; i < same.size(); i++)
		if (different [same [i]])
			solution [same [i]] = get_c(a [same [i]], a [same [i]]);
		else
			solution [same [i]] = a [same [i]];

	s = string (solution);

	if (f (a, s) == t && f (b, s) == t)
		cout << s << endl;
	else
		cout << -1 << endl;
	return 0;
}
