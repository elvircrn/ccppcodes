#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

namespace Math {

    class Matrix {

        public:

        int Height, Width;
        vector <vector <int> > matrix;

        Matrix () {}
        Matrix (int height, int width) {
            Height = height;
            Width = width;
            matrix = vector <vector <int> > (Height + 2, vector <int> (Width + 2));
        }

        static bool ONE (Matrix *mat) {

            if (mat->Height != mat->Width)
                return false;
            for (int i = 0; i < mat->Width; i++)
                mat->matrix [i] [i] = 1;

            return true;
        }



        void Add (int x, int y, int value) {
            this->matrix [x] [y] = value;

        }

        Matrix operator * (const Matrix &y) const {

            Matrix x = (*this);
            Matrix help;

            for (int i = 0; i < x.Height; i++)
                for (int j = 0; j < y.Width; j++)
                    for (int k = 0; k < x.Width; k++)
                        help.matrix [i] [j] += (x.matrix [i] [k] * y.matrix [k] [j]);

            return help;
        }

        void operator *= (const Matrix &y) {

            Matrix x = (*this);

            for (int i = 0; i < x.Height; i++)
                for (int j = 0; j < y.Width; j++)
                    for (int k = 0; k < x.Width; k++)
                        (*this).matrix [i] [j] += (x.matrix [i] [k] * y.matrix [k] [j]);

            return;
        }

    };

    template <class T> void fast_pow (T base, unsigned long long int exponent, T one, T *r) {

        if (exponent % 2 == 1) r = base;
        else r = one;

        while (exponent >>= 1) {
            base *= base;
            if (exponent % 2 == 1) r *= base;
        }

        return;

    }

    int fast_pow (int base, int exponent, int module) {
        if (exponent == 0) return 1;
        if (exponent == 1) return (base % module);
        if (exponent % 2 == 0) {int t = fast_pow (base, exponent / 2, module) % module; return (t * t) % module;}
        else return (fast_pow (base, exponent - 1, module) % module * (base % module)) % module;
    }

}//82

namespace PhysicsEngine {

    class Stuff {

        public:

        static float fast_pow (float base, int exponent) {
            if (exponent == 0) return 1.0;
            if (exponent == 1) return base;
            if (exponent % 2 == 0) {float t = fast_pow (base, exponent / 2); return t * t;}
            else return fast_pow (base, exponent - 1) * base;
        }

    };

    class Vector2 {

        public: float x, y;

        public: Vector2 () {x = y = 0;}
        public: Vector2 (float _x, float _y) {x = _x; y = _y;}

        public: void Debug () { printf ("%.4lf %.4lf\n", x, y); }

        public: float Magnitude () {
            return float (sqrt ((*this).x * (*this).x + (*this).y * (*this).y));
        }

        public: float MagnitudeSquared () {
            return x * x + y * y;
        }

        public: Vector2 Invert () {
            (*this).x *= (-1);
            (*this).y *= (-1);
            return (*this);
        }

        public: static Vector2 Invert (Vector2 &A) {
            return A.Invert();
        }

        public: void Normalize () {
            float M = (*this).Magnitude();
            (*this) *= float (float (1) / M);
        }

        public: static Vector2 Normalize (Vector2 &A) {
            return A *= float
            (float (1) /
            A.Magnitude());
        }

        //Scalar product.
        public: float operator * (const Vector2 &B) const {
            Vector2 A = (*this);
            return A.x * B.x + A.y + B.y;
        }

        public: Vector2 operator *= (const float val) {
            (*this).x *= val;
            (*this).y *= val;
            return (*this);
        }

        public: Vector2 operator * (const float val) const {
            Vector2 A = (*this);
            return Vector2 (A.x * val, A.y *val);
        }

        public: Vector2 operator + (const Vector2 &B) const {
            Vector2 A = (*this);
            return Vector2 (A.x + B.x, A.y + B.y);
        }

        public: Vector2 operator + (const float val) const {
            Vector2 A = (*this);
            return Vector2 (A.x + val, A.y + val);
        }

        public: Vector2 operator += (const float val) {
            Vector2* A = this;
            (*A).x += val;
            (*A).y += val;
            return *A;
        }

        public: Vector2 operator - (const Vector2 &B) const {
            Vector2 A = (*this);
            return Vector2 (A.x - B.x, A.y - B.y);
        }

        public: Vector2 operator - (const float val) const {
            Vector2 A = (*this);
            return Vector2 (A.x - val, A.y - val);
        }

        public: Vector2 operator -= (const float val) {
            Vector2* A = this;
            (*A).x -= val;
            (*A).y -= val;
            return *A;
        }

        public: void addScaledVector (Vector2 &B, float scale) {
            (*this).x += B.x * scale;
            (*this).y += B.y * scale;
        }

    };

    class Vector3 : Vector2 {

        //Scalar product
        //A x B = |A| * |B| * cos (angle) = A.x * B.x + A.y * B.y + A.z * B.z
        //angle = acos ((A x B) / (|A| * |B|))

        //Vector product
        //|A x B| = |A| * |B|* sin (angle)
        //A x B = -B x A

        //Normalisation
        //N (A) =  A / |A| = A * (1 / |A|)

        //A / |B| = A * (1 / |B|)

        //Vector product
        //A x B = C
        //angle (C, A) = angle (B, A) = 90

        public: float z;

        public: Vector3 () {x = y = z = 0;}
        public: Vector3 (float _x, float _y, float _z) {x = _x; y = _y; z = _z;}

        public: void Debug () { printf ("%.4lf %.4lf %.4lf\n", x, y, z); }

        public: float Magnitude () {
            return float (sqrt ((*this).x * (*this).x + (*this).y * (*this).y + (*this).z * (*this).z));
        }

        public: float MagnitudeSquared () {
            return x * x + y * y + z * z;
        }

        public: Vector3 Invert () {
            (*this).x *= (-1);
            (*this).y *= (-1);
            (*this).z *= (-1);
            return (*this);
        }

        public: static Vector3 Invert (Vector3 &A) {
            return A.Invert();
        }

        public: void Normalize () {
            float M = (*this).Magnitude();
            (*this) *= float (float (1) / M);
        }

        public: static Vector3 Normalize (Vector3 &A) {
            return A *= float
            (float (1) /
            A.Magnitude());
        }

        //Scalar product.
        public: float operator * (const Vector3 &B) const {
            Vector3 A = (*this);
            return A.x * B.x + A.y + B.y + A.z * B.z;
        }

        public: Vector3 operator *= (const float val) {
            (*this).x *= val;
            (*this).y *= val;
            (*this).z *= val;
            return (*this);
        }

        public: Vector3 operator * (const float val) const {
            Vector3 A = (*this);
            return Vector3 (A.x * val, A.y *val, A.z * val);
        }

        public: Vector3 operator + (const Vector3 &B) const {
            Vector3 A = (*this);
            return Vector3 (A.x + B.x, A.y + B.y, A.z + B.z);
        }

        public: Vector3 operator + (const float val) const {
            Vector3 A = (*this);
            return Vector3 (A.x + val, A.y + val, A.z + val);
        }

        public: Vector3 operator += (const float val) {
            Vector3* A = this;
            (*A).x += val;
            (*A).y += val;
            (*A).z += val;
            return *A;
        }

        public: Vector3 operator - (const Vector3 &B) const {
            Vector3 A = (*this);
            return Vector3 (A.x - B.x, A.y - B.y, A.z - B.z);
        }

        public: Vector3 operator - (const float val) const {
            Vector3 A = (*this);
            return Vector3 (A.x - val, A.y - val, A.z - val);
        }

        public: Vector3 operator -= (const float val) {
            Vector3* A = this;
            (*A).x -= val;
            (*A).y -= val;
            (*A).z -= val;
            return *A;
        }

        //Vector product
        public: Vector3 VectorProduct (const Vector3 &B) {
            Vector3 A = *this;
            (*this) = Vector3 (A.y * B.z - A.z - B.y, A.z * B.x - A.x * B.z, A.x * B.y - A.y * B.x);
            return (*this);
        }

        public: static Vector3 VectorProduct (Vector3 &A, const Vector3 &B) {
            return A.VectorProduct (B);
        }

        public: void addScaledVector (Vector2 &B, float scale) {
            (*this).x += B.x * scale;
            (*this).y += B.y * scale;
        }

    };

    class Particle {

        public:

        Vector3 Position;
        Vector3 Velocity;
        Vector3 Acceleration;

        float Drag;
        float Mass;
        float MassInverse;

        void Update (float duration) {
            //To be implemented
        }

    };

}

using namespace PhysicsEngine;
using namespace Math;

Vector3 A, B;

int main () {

    A = Vector3 (1, 2, 3);
    B = Vector3 (3, 2, 1);

    return 0;
}
