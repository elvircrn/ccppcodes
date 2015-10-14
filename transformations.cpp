#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

struct Vector2
{
    float x, y;

    Vector2 () { }
    Vector2 (int _x, int _y) { x = _x; y = _y; }

    Vector2 operator + (const Vector2 &B) const
    {
        return Vector2 (x + B.x, y + B.y);
    }

    Vector2 operator - (const Vector2 &B) const
    {
        return Vector2 (x - B.x, y - B.y);
    }
};

struct Matrix
{
    float mat [10] [10];
    int height, width;

    Matrix () { }
    Matrix (int _height, int _width) { height = _height; width = _width; }
    Matrix (float degrees)
    {
        float rotation = degrees * (M_PI / 180);

        height = 2;
        width = 2;
        mat [0] [0] = cos (rotation);
        mat [0] [1] = -sin (rotation);
        mat [1] [0] = sin (rotation);
        mat [1] [1] = cos (rotation);
    }

    Matrix operator* (Matrix &B)
    {
        Matrix help = Matrix (height, B.width);
        for (int i = 0; i < height; i++)
            for (int j = 0; j < B.width; j++)
                for (int k = 0; k < width; k++)
                    help.mat [i] [j] += (mat [i] [k] * B.mat [k] [j]);

        return help;
    }
};

int main ()
{


    return 0;
}
