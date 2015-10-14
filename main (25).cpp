#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;

#define MAXV 100100
#define MOD  1000000000LL

struct point
{
	long long x, y;

	point() { }
	point(long long _x, long long _y) { x = _x; y = _y; }

	void print()
	{
		printf ("x: %lld y: %lld", x, y);
	}

	bool operator< (const point &B) const
	{
		return (x != B.x) ? (x < B.x) : (y < B.y);
	}

	point shiftY()
	{
		return point(x, y + 1);
	}

	point shiftX()
	{
		return point(x + 1, y);
	}
};


long long n, cardinality [MAXV];
vector <point> cities;

bool compX(const point &A, const point &B)
{
	return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y);
}

bool compY(const point &A, const point &B)
{
	return (A.y != B.y) ? (A.y < B.y) : (A.x < B.x);
}

vector <point> final_set;
map    <point, long long> mark;
set <point> edges;
vector <long long> graph [MAXV];

long long sub_size [MAXV], total_sum;

int calculate_depth(int current_node, int prev_node)
{
    //printf ("prev_node: %d current_node: %d\n", prev_node, current_node);
	if (current_node != prev_node)
		final_set.emplace_back(prev_node, current_node);

	int ret = 0;

	for (long long next : graph [current_node])
	{
		if (prev_node != next)
		{
			ret += calculate_depth (next, current_node) % MOD;
			ret %= MOD;
		}
	}

	return sub_size [current_node] = ((ret % MOD) + (cardinality [current_node] % MOD)) % MOD;
}

void reset()
{
	mark.clear();
	total_sum = 0;
	edges.clear();
	memset (cardinality, 0, sizeof cardinality);
	final_set.clear();
	for (int i = 0; i < MAXV; i++)
		graph [i].clear();
	memset(sub_size, 0, sizeof sub_size);
}

long long calculate_horizontal()
{
    //cout<<"horizontal started: "<<endl;
	reset();
	sort (cities.begin(), cities.end(), compY);

	long long current_group = 1, solution = 0LL;

	for (long long i = 0; i < cities.size(); i++)
	{
		long long currentY = cities [i].y;
		for (; i < cities.size(); i++)
		{
			if (currentY != cities [i].y)
            {
                i--;
                current_group++;
				break;
            }
			else
			{
				if (i && cities [i - 1].y == cities [i].y && abs (cities [i - 1].x - cities [i].x) > 1)
					current_group++;
				mark [cities [i]] = current_group;
				cardinality [current_group]++;
			}
		}
	}

	for (long long i = 0; i < cities.size() - 1; i++)
	{
		point p = cities [i];

		long long u = mark [p];
		long long v = mark [p.shiftY()];

		if (v == 0)
			continue;

		if (edges.find(point(min (u, v), max (u, v))) == edges.end())
		{
			graph [u].push_back(v);
			graph [v].push_back(u);
			edges.insert(point(min (u, v), max (u, v)));
		}
	}

	total_sum = calculate_depth(1, 1);

	for (point e : final_set)
	{
		solution += ((total_sum - sub_size [e.y] % MOD) * (sub_size [e.y] % MOD)) % MOD;
		solution %= MOD;
	}

	return solution % MOD;
}

long long calculate_vertical()
{
    //cout<<"vertical started: "<<endl;
	reset();
	sort (cities.begin(), cities.end(), compX);

	long long current_group = 1, solution = 0LL;

	for (long long i = 0; i < cities.size(); i++)
	{
		long long currentX = cities [i].x;
		for (; i < cities.size(); i++)
		{
			if (currentX != cities [i].x)
            {
                i--;
                current_group++;
				break;
            }
			else
			{
				if (i && cities [i - 1].x == cities [i].x && abs (cities [i - 1].y - cities [i].y) > 1)
					current_group++;
				mark [cities [i]] = current_group;
				cardinality [current_group]++;
			}
		}
	}

	for (long long i = 0; i < cities.size() - 1; i++)
	{
		point p = cities [i];

		long long u = mark [p];
		long long v = mark [p.shiftX()];

		if (v == 0)
			continue;

		if (edges.find(point(min (u, v), max (u, v))) == edges.end())
		{
			graph [u].push_back(v);
			graph [v].push_back(u);
			edges.insert(point(min (u, v), max (u, v)));
		}
	}

	total_sum = calculate_depth(1, 1);

	for (point e : final_set)
		solution += ((total_sum - sub_size [e.y]) * sub_size [e.y]) % MOD;

	return solution;
}

int main()
{
	//freopen ("in.txt", "r", stdin);

	scanf ("%lld", &n);
	for (long long i = 0; i < n; i++)
	{
		long long x, y;
		scanf ("%lld %lld", &x, &y);
		cities.emplace_back(x, y);
	}

	printf ("%lld\n", (calculate_horizontal() + calculate_vertical()) % MOD);

	return 0;
}

/*
19
3 3
3 5
4 3
4 4
4 5
4 8
4 9
5 5
5 6
5 8
6 6
6 7
6 8
7 4
7 5
7 6
7 7
7 8
7 9
 */
