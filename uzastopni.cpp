#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int COUNT, current_sub = -123123, solution = 2000000, current_count, beginning, ending, sub_size, n, a, b, prev_number = -123123, number;
int visited [1000005];
vector <int> array;

int find_first (int start_index)
{
    for (int i = start_index; i < n; i++)
    {
        if (array [i] == -1)
        {
            for (int j = 0; j < sub_size; j++)
                visited [j] = 0;
            COUNT = 0;
            return i;
        }

        if (!visited [array [i]])
            COUNT++;

        visited [array [i]]++;

        if (COUNT == sub_size)
            return i;
    }

    return -1;
}

int cut(int start_index, int end_index)
{
    for (int i = start_index; i <= end_index; i++)
    {
        visited [array [i]]--;
        if (!visited [array [i]])
        {
            COUNT--;
            return i;
        }
    }

    return -1;
}

int main()
{
    scanf ("%d %d %d", &n, &a, &b);
    if ((b - a) + 1 > 1000000)
    {
        printf ("-1");
        return 0;
    }

    sub_size = (b - a) + 1;

    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &number);
        if (number < a || number > b)
        {
            number = -1;
            if (prev_number != -1)
                array.push_back (number);
        }
        else
        {
            number = (b - number);
            array.push_back (number);
        }

        prev_number = number;
    }

    int START = 0, END, current_index = 0, n = array.size();

    while ((n - current_index) >= sub_size)
    {
        int index = find_first(current_index);

        if (index == -1)
            break;
        else if (array [index] == -1)
        {
            current_index = index + 1;
            START = index + 1;
        }
        else
        {
            int now = cut (START, n);
            solution = min (solution, (index - now) + 1);
            current_index = index + 1;
            START = now + 1;
        }
    }

    printf ("%d\n", (solution == 2000000) ? -1 : solution);

    return 0;
}






