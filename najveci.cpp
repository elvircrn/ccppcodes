#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char current_number [100100], solution_string  [101], number_solution [100100], current_string [100001];
int solution_size = 0;
vector <char> sol;
bool flag2, first = true;

int main()
{
    char c;
    while (true)
    {
        bool flag = false;
        current_string [1] = '\0';
        current_string [0] = getchar();
        l2:;
        if (current_string [0] == '\n' || current_string [0] == EOF)
            break;

        scanf ("%[^=]", current_string + 1);

        if (getchar() == '\n')
            flag2 = true;

        bool finished_comparing = false, greater = false;
        int index = 0;
        while (isdigit ((c = getchar())))
        {
            cout<<c<<endl;
            if (!isdigit (c))
            {
                if (c == '\n')
                {
                    flag2 = true;
                    goto l1;
                }
                current_string [0] = c;
                goto l2;
                flag = true;
            }
            current_number [index] = c;
            if (current_number [index] > number_solution [index] && !finished_comparing)
            {
                greater = true;
                finished_comparing = true;
            }

            index++;
        }

        if (flag)
            continue;

        if (index > strlen (number_solution))
            greater = true;

        current_number [index] = '\0';

        if (index < strlen (number_solution))
            greater = false;

        if (greater)
        {
            int s = strlen (current_string);

            if (s < 3)
                continue;

            sol.clear();

            for (int i = 1; i <= 3 && s - i > -1; i++)
                if (toupper (current_string [s - i]) == current_string [s - i])
                    goto l1;
                else
                    sol.push_back (current_string [s - i]);
            reverse(sol.begin(), sol.end());
            strcpy (number_solution, current_number);
        }

        first = false;
        l1:;

        if (flag2)
            break;
    }

    if (sol.empty())
        printf ("NEMA NIJEDNA VARIJABLA\n");
    else
    {
        for (int i = 0; i < sol.size(); i++)
            cout<<sol [i];
        printf ("=%s;\n", number_solution);
    }

        //printf ("%s=%s\n", solution_string, number_solution);
    return 0;
}


























