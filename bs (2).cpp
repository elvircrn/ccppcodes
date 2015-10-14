#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define DEBUG

long long int solution, top_index, array [1000100], n;
vector <long long int> S;

int binary_search (long long int element)
{
    int Left = 0, Right = n - 1, pivot, current_sol = -1;
    while (Left <= Right)
    {
        printf ("Left: %d Right: %d\n", Left, Right);
        pivot = (Left + Right) / 2;

        if (element >= array [pivot])
        {
            Left = pivot + 1;
            current_sol = pivot;
        }
        else
            Right = pivot - 1;
    }

    return current_sol;
}

int main()
{
    freopen ("input.txt", "r", stdin);
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf ("%lld", &array [i]);

    cout<<upper_bound (array, array + n, 7) - array<<endl;

    return 0;
}
