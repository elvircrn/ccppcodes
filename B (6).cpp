#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int limit, sum, n;
bool visited [110000];
vector <int> solution;

int main()
{
    scanf ("%d %d", &sum, &limit);

    int power = 1;

    while (sum)
    {
        if (sum < power)
        {
            printf ("-1\n");
            return 0;
        }

        int current_number = power, counter = power * 2;

        while (current_number <= limit)
        {
            if (visited [current_number] == false && sum >= power)
            {
                visited [current_number] = true;
                sum -= power;
                solution.push_back (current_number);
            }
            if (sum < power)
            {
                printf ("-1\n");
                return 0;
            }

            current_number += counter;
            counter *= 2;
        }

        power *= 2;
    }

    printf ("%d\n", solution.size());
    for (int i = 0; i < solution.size() - 1; i++)
        printf ("%d ", solution [i]); printf ("%d\n", solution [solution.size() - 1]);

    return 0;
}
