
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

struct point
{
    int x, y;

    point() { }
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    point subtract(const point &B) const
    {
        return point (x - B.x, y - B.y);
    }

    point add(const point &B) const
    {
        return point (x + B.x, y + B.y);
    }

    void get()
    {
        scanf ("%d %d", &x, &y);
    }

    void print()
    {
        printf ("%d %d\n", x, y);
    }

    float distance (const point &B) const
    {
        return ((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
    }

    float rooted_distance (const point &B) const
    {
        return sqrt ((*this).distance (B));
    }

    int cross_product(const point &B) const
    {
        int sol = ((x * B.y) - (B.x * y));
        return sol;
    }

    int ccw (const point &B) const
    {
        int cnt = (*this).cross_product (B);

        if (cnt == 0)
            return 0;
        else if (cnt < 0)
            return -1;
        else if (cnt > 0)
            return 1;
    }

    int ccw(const point &B, const point &C) const
    {
#define A (*this)

        int cnt = (A.subtract(C)).ccw(B.subtract(C));

        if (cnt == 0)
            return 0;
        else if (cnt < 0)
            return -1;
        else
            return 1;
#undef A
    }

    bool operator== (const point &B) const
    {
        return x == B.x && y == B.y;
    }
};

int n;
float solution;
point Points [100], reference_point;
vector <point> points;

int comp (const point &A, const point &B)
{
    int cnt = A.ccw(B, reference_point);

    if (cnt == 0)
    {
        float dist_B = reference_point.distance (B);
        float dist_A = reference_point.distance (A);

        return (dist_A < dist_B);
    }

    return (cnt > 0);
}

int main ()
{
    int starting_index, min_y = 10000;

    point D (1, -3), B (1, 1), C (1, -1), G (4, 4);

    //cout<<B.ccw (C, D)<<endl;


    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Points [i].get();

        if (min_y > Points [i].y)
        {
            min_y = Points [i].y;
            starting_index = i;
            reference_point = Points [starting_index];
        }
    }

    for (int i = 0; i < n; i++)
        if (!(reference_point == Points [i]))
            points.push_back (Points [i]);


    printf ("\n\n<---------->\n\n");


    sort (points.begin(), points.end(), comp);

    for (int i = 0; i < n; i++)
        points [i].print();

    cout<<endl<<"result: "<<points [1].ccw (points [3], points [2])<<endl;

    printf ("\n\n<---------->\n\n");


    stack <point> S;

    n--;

    S.push (reference_point);
    S.push (points [0]);
    S.push (points [1]);

    point point1 = points [1], point2 = points [0];

    for (int i = 2; i < n; i++)
    {
        point1 = S.top();
        S.pop();
        point2 = S.top();
        S.push (point1);

        point new_point = points [i];
        cout<<"new_point: "; new_point.print();
        cout<<"point1: "; point1.print();
        cout<<"point2: "; point2.print();
        cout<<"result: "; cout<<new_point.ccw (point2, point1)<<endl;
        system ("pause");

        while (new_point.ccw (point2, point1) < 0)
        {
            cout<<i<<endl;
            system ("pause");
            S.pop();

            point1 = S.top();
            S.pop();
            point2 = S.top();
            S.push (point1);
        }

        S.push (new_point);
    }

    while (!S.empty())
    {
        S.top().print();
        S.pop();
    }



    return 0;
}
/*
6
-1 1
-2 -2
2 1
1 3
4 1
1 -3
*/
