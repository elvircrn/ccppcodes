#include "Vector.h"


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

Vector2::Vector2 () {x = y = 0;}
Vector2::Vector2 (float _x, float _y) {x = _x; y = _y;}

Vector2::Debug () { printf ("%.4lf %.4lf\n", x, y); }

Vector2::Magnitude () {
    return float (sqrt ((*this).x * (*this).x + (*this).y * (*this).y));
}

Vector2::MagnitudeSquared () {
    return x * x + y * y;
}

Vector2::Invert () {
    (*this).x *= (-1);
    (*this).y *= (-1);
    return (*this);
}

Vector2::Invert (Vector2 &A) {
    return A.Invert();
}

Vector2::Normalize () {
    float M = (*this).Magnitude();
    (*this) *= float (float (1) / M);
}

Vector2 Vector2::Normalize (Vector2 &A) {
    return A *= float
    (float (1) /
    A.Magnitude());
}

//Scalar product.
float Vector2::operator * (const Vector2 &B) const {
    Vector2 A = (*this);
    return A.x * B.x + A.y + B.y;
}

Vector2 Vector2::operator *= (const float val) {
    (*this).x *= val;
    (*this).y *= val;
    return (*this);
}

Vector2 Vector2::operator * (const float val) const {
    Vector2 A = (*this);
    return Vector2 (A.x * val, A.y *val);
}

Vector2 Vector2::operator + (const Vector2 &B) const {
    Vector2 A = (*this);
    return Vector2 (A.x + B.x, A.y + B.y);
}

Vector2::operator + (const float val) const {
    Vector2 A = (*this);
    return Vector2 (A.x + val, A.y + val);
}

Vector2 Vector2::operator += (const float val) {
    Vector2* A = this;
    (*A).x += val;
    (*A).y += val;
    return *A;
}

Vector2 Vector2::operator - (const Vector2 &B) const {
    Vector2 A = (*this);
    return Vector2 (A.x - B.x, A.y - B.y);
}

Vector2 Vector2::operator - (const float val) const {
    Vector2 A = (*this);
    return Vector2 (A.x - val, A.y - val);
}

Vector2 Vector2::operator -= (const float val) {
    Vector2* A = this;
    (*A).x -= val;
    (*A).y -= val;
    return *A;
}

/*Vector2::addScaledVector (Vector2 &B, float scale) {
    (*this).x += B.x * scale;
    (*this).y += B.y * scale;
}*/
