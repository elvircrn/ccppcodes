#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int t, T, X, O;
string matrix [10];
bool nasao1;

int current_case = 1;

int main ()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    scanf ("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 4; i++)
            cin>>matrix [i];

        for (int i = 0; i < 4; i++)
        {
            X = 0;
            T = 0;
            O = 0;

            for (int j = 0; j < 4; j++)
            {
                if (matrix [i] [j] == 'X')
                    X++;
                else if (matrix [i] [j] == 'O')
                    O++;
                else if (matrix [i] [j] == 'T')
                    T++;
            }

            if (X == 3 && T == 1 || X == 4)
            {
                printf ("Case #%d: X won\n", current_case);
                goto new_case;
            }
            else if (O == 3 && T == 1 || O == 4)
            {
                printf ("Case #%d: O won\n", current_case);
                goto new_case;
            }

            X = 0;
            T = 0;
            O = 0;

            for (int j = 0; j < 4; j++)
            {
                if (matrix [j] [i] == 'X')
                    X++;
                else if (matrix [j] [i] == 'O')
                    O++;
                else if (matrix [j] [i] == 'T')
                    T++;
            }

            if (X == 3 && T == 1 || X == 4)
            {
                printf ("Case #%d: X won\n", current_case);
                goto new_case;
            }
            else if (O == 3 && T == 1 || O == 4)
            {
                printf ("Case #%d: O won\n", current_case);
                goto new_case;
            }
        }

        X = 0;
        O = 0;
        T = 0;

        for (int i = 0; i < 4; i++)
            if (matrix [i] [i] == 'X')
                X++;
            else if (matrix [i] [i] == 'O')
                O++;
            else if (matrix [i] [i] == 'T')
                T++;

        if (X == 3 && T == 1 || X == 4)
        {
            printf ("Case #%d: X won\n", current_case);
            goto new_case;
        }
        else if (O == 3 && T == 1 || O == 4)
        {
            printf ("Case #%d: O won\n", current_case);
            goto new_case;
        }

        X = 0;
        O = 0;
        T = 0;

        for (int i = 0; i < 4; i++)
        {
            if (matrix [i] [4 - (i + 1)] == 'X')
                X++;
            else if (matrix [i] [4 - (i + 1)] == 'O')
                O++;
            else if (matrix [i] [4 - (i + 1)] == 'T')
                T++;
        }

        if (X == 3 && T == 1 || X == 4)
        {
            printf ("Case #%d: X won\n", current_case);
            goto new_case;
        }
        else if (O == 3 && T == 1 || O == 4)
        {
            printf ("Case #%d: O won\n", current_case);
            goto new_case;
        }

        nasao1 = false;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (matrix [i] [j] == '.')
                    nasao1 = true;

        if (nasao1)
        {
            printf ("Case #%d: Game has not completed\n", current_case);
        }
        else
        {
            printf ("Case #%d: Draw\n", current_case);
        }

        new_case:;

        current_case++;
    }

    return 0;
}
