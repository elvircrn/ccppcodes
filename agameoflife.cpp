#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dirX [8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dirY [8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

char field [1000] [1000], kopija [1000] [1000];
int width, height;

void clear()
{
    for (int i = 1; i <= height; i++)
        for (int j = 1; j <= width; j++)
            field [i] [j] = '.';
}

void print()
{
    for (int i = 1; i <= height; i++)
        puts (field [i]);

    puts ("Algorithm made by John Conway and implemented by Elvir Crncevic");
}

void set_at (int x, int y)
{
    field [x] [y] = '#';
}

void SAVE ()
{
    for (int i = 1; i <= height; i++)
        for (int j = 1; j <= width; j++)
            kopija [i] [j] = field [i] [j];
}

void LOAD()
{
    for (int i = 1; i <= height; i++)
        for (int j = 1; j <= width; j++)
            field [i] [j] = kopija [i] [j];
}

int main ()
{
    FILE *file = fopen ("file.txt", "r");

    fscanf (file, "%d %d", &height, &width);
    for (int i = 0; i < height; i++)
        fscanf (file, "%s", &field [i]);

    fclose (file);

    print();
    system ("pause");
    system ("cls");

    for (;;)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int empty = 0, full = 0;

                for (int direction = 0; direction < 8; direction++)
                {
                    int X = i + dirX [direction];
                    int Y = j + dirY [direction];

                    if (X >= 0 && Y >= 0 && X < height && Y < width)
                    {
                        if (field [X] [Y] == '.')
                            empty++;
                        else if (field [X] [Y] == '#')
                            full++;
                    }
                }

                if (full < 2)
                    kopija [i] [j] = '.';
                else if (full >= 4)
                    kopija [i] [j] = '.';
                else if (full == 3)
                    kopija [i] [j] = '#';
                else if (full == 2 && field [i] [j] == '#')
                    kopija [i] [j] = '#';
                else
                    kopija [i] [j] = '.';
            }
        }

        LOAD();
        print();
        system ("cls");
    }

    system ("pause");
    return 0;
}
/*
20 56
........................................................
........................................................
........................................................
........................................................
........................................................
.............................##.........##..............
............................#.#.........##..............
......##.......##...........##..........................
......##......#.#.......................................
..............##......##................................
......................#.#...............................
......................#.................................
.........................................##.............
.........................................#.#............
.........................................#..............
........................................................
........................................................
..............................###.......................
..............................#.........................
...............................#........................
*/
