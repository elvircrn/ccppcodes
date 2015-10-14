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

char in [1010];
int len, solution;

int main()
{
    scanf ("%s", &in);
    len = strlen(in);

    for (int i = 0; i < len; i++)
    {
        int cnt(1), start_index = i + 1;
        char seek_and_destroy = in [i];

        for (int j = i + 1; j < len; j++)
        {
            if (seek_and_destroy == in [j])
            {
                int seek = j + 1;
                if ((seek - start_index + 1) % 2 == 0)
                {
                    start_index = seek;
                    cnt++;
                }
            }
        }

        solution = max (solution, cnt);
    }

    printf ("%d\n", (solution == 0) ? 1 : solution);

    return 0;
}
