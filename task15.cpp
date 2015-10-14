#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

#define EPS 10e-17


bool cmp (const double &x, const double &y)
{
    return fabs (x - y) < EPS;
}

template <class T>
class vector2
{
public:
    T x, y;

    vector2() { }
    vector2(T _x, T _y) { x = _x; y = _y; }
    vector2(T x1, T y1, T x2, T y2) { x = x2 - x1; y = y2 - y1; }

    T cross_product (const vector2 &B) const
    {
        return x * B.y - y * B.x;
    }

    T dot_product (const vector2 &B) const
    {
        return x * B.x + y * B.y;
    }

    void print() const
    {
        cout<<x<<' '<<y<<endl;
    }

    T dist (const vector2<T> &B) const
    {
        return sqrt ((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
    }

    bool operator< (const vector2<T> &B) const
    {
        if (cmp (x, B.x))
            return y < B.y;
        else
            return x < B.x;
    }
};

template <class T>
class line
{
public:
    T A, B, C;

    line() { }
    line(T _A, T _B, T _C) { A = _A; B = _B; C = _C; }
    line(const vector2<T> &one, const vector2<T> &two)
    {
        A = two.y - one.y;
        B = one.x - two.x;
        C = -one.y * (one.x - two.x) + one.x * (one.y - two.y);
    }

    vector2<T> intersection(const line &two) const
    {
#define one (*this)

        T d = one.A * two.B - two.A * one.B;

        if (cmp (d, 0.0000f))
            return vector2<T> (-10000000.0f, -1120000.123123f);

        T y =   (one.A * two.C - two.A * one.C)  / d;
        T x = (-(one.B * two.C - two.B * one.C)) / d;

        return vector2<T> (x, y);
#undef one
    }
};

vector <line<double> > lines;
map <vector2 <double>, bool> visited;

class PlaneDivision
{
public:

    int howManyFiniteParts(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2)
    {
        int n = x1.size();

        if (n <= 2)
            return 0;

        for (int i = 0; i < n; i++)
            lines.push_back (line<double> (vector2<double> (x1 [i], y1 [i]), vector2<double> (x2 [i], y2 [i])));

        int V = 0, E = 0;

        for (int i = 0; i < n; i++)
        {
            int v = 0;

            for (int j = 0; j < n; j++)
            {
                if (i == j || (cmp (lines [i].A, lines [j].A) && cmp (lines [i].B, lines [j].B) && (lines [i].C, lines [j].C)) || cmp (intersection.y, -1120000.123123f))
                    continue;

                vector2<double> intersection = lines [i].intersection (lines [j]);

                if (visited [intersection] == false)
                {
                    //intersection.print();
                    visited [intersection] = true;
                    v++;
                }
            }

            E += (v - 1);
        }

        return (1 + E - V > 0) ? (1 + E - V) : 0;
    }
};





int main()
{
    map <vector2 <double>, bool> TEST;

    const int SIZE = 7;

    int X1 [SIZE] = {-1, -1, -1, -1, 1, 3, -3};
    int Y1 [SIZE] = {-1, -2, 0, 0, 10000, 1, -5};
    int X2 [SIZE] = {1, 1, 1, -1, 1, -3, 3};
    int Y2 [SIZE] = {1, 0, 2, -10000, 0, -2, 4};

    vector <int> x1 (X1, X1 + SIZE);
    vector <int> y1 (Y1, Y1 + SIZE);
    vector <int> x2 (X2, X2 + SIZE);
    vector <int> y2 (Y2, Y2 + SIZE);

    PlaneDivision PD;

    printf ("%d\n", PD.howManyFiniteParts(x1, y1, x2, y2));

    return 0;
}














