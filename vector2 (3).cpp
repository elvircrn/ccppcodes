#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>

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