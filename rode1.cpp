#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int array [1000100], n, b [1000100];

int merge (int left, int mid, int right)
{
    int solution = 0;
    for (int i = left; i <= right; i++)
        b [i] = array [i];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (b [i] <= b [j])
            array [k++] = b [i++];
        else
        {
            solution += (mid - i);
            array [k++] = b [j++];
        }
    }

    while (i <= mid)
        array [k++] = b [i++];
    while (j <= right)
        array [k++] = b [j++];

    return solution;
}

int merge_sort (int left, int right)
{
    int solution = 0;
    if (left < right)
    {
        int pivot = (left + right) / 2;
        solution = merge_sort (left, pivot);
        solution += merge_sort (pivot + 1, right);
        solution += merge (left, pivot, right);
    }
    return solution;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &array [i]);

    printf ("%d\n", merge_sort (0, n - 1));

    return 0;
}
