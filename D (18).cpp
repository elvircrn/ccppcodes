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

struct sign
{
	int x, y;
	char name;

	sign() { }
	sign(int _x, int _y, char _name) { x = _x; y = _y; name = _name; }

	int index() const
	{
		return name - 'A';
	}

	void get()
	{
		cin >> x >> y;
	}

	bool operator< (const sign &B) const
	{
		return index() < B.index();
	}
};

char matrix [500] [500];
int area, n;
sign signs [3];

void print()
{
	cout << n << endl;
	for (int i = 0; i < n; i++, putchar('\n'))
		for (int j = 0; j < n; j++)
			putchar (matrix [i] [j]);
}

int main()
{
	int maximum = 0;
	ios_base :: sync_with_stdio (false);
	for (int i = 0; i < 3; i++)
	{
		signs [i].get();
		signs [i].name = char ('A' + i);
		area += signs [i].x * signs [i].y;
		maximum = max (maximum, max (signs [i].x, signs [i].y));
	}
	
	n = sqrt (area);

	sort (signs, signs + 3);

	int found = 0;

	if (n != maximum || n * n != area)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < 3; i++)
	{
		if (signs [i].x > n || signs [i].y > n)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	while (next_permutation (signs, signs + 3))
	{
		cout << signs [0].name << endl;
		if (signs [0].x == n)
			swap (signs [0].x, signs [0].y);
		
		if (signs [0].y == n)
		{
			cout << "here" << endl;
			int bottom = n - signs [0].x;

			for (int i = 1; i < 3; i++)
				if (signs [i].y == bottom)
					swap (signs [i].x, signs [i].y);
			
			if (n == signs [1].y + signs [2].y &&
				bottom == signs [1].x && bottom == signs [2].y)
			{
				found = 2;
				break;
			}
		}
	}

	if (found == 0)
	{
		for (int i = 0; i < 3; i++)
			if (signs [0].x == n)
				swap (signs [0].x, signs [0].y);

		int counter = 0, cX = 0;
		for (int i = 0; i < 3; i++)
		{
			counter += (signs [i].y == n);
			cX += signs [i].x;
		}

		if (counter == 3 && cX == n)
		{
			for (int i = 0; i < signs [0].x; i++)
				for (int j = 0; j < signs [0].y; j++)
					matrix [i] [j] = signs [0].name;

			for (int i = signs [0].x; i < signs [0].x + signs [1].x; i++)
				for (int j = 0; j < signs [1].y; j++)
					matrix [i] [j] = signs [1].name;
			
			
			for (int i = signs [0].x + signs [1].x; i < signs [0].x + signs [1].x + signs [2].x; i++)
				for (int j = 0; j < signs [2].y; j++)
					matrix [i] [j] = signs [2].name;

			print();

			return 0;
		}
	}
	else if (found == 2)
	{
		for (int i = 0; i < signs [0].x; i++)
			for (int j = 0; j < signs [0].y; j++)
				matrix [i] [j] = signs [0].name;
		for (int i = signs [0].x; i < n; i++)
			for (int j = 0; j < signs [1].y; j++)
				matrix [i] [j] = signs [1].name;
		for (int i = signs [0].x; i < n; i++)
			for (int j = signs [1].y; j < n; j++)
				matrix [i] [j] = signs [2].name;

		print();

		return 0;
	}

	cout << -1 << endl;
	
	return 0;
}
/*
9 23 14 8 15 14
//
 */
