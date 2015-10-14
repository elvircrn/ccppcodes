#include "all.h"
#include "matrix.h"
#include "vector2.h"

Vector2::Vector2 () {}
Vector2::Vector2 (float _x, float _y) {
    this->x = _x;
    this->y = _y;
}

void Vector2::operator *= (const Matrix & M) {
    Vector2 k = (*this);
    (*this) = Vector2 (k.y, -k.x);
}

float Vector2::operator * (const Vector2 & B) const {
    Vector2 A = (*this);
    return (A.x * B.x + A.y * B.y);
}

void Vector2::print () const {
    printf ("%d %d\n", (*this).x, (*this).y);
}

void Vector2::operator-= (const Vector2 &B) {
    (*this).x -= B.x;
    (*this).y -= B.y;
}

void Vector2::operator+= (const Vector2 &B) {
    (*this).x += B.x;
    (*this).y += B.y;
}
