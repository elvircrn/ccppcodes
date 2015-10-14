#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int array[4];

struct op
{
    int number;
    char operation;

    op() { }
    op(int _number, char _operation) { number = _number; operation = _operation; }
};

vector <op> ops;

bool solve (int current_number, int mask, int PREV_NUMBER, char PREV_OPERATION)
{
    if (current_number == 24 && mask == 15)
    {
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (!((1<<i) & mask))
        {
            if (solve (current_number + array [i], mask + (1<<i), array [i], '+'))
            {
                printf ("%d\n", current_number);
                ops.push_back (op (array [i], '+'));
                return true;
            }
            if (solve (current_number - array [i], mask + (1<<i), array [i], '-'))
            {
                printf ("%d\n", current_number);
                ops.push_back (op (array [i], '-'));
                return true;
            }

            if (solve (current_number * array [i], mask + (1<<i), array [i], '*'))
            {
                printf ("%d\n", current_number);
                ops.push_back (op (array [i], '*'));
                return true;
            }


            if (current_number % array [i] == 0)
            {
                if (solve (current_number / array [i], mask + (1<<i), array [i], '/'))
                {
                    printf ("%d\n", current_number);
                    ops.push_back (op (array [i], '/'));
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    for (int i = 0; i < 4; i++)
        scanf ("%d", &array [i]);

    int start;

    for (int i = 0; i < 4; i++)
    {
        if (solve (array [i], (1<<i), 0, 0))
        {
            start = array [i];
            break;
        }
    }

    printf ("\n\n%d\n", start);
    for (int i = ops.size() - 1; i > -1; i--)
        printf ("%c%d\n", ops [i].operation, ops [i].number);

    return 0;
}




/*
7 8 10 11


0 6 24 24


24 / 1 = 24
24 / 4 = 6


*/





