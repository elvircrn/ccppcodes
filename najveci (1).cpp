#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char current_number [10100], solution_string  [101], number_solution [10100], current_string [10001];
int solution_size = 0;
bool first = true;

int main()
{
    char c;
    while (true)
    {
        if (!first)
        {
            current_string [0] = getchar();
            if (current_string [0] == '\n' || current_string [0] == EOF)
                break;
            scanf ("%[^=]", current_string + 1);
        }
        else
        {
            solution_string [0] = getchar();
            if (solution_string [0] == '\n' || solution_string [0] == EOF)
                break;
            scanf ("%[^=]", solution_string + 1);
        }

        getchar();

        if (first)
        {
            first = false;
            char cc;
            while ((cc = getchar()) != ';')
            {
                number_solution [solution_size] = cc;
                solution_size++;
            }
            number_solution [solution_size] = '\0';
        }
        else
        {
            bool finished_comparing = false, greater = false;
            int index = 0;
            while (((c = getchar()) != ';'))
            {
                current_number [index] = c;
                if (current_number [index] > number_solution [index] && !finished_comparing)
                {
                    greater = true;
                    finished_comparing = true;
                }

                index++;
                if (index > solution_size)
                {
                    greater = true;
                }
            }

            current_number [index] = '\0';

            if (index < strlen (number_solution))
                greater = false;


            if (greater)
            {
                int s = strlen (current_string);
                solution_string [2] = current_string [s - 3];
                solution_string [1] = current_string [s - 2];
                solution_string [0] = current_string [s - 1];
                solution_string [3] = '\0';
                strcpy (number_solution, current_number);
            }
        }
    }

    int ss = strlen (solution_string);


    for (int i = 3; i >= 1; i--)
        if (isalpha (solution_string [ss - i]))
            putchar (solution_string [ss - i]);
    printf ("=%s;\n", number_solution);


        //printf ("%s=%s\n", solution_string, number_solution);
    return 0;
}


























