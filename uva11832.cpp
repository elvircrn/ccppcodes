#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define INF   1<<27
#define SHIFT 40000

short dp [41] [80080];
int target_price, n, items [41];
bool pos [41], neg [41];

short find(short current_index, int current_sum)
{
    if (current_index == n)
        return current_sum == target_price;

    if (dp [current_index] [current_sum] != -1)
        return dp [current_index] [current_sum];

    bool sum = false;
    bool sub = false;

    sum = find(current_index + 1, current_sum + items [current_index]);
    sub = find(current_index + 1, current_sum - items [current_index]);

    pos [current_index] |= sum;
    neg [current_index] |= sub;

    return (dp [current_index] [current_sum] = (sum | sub));
}

inline void print_sol()
{
    for (int i = 0; i < n; i++)
        if (pos [i] && neg [i])
            putc ('?', stdout);
        else if (pos [i])
            putc ('+', stdout);
        else
            putc ('-', stdout);

    putc('\n', stdout);
}

int main()
{
    while (scanf ("%d %d", &n, &target_price) == 2 && (n || target_price))
    {
        int current_sum = 0;

        for (int i = 0; i <= n; i++)
            pos [i] = neg [i] = false;

        memset (dp, -1, sizeof dp);

        for (int i = 0; i < n; i++)
        {
            scanf ("%d", &items [i]);
            current_sum += items [i];
        }

        if (current_sum < target_price)
            printf ("*\n");
        else
        {
            target_price += SHIFT;

            if (find(0, SHIFT))
                print_sol();
            else
                printf ("*\n");
        }
    }

    return 0;
}

//-3 + 1 + 5



















