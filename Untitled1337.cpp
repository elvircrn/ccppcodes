#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#define PI 3.14159265
#define MALO 10e-5

float to_radians (float degrees)
{
   return (degrees * PI / 180);
}

float myabs (float a)
{
   if (a < 0)
       return a * (-1);
   else
       return a;
}

bool equal (float a, float b)
{
   return (myabs (a - b) < MALO);
}

struct point
{
   float x, y;

   point() { }
   point(float _x, float _y)
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
       scanf ("%f %f", &x, &y);
   }

   void print()
   {
       printf ("%f %f\n", x, y);
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
       return equal (x, B.x) && equal (y, B.y);
   }

   void rotate (float angle)
   {
       float radians = to_radians (angle);
       float X = x * cos (radians) + y * -sin (radians);
       float Y = x * (sin (radians)) + y * cos (radians);

       (*this).x = X;
       (*this).y = Y;
   }
};

int main ()
{
    point A (2, 0), B (-3, 1), V (-5, 1), D (1, 1);

    V.rotate (-60);

    V.print();

    return 0;
}
