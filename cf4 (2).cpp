#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef unsigned long long int ull;

const ull n = 11;

int main()
{

    ull path_length = 3, solution(0);
    /*while (true)
    {*/
        ull path_branches = (n - 2) / path_length;

        ull sol = 0;
        for (ull i = 1; i <= path_length; i++)
        {
            ull cnt = (path_branches - 1) * (path_length - i);
            solution += cnt;
        }
        printf ("%lld\n", solution);
        path_length++;
    //}


    return 0;
}
