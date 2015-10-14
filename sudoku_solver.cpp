#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define ovaj (*this)

enum FIELD {
    FIXED,
    EMPTY,
    IN_PROGRESS
};

class Point {

public:

    int x, y;

    Point () { }
    Point (int _x, int _y) {x = _x; y = _y;}

};

class Sudoku {

public:

    int matrix [20] [20];
    FIELD mark [20] [20];
    int fieldsOpen;
    vector <Point> empty_fields;
    bool solved;

    Sudoku () { solved = false; fieldsOpen = 0; }

    void input () {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                scanf ("%d", &matrix [i] [j]);
                if (matrix [i] [j] == 0) {
                    fieldsOpen++;
                    mark [i] [j] = EMPTY;
                    empty_fields.push_back (Point (i, j));
                }
                else
                    mark [i] [j] = FIXED;
            }
        }
        return;
    }

    void print () {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                printf ("%d ", matrix [i] [j]);
            }
            printf ("\n");
        }
    }

    bool checkField (int x, int y, int val) {

        for (int i = 1; i <= 9; i++)
            if ((matrix [i] [y] == val && x != i) || (matrix [x] [i] == val && i != y))
                return false;

        int startX = ((x > 3) ? (x % 3) * 3 + 1 : 1), startY = ((y > 3) ? (y % 3) * 3 + 1 : 1);
        int endX = startX + 2, endY = startY + 2;

        cout<<startX<<" "<<startY<<endl;

        for (int i = startX; i <= endX; i++)
            for (int j = startY; j <= endY; j++)
                if (x = i && y == j)
                    continue;
                else if (matrix [i] [j] == val)
                    return false;

        return true;
    }

    void Solve (const Point&, int);

    void Solve_Sudoku () {
        Solve (Point (1, 1), 0);
        return;
    }

};

Sudoku sudoku = Sudoku();

#define DEBUG

void Sudoku::Solve (const Point &currentField, int ind) {

    printf ("%d %d\n", currentField.x, currentField.y);
    sudoku.print();

    puts ("<----------------------------->");
    system ("pause");

    //FAIL
    if (ind == ovaj.empty_fields.size()) {
        printf ("The program has crashed.\n");
        exit (0);
        system ("pause");
    }
    //HOPEFULLY WE'LL GET TO THIS SAFELY!!! ^^
    if ((ovaj.solved = !(ovaj.fieldsOpen)))
        return;

    for (int i = 1; i <= 9; i++) {
        if (ovaj.checkField (currentField.x, currentField.y, i) == true) {
            ovaj.matrix [currentField.x] [currentField.y] = i;
            ovaj.fieldsOpen--;
            Sudoku::Solve (ovaj.empty_fields [ind + 1], ind + 1);
        }
        ovaj.matrix [currentField.x] [currentField.y] = 0;
        ovaj.fieldsOpen++;
    }

    ovaj.matrix [currentField.x] [currentField.y] = 0;
    ovaj.fieldsOpen++;

    return;
}




int main () {

    //freopen ("SudokuInput.txt", "r", stdin);

    sudoku.input();
    //sudoku.Solve_Sudoku();
    //sudoku.print();

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout<<i<<"-"<<j<<endl;
            sudoku.checkField (i, j, 1);
        }
    }

    return 0;
}





/*
PUZZLE_ONE:
7 9 0 0 0 0 3 0 0
0 0 0 0 0 6 9 0 0
8 0 0 0 3 0 0 7 6
0 0 0 0 0 5 0 0 2
0 0 5 4 1 8 7 0 0
4 0 0 7 0 0 0 0 0
6 1 0 0 9 0 0 0 8
0 0 2 3 0 0 0 0 0
0 0 9 0 0 0 0 5 4
SOLUTION:
7 9 6 8 5 4 3 2 1
2 4 3 1 7 6 9 8 5
8 5 1 2 3 9 4 7 6
1 3 7 9 6 5 8 4 2
9 2 5 4 1 8 7 6 3
4 6 8 7 2 3 5 1 9
6 1 4 5 9 7 2 3 8
5 8 2 3 4 1 6 9 7
3 7 9 6 8 2 1 5 4


EMPTY
1 2 3 4 5 6 7 8 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

TEST AVAILABILITY
0 0 0 0 0 0 0 0 0
0 0 0 0 0 3 0 8 5
0 0 1 0 2 0 0 0 0
0 0 0 5 0 7 0 0 0
0 0 4 0 0 0 1 0 0
0 9 0 0 0 0 0 0 0
5 0 0 0 0 0 0 7 3
0 0 2 0 1 0 0 0 0
0 0 0 0 4 0 0 0 9
*/
