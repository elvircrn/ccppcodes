#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define GORE 0
#define DESNO 1

char field [10] [10];
FILE *out_file;
int number_of_moves = 0, q, index, direction;

void print_field()
{
    for (int i = 0; i < 8; i++)
        puts (field [i]);
}

void fprint_field()
{
    out_file = fopen ("OUTPUT.txt", "w");
    for (int i = 0; i < 8; i++, fprintf (out_file, "\n"))
        for (int j = 0; j < 8; j++)
            fprintf (out_file, "%c", field [i] [j]);
    fprintf (out_file, "%d\n", number_of_moves);
    fclose (out_file);
}

int main ()
{
    srand (time (0));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            field [i] [j] = '+';

    int t = 100000000;

    while (t--)
    {
        q = 1;
        if (q == 1)
        {
            index = rand() % 8;
            direction = rand() % 2;
            for (int i = 0; i < 8; i++)
            {
                if (direction == GORE)
                {
                    if (field [index] [i] == '+')
                        field [index] [i] = '-';
                    else
                        field [index] [i] = '+';
                }
                else if (direction == DESNO)
                {
                    if (field [i] [index] == '+')
                        field [i] [index] = '-';
                    else
                        field [i] [index] = '+';
                }
            }
        }
        if (q == 2)
        {
            fprint_field();
        }
        number_of_moves++;
    }

    fprint_field();

    //system ("pluseviiminusevi.exe");

    return 0;
}
