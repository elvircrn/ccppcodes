#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define EPS 10e-10


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

       double d = one.A * two.B - two.A * one.B;

       if (cmp (d, 0))
           return vector2<T> (3000.0f, 3000.0f);

       double y =   (one.A * two.C - two.A * one.C) / d;
       double x = (-(one.B * two.C - two.B * one.C)) / d;

       return vector2<T> (x, y);
#undef one
   }
};

vector <vector2<double> > points;
vector <vector2<double> > convex_hull;


int start_index, n;

bool cmp (const vector2 <double> &A, const vector2 <double> &B)
{
    return A.cross_product(B) > 0.0f;
}

vector <vector2 <double> > real_points;

int main()
{
    scanf ("%d", &n);

    min_index = 30000.0f;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        scanf ("%f %f", &x, &y);
        points.push_back (vector2<double (x, y));


        if (min > y)
        {
            min_index = i;
            min = y;
        }

    }


    for (int i = 0; i < points.size(); i++)
    {
        if (i != min_index)
        {
            real_points.push_back (points [i]);
        }
    }

    sort (real_points.begin(), real_points.end(), cmp);

    return 0;
}





















