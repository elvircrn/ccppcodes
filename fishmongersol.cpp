#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

#define INF 1<<30

pair<int, int> memo [55] [1100];
int cities, total_time, travelTime [55] [1100], toll [55] [1100];

pair<int, int> go(int curCity, int time_left)
{
    if (time_left <= 0)
        return make_pair(INF, INF);
    if (curCity == cities - 1)
        return make_pair(0, 0);
    if (memo[curCity][time_left].first != -1)
        return memo[curCity][time_left];

    pair<int, int> answer = make_pair(INF, INF);

    for (int neighbor = 0; neighbor < cities; neighbor++)
    {
        if (curCity != neighbor)
        {
            pair<int, int> nextCity = go(neighbor,
                                         time_left - travelTime[curCity][neighbor]);

            if (nextCity.first + toll[curCity][neighbor] < answer.first)
            {
                answer.first = nextCity.first + toll[curCity][neighbor];
                answer.second = nextCity.second + travelTime[curCity][neighbor];
            }
        }
    }

    return memo[curCity][time_left] = answer;
}

int main ()
{
    scanf ("%d %d", &cities, &total_time);
    while (cities && total_time)
    {
        for (int i = 0; i <= total_time; i++)
            for (int j = 0; j <= total_time; j++)
                memo [i] [j] = make_pair(-1, -1);

        for (int i = 0; i < cities; i++)
            for (int j = 0; j < cities; j++)
                scanf ("%d", &travelTime [i] [j]);

        for (int i = 0; i < cities; i++)
            for (int j = 0; j < cities; j++)
                scanf ("%d", &toll [i] [j]);

        pair<int, int> solution = go (0, total_time);

        if (solution.first != INF && solution.second != INF)
            printf ("%d %d\n", solution.first, solution.second);
        else
            printf ("-1 -1\n");

        scanf ("%d %d", &cities, &total_time);
    }

    return 0;
}
/*
4 4
0 5 2 3
5 0 2 3
3 1 0 2
3 3 2 0

0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0
*/
