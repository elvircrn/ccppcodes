#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1<<27

int dp [1000000];

class NewCoins
{
public:
    int minCoins(vector <int> prices)
    {
        int maximum = prices [max_element (prices.begin(), prices.end()) - prices.begin()];

        for (int i = 2; i <= maximum; i++)
            dp [i] = INF;

        int solution = INF;

        dp [1] = 0;

        for (int b = 1; b <= maximum; b++)
        {
            for (int a = b + b; a <= maximum; a += b)
            {
                int cnt(0);
                for (int i = 0; i < prices.size(); i++)
                    cnt += (prices [i] % a) / b;

                dp [a] = min (dp [a], dp [b] + cnt);

                //solution = min (dp [a], solution);
            }
        }

        for (int i = 2; i <= maximum; i++)
        {
            for (int j = 0; j < prices.size(); j++)
            {
                dp [i] += prices [j] / i;
            }

            solution = min (dp [i], solution);
        }

        if (solution == INF)
            return prices.size();
        else
            return solution;
    }
};

int main()
{
    int array[16] = {28, 569, 587, 256, 15, 87, 927, 4, 589, 73, 98, 87, 597, 163, 6, 498};

    vector <int> prices (array, array + 16);

    prices.clear();

    prices.push_back (1);

    NewCoins newCoins;

    printf ("%d\n", newCoins.minCoins(prices));

    return 0;
}
/*

*/









