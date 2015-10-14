#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair <int, int> > cows;
int solution, n, a, b, counter;

int main()
{
    scanf ("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++)
    {
        char color[2];
        int x;

        scanf ("%s %d", &color, &x);
        cows.push_back(make_pair(x, color[0] == 'S'));
        counter += (color[0] == 'S');
    }

    sort(cows.begin(), cows.end());

    if (cows[cows.size() - 1].first != b && cows[cows.size() - 1].second)
    {
        cows.push_back(make_pair(b, 1));
        solution++;
    }

    for (int i = 0; i < cows.size() - 1; i++)
    {
        if (i == 0 && cows[i].second)
            solution += (cows[i].first - a);

        if (cows[i].second)
        {
            if (!cows[i + 1].second)
                solution += (cows[i + 1].first - cows[i].first) / 2;
            else
                solution += ((cows[i + 1].first - cows[i].first) - 1);
        }
        else if (cows[i + 1].second)
            solution += (cows[i + 1].first - cows[i].first) / 2;
    }

    printf ("%d\n", solution + counter);

    return 0;
}
/*
2 1 11
S 7
NS 4

3 1 13
S 1
NS 4
S 10

3 1 15
S 1
S 4
S 10
*/













































