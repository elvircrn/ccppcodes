#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAXN 210
#define MAXN 210
#define MAX_LASERS 100

int dirX [4] = { -1, 0, 1, 0 };
int dirY [4] = { 0, 1, 0, -1 };

struct point
{
	int x, y;

	point() { }
	point(int _x, int _y) { x = _x; y = _y; }

	void set(int _x, int _y) { x = _x; y = _y; }

	void print() const { printf ("x: %d y: %d\n", x, y); }
	void print() { printf ("x: %d y: %d\n", x, y); }

	void add(int i) { x += dirX [i]; y += dirY [i]; }

	bool operator== (const point &B) const { return x == B.x && y == B.y; }
};

int get_direction(int current_direction, char mirror)
{
	if (mirror == '/')
	{
		if (current_direction == 0)
			return 1;
		else if (current_direction == 1)
			return 0;
		else if (current_direction == 2)
			return 3;
		else
			return 2;
	}
	else if (mirror == '\\')
	{
		if (current_direction == 0)
			return 3;
		else if (current_direction == 1)
			return 2;
		else if (current_direction == 2)
			return 1;
		else
			return 0;
	}
	else
		return current_direction;
}

void print_field(int n, int m, char **field)
{
	for (int i = 1; i <= n; i++, putchar ('\n'))
		for (int j = 1; j <= m; j++)
			putchar (field [i] [j]); putchar ('\n');
}

bool check (const point &start, int direction, char **field)
{
	bool visited [200] [200] [4];
	memset (visited, false, sizeof visited);
	point current_location = start;
    int current_direction = direction;

	while (!visited [current_location.x] [current_location.y] [current_direction])
	{
		char current_char = field [current_location.x] [current_location.y];
		if (current_char != '.' && current_char != 'S' && current_char != 'E' && current_char != '\\' && current_char != '/')
			return false;

		if (field [current_location.x] [current_location.y] == 'E')
			return true;

		visited [current_location.x] [current_location.y] [current_direction] = true;
		current_location.add(current_direction);
		current_direction = get_direction(current_direction, field [current_location.x] [current_location.y]);
	}
	
	return false;
}

string solve(int n, int m, int direction, char **field)
{
	point start, end;
	vector <point> mirrors;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (field [i] [j] == 'S')
				start.set(i, j);
			else if (field [i] [j] == 'E')
				end.set(i, j);
			else if (field [i] [j] != '.')
				mirrors.emplace_back(i, j);
		}
	}

	if (check(start, direction, field))
	{
		return "nije potrebno vrsiti izmjene";
	}
	
	for (point mirror : mirrors)
	{
		if (field [mirror.x] [mirror.y] == '\\')
			field [mirror.x] [mirror.y] = '/';
		else
			field [mirror.x] [mirror.y] = '\\';
		
		if (check (start, direction, field))
		{
			printf ("%d %d\n", mirror.x, mirror.y);
			return;
		}

		if (field [mirror.x] [mirror.y] == '\\')
			field [mirror.x] [mirror.y] = '/';
		else
			field [mirror.x] [mirror.y] = '\\';
	}

	return "nemoguce";
}

int main()
{
	int n, m, direction;
	char **field;
	
	field = new char* [200];
	for (int i = 0; i < 200; i++)
		field [i] = new char [200];

	scanf ("%d %d %d", &n, &m, &direction); getchar();
	for (int i = 1; i <= n; i++, getchar())
		for (int j = 1; j <= m; j++)
			field [i] [j] = getchar();

	solve (n, m, direction, field);

	print_field(n, m, field);

	return 0;
}


/*
6 6
0
/....E
......
\....\
......
/..../
S.....
*/
