#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int n, array [20], dp [3000000] [20];

int myabs(int x)
{
    return (x > 0) ? x : -x;
}

void print_binary(int number)
{
    if (number <= 1)
    {
        printf ("%d", number);
        return;
    }

    vector <int> digits;

    while (number)
    {
        digits.push_back (number & 1);
        number >>= 1;
    }

    for (int i = digits.size() - 1; i > -1; i--)
        printf ("%d", digits [i]);
}

int solve (int X, int index)
{
    printf ("X: "); print_binary(X); printf (" index: %d\n", index);

    // system ("pause");

    if (X == (1<<index))
        return dp [X] [index] = array [index] * 2 + 2;

    if (dp [X] [index] != -1)
        return dp [X] [index];

    int asd = -1;

    for (int i = 0; i < n; i++)
        if (X & (1<<i) && i != index)
        {
            if (array [i] < array [index])
                asd = max (asd, solve (X - (1<<index), i) + (array [index] - array [i]) + array [index] + 2);
            else
                asd = max (asd, solve (X - (1<<index), i) + 2);
        }
    printf ("   dp [%d] [%d]: %d\n", X, index, asd);

    dp [X] [index] = asd;

    return dp [X] [index];
}

int main()
{
    freopen ("in.txt", "r", stdin);

    int first_bit(0);

    for (int i = 0; i < 3000000; i++)
        for (int j = 0; j < 20; j++)
            dp [i] [j] = -1;

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    sort (array, array + n);

    for (int i = 0; i < n; i++)
        first_bit += (1<<i);

    int solution = -123123;

    //solution = solve (first_bit - (1<<3), 3);

    for (int i = 0; i < n; i++)
    {
        solution = max (solution, solve (first_bit, i));
    }

    printf ("DP: %d\n", dp [7] [2]);

    printf ("%d\n", solution);

    return 0;
}




