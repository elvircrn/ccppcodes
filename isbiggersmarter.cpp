#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct ByWeight
{
    int Weight, IQ, position;

    ByWeight () { }
    ByWeight (int  _Weight, int _IQ, int _position) { Weight = _Weight; IQ = _IQ; position = _position; }

    bool operator < (const ByWeight B) const
    {
        //if (Weight != B.Weight)
            return Weight < B.Weight;
        //else
        //    return IQ > B.IQ;
    }
};

vector <ByWeight> ByWeights;
vector <int> SOLUTION;
int A, B, n, dp [1010], indexes [1010], solution, solution_index;

int main ()
{
    freopen ("input (2).txt", "r", stdin);

    while (scanf ("%d %d", &A, &B) == 2)
    {
        dp [n] = 1;
        ByWeights.push_back (ByWeight (A, B, n));
        n++;
    }

    sort (ByWeights.begin(), ByWeights.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ByWeights [i].IQ < ByWeights [j].IQ && ByWeights [j].Weight < ByWeights [i].Weight && dp [i] <= dp [j])
            {
                dp [i] = dp [j] + 1;
                indexes [i] = j;
                if (solution < dp [i])
                {
                    solution = dp [i];
                    solution_index = i;
                }
            }
        }
    }

    printf ("%d\n", solution);

    int current_index = solution_index;

    for (int i = 0; i < solution; i++)
    {
        SOLUTION.push_back (current_index);
        current_index = indexes [current_index];
    }

    for (int i = solution - 1; i > -1; i--)
        printf ("%d\n", ByWeights [SOLUTION [i]].position + 1);

    return 0;
}
/*
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
*/
