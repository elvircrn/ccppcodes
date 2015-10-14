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
#define toll first
#define time second
#define edge pair<int, int>

/*struct edge
{
    int toll, time;

    edge() { }
    edge(int _toll, int _time) { toll = _toll; time = _time; }

    bool operator < (const edge &B) const
    {
        return toll < B.toll;
    }

    bool operator > (const edge &B) const
    {
        return toll > B.toll;
    }

    bool operator <= (const edge &B) const
    {
        return toll <= B.toll;
    }

    bool operator >= (const edge &B) const
    {
        return toll >= B.toll;
    }

    bool operator == (const edge &B) const
    {
        return toll == B.toll;
    }

    void print()
    {
        printf ("%d %d\n", toll, time);
    }
};*/

edge matrix [55] [1100], memo [55] [1100];
int cities, total_time;

edge solve (int current_city, int time_left)
{
    if (time_left < 0)
        return edge (INF, INF);
    if (current_city == cities - 1)
        return edge (0, 0);
    if (memo [current_city] [time_left].toll != -1)
        return memo [current_city] [time_left];


    edge answer = edge(INF, INF);

    for (int i = 0; i < cities; i++)
    {
        if (current_city == i)
            continue;

        edge next_city = solve (i, time_left - matrix [current_city] [i].time);

        if (next_city.toll + matrix [current_city] [i].toll < answer.toll)
            answer = edge(next_city.toll + matrix [current_city] [i].toll,
                          next_city.time + matrix [current_city] [i].time);
    }

    return memo [current_city] [time_left] = answer;
}

void clear_case()
{

}

int main ()
{
    scanf ("%d %d", &cities, &total_time);
    while (cities && total_time)
    {
        for (int i = 0; i <= total_time; i++)
            for (int j = 0; j <= total_time; j++)
                memo [i] [j] = edge(-1, -1);

        for (int i = 0; i < cities; i++)
            for (int j = 0; j < cities; j++)
            {
                matrix [i] [j] = edge();
                scanf ("%d", &matrix [i] [j].time);
            }

        for (int i = 0; i < cities; i++)
            for (int j = 0; j < cities; j++)
                scanf ("%d", &matrix [i] [j].toll);

        pair<int, int> solution = solve (0, total_time);

        if (solution.toll != INF && solution.time != INF)
            printf ("%d %d\n", solution.toll, solution.time);
        else
            printf ("-1 -1\n");

        scanf ("%d %d", &cities, &total_time);
    }

    return 0;
}
/*
4 1
0 5 2 3
5 0 2 3
3 1 0 2
3 3 2 0

0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0
*/
