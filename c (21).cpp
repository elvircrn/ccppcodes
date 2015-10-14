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

#define MAXV 100100

bool cat [MAXV];
int v, limit, solution;

vector <int> graph [MAXV];

void dfs (int prev_node, int current_node, int cats)
{
	cout << "current_node: " << current_node + 1 << endl;
	
	cats += cat [current_node];

	if (cats > limit)
		return;

	if (!cat [current_node])
		cats = 0;

	for (int next : graph [current_node])
		if (next != prev_node)
			dfs (current_node, next, cats);

	solution = solution + (graph [current_node].size() == 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> v >> limit;

	for (int i = 0; i < v; i++)
		cin >> cat [i];

	for (int i = 0; i < v - 1; i++)
	{
		int x, y;

		cin >> x >> y;
		
		x--;
		y--;

		graph [x].push_back(y);
		graph [y].push_back(x);
	}

	dfs (0, 0, 0);

	cout << solution << endl;

	return 0;
}
/*
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
*/
