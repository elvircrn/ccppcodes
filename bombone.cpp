#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int set_count = 3;

long long int n, array [100100], counter [5];
vector <long long int> numbers;
long long int solution;

long long int find (long long int index)
{
    for (int i = index; i < n; i++)
    {
        long long int picked = -1;
        for (int j = 0; j < numbers.size(); j++)
        {
            if (array [i] == numbers [j])
            {
                counter [j]++;
                picked = j;
                break;
            }
        }
        if (picked == -1)
        {
            if (numbers.size() == 3)
                return i;
            else
            {
                numbers.push_back (array [i]);
                counter [numbers.size() - 1] = 1;
            }
        }
    }
    return n;
}

int main()
{
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf ("%lld", &array [i]);

    long long int prev(0);

    for (int i = 0; i < n; i++)
    {
        long long int found = find (i);

        if (found == n)
        {
            long long int ASD = ((n - 1) - prev) + 1;
            solution += ((ASD + 1) * ASD) / 2;
            break;
        }

        solution += (((found - 1) - prev) + 1);

        for (int j = 0; j < numbers.size(); j++)
        {
            if (array [prev] == numbers [j])
            {
                counter[j]--;
                if (counter [j] == 0)
                {
                    numbers.erase(numbers.begin() + j);
                    for (int k = j; k < numbers.size(); k++)
                        counter [k] = counter [k + 1];
                }
                break;
            }
        }

        prev++;

        i = found - 1;
    }

    printf ("%lld\n", solution);

    return 0;
}
