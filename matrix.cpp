#include "matrix.h"

Matrix::Matrix () {
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
            (*this).m [i] [j] = 0;
}

Matrix::Matrix (int _h, int _w) {
    height = _h;
    width = _w;
    for (int i = 0; i <= (*this).height; i++)
        for (int j = 0; j <= (*this).width; j++)
            (*this).m [i] [j] = 0;
}

void Matrix::TetrisRotationMatrix () {
    (*this).m [0] [1] = -1;
    (*this).m [1] [0] = 1;
};
