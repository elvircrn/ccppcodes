#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

typedef pair<int, int> Point;
set<Point> object, visited;
int perimeter;

bool isolated(int x, int y)
{
    for (int i=-1; i<=1; i++)
        for (int j=-1; j<=1; j++)
            if (object.count(Point(x+i,y+j))) return false;
    return true;
}

void visit(int x, int y)
{
    if (object.count(Point(x,y)))
    {
        perimeter++;
        return;
    }
    if (visited.count(Point(x,y))) return;
    visited.insert(Point(x,y));
    if (isolated(x,y)) return;
    visit(x-1,y);
    visit(x+1,y);
    visit(x,y-1);
    visit(x,y+1);
}

int main(void)
{
    int N, x, y;

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> x >> y;
        object.insert(Point(x,y));
    }

    Point start = *object.begin();
    x = start.first-1;
    y = start.second;

    visit(x, y);

    cout << perimeter << "\n";
    return 0;
}
