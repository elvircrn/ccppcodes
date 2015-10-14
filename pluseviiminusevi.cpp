#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define DESNO 1

#define GORE 0
#define DOLE 2
//ide seeeeeeeeeeeeeeeeeeee

#define SIZE 8

char field [10] [10];
int k;

void print_field()
{
    for (int i = 0; i < SIZE; i++, printf ("\n"))
        for (int j = 0; j < SIZE; j++)
            cout<<field [i] [j];
}

int count_pluses()
{
    int ret = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (field [i] [j] == '+')
                ret++;
    return ret;
}

int solve ()
{
    bool nasao = true, real_solution = 0;
    while (nasao && k)
    {
        nasao = false;
        int solution = 0, solution_direction = 0, solution_index = 0;
        for (int i = 0; i < SIZE; i++)
        {
            int minusevi_desno = 0, plusevi_desno = 0, minusevi_gore = 0, plusevi_gore = 0;
            for (int j = 0; j < SIZE; j++)
            {
                if (field [i] [j] == '+')
                    plusevi_desno++;
                else
                    minusevi_desno++;

                if (field [j] [i] == '+')
                    plusevi_gore++;
                else
                    minusevi_gore++;
            }

            if (minusevi_desno > solution && minusevi_desno > plusevi_desno)
            {
                solution = minusevi_desno;
                solution_direction = DESNO;
                solution_index = i;
                nasao = true;
            }

            if (minusevi_gore > solution && minusevi_gore > plusevi_gore)
            {
                solution = minusevi_gore;
                solution_direction = GORE;
                solution_index = i;
                nasao = true;
            }
        }

        if (nasao == false)
            break;

        if (solution_direction == DESNO)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (field [solution_index] [i] == '+')
                    field [solution_index] [i] = '-';
                else
                    field [solution_index] [i] = '+';
            }
        }
        else
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (field [i] [solution_index] == '+')
                    field [i] [solution_index] = '-';
                else
                    field [i] [solution_index] = '+';
            }
        }
        k--;
    }

    int r_solution = 100;

    if (k % 2 == 0)
        return count_pluses();
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < SIZE; j++)
            {
                if (field [i] [j] == '+')
                    cnt1++;
                if (field [i] [j] == '+')
                    cnt2++;
            }
            r_solution = min (r_solution, cnt1);
            r_solution = min (r_solution, cnt2);
        }
    }

    return count_pluses() - r_solution + (SIZE - r_solution);
}

int main ()
{
    FILE *f = fopen ("OUTPUT.txt", "r");
    freopen ("OUTPUT.txt", "r", stdin);
    for (int i = 0; i < SIZE; i++)
        fscanf (f, "%s", &field [i]);
    fscanf (f, "%d", &k);

    print_field();

    printf ("%d\n", solve());

    fclose (f);

    //system ("pause");
    return 0;
}
/*
-+++++++
-+++++++
-+++++++
+-------
-+++++++
-+++++++
-+++++++
-+++++++
2
*/
