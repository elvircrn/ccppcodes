#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int solution, n, red_count, blue_count;
char balls [100];
vector <char> STACK;

int main()
{
    scanf ("%d %s", &n, &balls);

    for (long long int i = 0; i < n; i++)
    {
        if (balls [i] == 'R')
            red_count++;
        else
            blue_count++;

        STACK.push_back (balls [i]);
    }

    int rc = red_count;

    reverse(STACK.begin(), STACK.end());


    while (blue_count)
    {
        solution++;
        while (!STACK.empty() && STACK [STACK.size() - 1] == 'R')
        {
            red_count--;
            STACK.pop_back();
        }

        if (!STACK.empty())
        {
            STACK [STACK.size() - 1] = 'R';
            red_count++;
        }

        while (STACK.size() != n)
        {
            blue_count++;
            STACK.push_back ('B');
        }
    }

    printf ("%d\n", solution - (rc > 0));

    return 0;
}









