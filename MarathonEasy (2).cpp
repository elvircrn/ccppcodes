#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

int n;
int x[500000], y[500000];
int dist;
int dp[500000];

const int test_cases = 15;

FILE *in, *out;

string numbers [16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15" };

int main()
{
    for (int i = 1; i <= test_cases; i++)
    {
        memset (x, 0, sizeof x);
        memset (y, 0, sizeof y);
        dist = 0;
        n = 0;

        string current_file = (numbers [i] + ".in");

        printf ("current_file: %s\n", current_file.c_str());

        in = fopen (current_file.c_str(), "r");

        fscanf (in, "%d", &n);

        for (int i = 0; i < n; i++)
        {
            //cin >> x[i] >> y[i];
            fscanf (in, "%d %d", &x [i], &y [i]);
            dist += (i != 0) ? (abs (x[i] - x[i - 1]) + abs (y[i] - y[i - 1])) : 0;
        }

        int res = dist;
        for (int i = 1; i < n - 1; i++)
            res = min(res, dist - abs (x[i] - x[i - 1]) - abs (y[i] - y[i - 1])
                        - abs (x[i] - x[i + 1]) - abs (y[i] - y[i + 1])
                        + abs (x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]));


        printf ("irfan: %d\n", res);

        fclose (in);
    }

    return 0;
}


























