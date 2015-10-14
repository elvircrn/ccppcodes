#include "TetrisBlock.h"
#include "matrix.h"
#include "vector2.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

TetrisBlock::TetrisBlock() { }
TetrisBlock::TetrisBlock (Vector2 position, char shape) {

    color = shape;

    if (shape == 'O')
        TetrisBlock::CreateO(position);
    else if (shape == 'T')
        TetrisBlock::CreateT(position);
    else if (shape == 'S')
        TetrisBlock::CreateS(position);
    else if (shape == 'I')
        TetrisBlock::CreateI(position);
    else if (shape == 'Z')
        TetrisBlock::CreateZ(position);
    else if (shape == 'L')
        TetrisBlock::CreateL(position);
    else if (shape == 'J')
        TetrisBlock::CreateJ(position);
};

void TetrisBlock::CreateI(Vector2 position) {
    TetrisBlock::blocks.push_back (position);
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 2, position.y));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 3, position.y));
    origin = Vector2 (blocks [1].x + 0.5f, blocks [1].y + 0.5f);
}

void TetrisBlock::CreateJ(Vector2 position) {
    TetrisBlock::blocks.push_back (position);
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 2, position.y));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 2, position.y - 1));
    origin = blocks [1];
}

void TetrisBlock::CreateL(Vector2 position) {
    TetrisBlock::blocks.push_back (position);
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 2, position.y));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 2, position.y + 1));
    origin = blocks [1];
}

void TetrisBlock::CreateS(Vector2 position) {
    TetrisBlock::blocks.push_back (position);
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y - 1));
    TetrisBlock::blocks.push_back (Vector2 (position.x, position.y + 1));
    origin = blocks [1];
}

void TetrisBlock::CreateZ(Vector2 position) {
    TetrisBlock::blocks.push_back (position);
    TetrisBlock::blocks.push_back (Vector2 (position.x, position.y + 1));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y + 1));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y + 2));
    origin = blocks [1];
}

void TetrisBlock::CreateO(Vector2 position) {
    TetrisBlock::blocks.push_back (position);
    TetrisBlock::blocks.push_back (Vector2 (position.x, position.y + 1));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y + 1));
    origin = Vector2 (blocks [0].x + 0.5f, blocks [0].x + 0.5f);
}

void TetrisBlock::CreateT(Vector2 position) {
    TetrisBlock::blocks.push_back (position);
    TetrisBlock::blocks.push_back (Vector2 (position.x, position.y + 1));
    TetrisBlock::blocks.push_back (Vector2 (position.x, position.y - 1));
    TetrisBlock::blocks.push_back (Vector2 (position.x + 1, position.y));
    origin = blocks [0];
}

void TetrisBlock::RotateClockwise(int W, int H) {

    Vector2 kopija [5], o, solution;
    Matrix m = Matrix (2, 2);
    m.TetrisRotationMatrix();

    for (int i = 0; i < blocks.size(); i++) {

        solution = blocks [i];

        solution -= o;
        solution *= m; solution += o;

        if (!solution.x || !solution.y || solution.x > H || solution.y > W)
            return;

        kopija [i] = solution;

    }

    for (int i = 0; i < 4; i++)
        blocks [i] = kopija [i];
}

int TetrisBlock::Depth() {
    int Maximum = 0;

    for (int i = 0; i < blocks.size(); i++)
        Maximum = max (Maximum, int (blocks [i].x));

    return Maximum;
}






