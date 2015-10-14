#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>

using namespace std;

char in[110];
int len, solution;

vector <int> nums [200];

int main()
{
    scanf ("%s", &in);

    len = strlen (in);

    int current_count = 1;

    for (int i = 1; i < len; i++)
    {
        if (in [i] != in [i - 1])
        {
            nums [in [i - 1]].push_back (current_count);
            current_count = 0;
        }
        current_count++;
    }

    nums [in [len - 1]].push_back (current_count);

    for (int i = 'A'; i < 'Z'; i++)
    {
        for (int j = 0; j < nums [i].size(); j++)
            solution += !(nums [i] [j] % 2);
    }

    printf ("%d\n", solution);

    return 0;
}
