#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <ctime>

using namespace std;

char matrix [1000] [1000];

int n, m;

struct point
{
    int x, y;

    point () { }
    point (int _x, int _y) { x = _x; y = _y; }

    void print ()
    {
        printf ("%d %d\n", x, y);
    }

    bool operator == (const point &B) const
    {
        return (x == B.x && y == B.y);
    }
};

bool check (FILE *brut, FILE *solution)
{
    int n1, n2;
    point array1 [100], array2 [100];
    fscanf (brut, "%d", &n1);
    fscanf (solution, "%d", &n2);

    if (n1 != n2)
        return false;

    for (int i = 0; i < n1; i++)
    {
        fscanf (brut, "%d %d", &array1 [i].x, &array1 [i].y);
        fscanf (solution, "%d %d", &array2 [i].x, &array2 [i].y);
    }

    for (int i = 0; i < n1; i++)
    {
        bool nasao = false;
        for (int j = 0; j < n2; j++)
        {
            if (array1 [i] == array2 [j])
            {
                nasao = true;
                break;
            }
        }

        if (nasao == false)
            return false;
    }

    return true;
}

void generate_cases (FILE *test_case)
{
    test_case = fopen ("test_case.txt", "wt");
    n = 10, m = 10;

    fprintf (test_case, "%d %d\n", n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0 || i == n - 1 && j == m - 1)
                matrix [i] [j] = '.';
            else
            {
                int RANDOM = rand () % 5;

                if (RANDOM == 0 || RANDOM == 1)
                    matrix [i] [j] = '#';
                else
                    matrix [i] [j] = '.';
            }
        }
    }

    for (int i = 0; i < n; i++, fprintf (test_case, "\n"))
        for (int j = 0; j < m; j++)
            fprintf (test_case, "%c", matrix [i] [j]);

    fclose (test_case);
}

void custom_input (FILE *test_case)
{
    test_case = fopen ("test_case.txt", "r");
    fscanf (test_case, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        fscanf (test_case, "%s", &matrix [i]);
}

void print_case (FILE *cases)
{
    fprintf (cases, "%d %d\n", n, m);
    for (int i = 0; i < n; i++, fprintf (cases, "\n"))
        for (int j = 0; j < m; j++)
            fprintf (cases, "%c", matrix [i] [j]);

    fprintf (cases, "\n<-------------->\n\n");
}

int t, progress, current, total;

int main ()
{
    srand (time (0));

    FILE *brute_force, *my_solution, *test_case, *OUTPUT;
    OUTPUT = fopen ("OUTPUT.txt", "wt");

    fclose (OUTPUT);

    total = t;

    while (true)
    {
        generate_cases(test_case);
        //custom_input (test_case);

        system ("my_solution1.exe");
        system ("brut_froce.exe");

        brute_force = fopen ("brut_output.txt", "r");
        my_solution = fopen ("my_output.txt", "r");

        if (!check (brute_force, my_solution))
        {
            print_case (OUTPUT);
            break;
        }

        current++;
        fclose (brute_force);
        fclose (my_solution);
    }

    return 0;
}
