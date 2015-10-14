#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

#include "Window.h"
#include "TetrisBlock.h"
#include "Vector2.h"

using namespace std;

const int matrix_size = 15;

int matrix [1000] [1000], dp [1000] [1000];
int colums = 1, solution;

int A;

int main() {

    for (int i = 1; i <= matrix_size; i++) {
        for (int j = 1; j <= i; j++) {
            scanf ("%d", &A);
            matrix [i] [j] = A;
        }
    }

    for (int i = 1; i <= matrix_size; i++)
        for (int j = 1; j <= i; j++)
            dp [i] [j] = max (dp [i - 1] [j - 1], dp [i - 1] [j]) + matrix [i] [j];

    for (int i = 1; i <= matrix_size; i++)
        solution = max (dp [matrix_size] [i], solution);

    printf ("%d\n", solution);

    return 0;
}
