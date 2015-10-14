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
            for (int j = i - 1; j >= start_index; j--)
                visited [array [j]] = 0;
            return i;
        }
        if (!visited [array [i]])
            COUNT++;
        visited [array [i]]++;
        if (count == sub_size)
            return i;
    }

    return -1;
}

int cut(int start_index, int end_index)
{
    int sol = -1;
    for (int i = start_index; i <= end_index; i++)
    {
        visited [array [i]]--;
        if (!visited [array [i]])
        {
            COUNT--;
            if (sol == -1)
                sol = i;
        }
    }

    return sol;
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

    while ((n - current_index) + 1 >= sub_size)
    {
        int index = find_first (current_index);
        if (index == -1)
            break;
        if (array [index] != -1)
        {
            int now = cut(START, index);
            solution = min (solution, (index - now) + 1);
            current_index = now + 1;
            for (int i = 0; i < sub_size; i++)
                visited [i] = 0;
        }
        else if (array [index] == -1)
        {
            COUNT = 0;
            current_index = index + 1;
            START = current_index;
        }
    }

    printf ("%d\n", (solution != 2000000) ? solution : -1);

    return 0;
}







