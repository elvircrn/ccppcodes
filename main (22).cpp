#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <functional>
#include <climits>

using namespace std;

struct point
{
	int x, y;

	point() { }
	point(int _x, int _y) { x = _x; y = _y; }
	point(bool use) { get(); }

	void get()
	{
		cin>>x>>y;
	}

	void print() const
	{
		cout<<"x: "<<x<<" y: "<<y<<endl;
	}

	bool operator< (const point &B) const
	{
		if (y != B.y)
			return y < B.y;
		else
			return x < B.x;
	}
};

int n, d;
vector <point> points;
set    <point, function <bool (const point&, const point&)> > S ([] (const point &A, const point &B) -> bool { return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y); });

int main()
{
	freopen ("8.in", "r", stdin);

	cin>>n>>d;
	for (int i = 0; i < n; i++)
		points.push_back(point(true));


	sort (points.begin(), points.end());

	int where = -1;

	for (int i = 1; i < points.size(); i++)
	{
		if (where == -1 && abs (points [0].y - points [i].y) >= d)
			where = i;

		if (abs (points [0].y - points [i].y) >= d)
			S.insert(points [i]);
	}

	int w = INT_MAX;

	for (int i = 0; i < points.size(); i++)
	{
		//cout<<"current_index: "; points [i].print();
		while (where < points.size() && abs (points [i].y - points [where].y) < d)
		{
			//cout<<"    removed: "<<where<<endl;
			S.erase(points [where]);
			where++;
		}

		//cout<<"S.size(): "<<S.size()<<endl;

		if (!S.empty())
		{
			auto it = S.insert(points [i]).first;

			if (it != S.begin())
			{
				it--;
				w = min (w, abs (it->x - points [i].x));
				//cout<<"    "; it->print();
				it++;
			}
			it++;
			if (it != S.end())
			{
				//cout<<"    "; it->print();
				w = min (w, abs (it->x - points [i].x));
			}
		}
		S.erase(points [i]);
	}

	cout<<w<<endl;

	return 0;
}

































