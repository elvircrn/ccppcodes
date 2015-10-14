#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char input[5100];
int prev_found = 0, solution, hash [200], len;

bool check(int pos)
{
    if (pos + 3 >= len)
        return false;
    return (input [pos] == 'b' && input [pos + 1] == 'e' && input [pos + 2] == 'a' && input [pos + 3] == 'r');
}

int main()
{
    scanf ("%s", &input);

    len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        int current_index = i + 1;
        if (check(i))
        {
            if (i > 0)
                solution += ((current_index - prev_found) * (len - (current_index + 3) + 1));
            else
                solution += ((len - 1) - (i + 3) + 1);
            prev_found = i + 1;
        }
    }

    printf ("%d\n", solution);

    return 0;
}
