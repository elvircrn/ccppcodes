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
    Vector2 (float _x, float _y) { x = _x; y = _y; }

    Vector2 operator + (const Vector2 &B) const
    {
        return Vector2 (x + B.x, y + B.y);
    }

    Vector2 operator - (const Vector2 &B) const
    {
        return Vector2 (x - B.x, y - B.y);
    }

    void print()
    {
        printf ("%f %f\n", x, y);
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
        mat [0] [1] = sin (rotation);
        mat [1] [0] = -sin (rotation);
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

    void Print()
    {
        for (int i = 0; i < height; i++, printf ("\n"))
            for (int j = 0; j < width; j++)
                printf ("%f ", mat [i] [j]);
    }

    Vector2 operator * (const Vector2 &B) const
    {
        for (int i = 0; i < height; i++, printf ("\n"))
            for (int j = 0; j < width; j++)
                printf ("%f ", mat [i] [j]);

        return Vector2 (B.x * mat [0] [0] + B.y * mat [1] [0], B.x * mat [0] [1] + B.y * mat [1] [1]);
    }
};

struct Field
{
    int n;
    char mat [20] [20];

    Field () { }
    Field (int _n) { n = _n; }

    void Get ()
    {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++)
            scanf ("%s", &mat [i]);
    }

    void print ()
    {
        for (int i = 0; i < n; i++)
            printf ("%s\n", mat [i]);

    }
    char getValue (const Vector2 &location)
    {
        return mat [int (location.x)] [int (location.y)];
    }

    Vector2 getCenter ()
    {
        return Vector2 (float (n / 2) + float (n % 2), float (n / 2) + float (n % 2));
    }

    void rotate (float degrees)
    {
        Field kopija = (*this);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //kopija.mat [i] [j] = (getValue ( Matrix (degrees) * (Vector2 (i, j) - getCenter())    ));
                kopija.mat [i] [j] = (getValue ( Vector2 (i, j) + Matrix (degrees) * (getCenter() - Vector2 (i, j))    ));
            }
        }
    }
};

int main ()
{
    /*
    int n;

    scanf ("%d", &n);

    Field input = Field (n);
    input.Get();

    input.rotate (90);

    input.print();
*/

    Vector2 one (1.0, 1.0);
    Matrix new_matrix = Matrix (1, 1);
/*

    int cnt = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            new_matrix.mat [i] [j] = cnt;
            cnt++;
        }

    (new_matrix * one).print();

*/
    (Matrix (90) * one).print();

    return 0;
}
