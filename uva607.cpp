#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define INF 1<<28

//first  lecture_count
//second dissatisfaction_index

int n, l, c, t [1001];


int get_index(int time_left)
{
    if (1 <= time_left && time_left <= 10)
        return -c;
    else if (time_left > 10)
        return (time_left - 10) * (time_left - 10);
    else
        return 0;
}

pair <int, int> dp [1001] [1001];
pair <int, int> solution;

pair<int, int> solve (int current_index, int remaining_time, int lecture_count)
{
    printf ("current_index: %d remaining_time: %d lecture_count: %d\n", current_index, remaining_time, lecture_count);


    if (current_index == n - 1)
    {
        if (remaining_time >= t [current_index])
        {
            if (solution.first > lecture_count || solution.first == lecture_count && solution.second > get_index(remaining_time - t [current_index]))
            {
                solution.first  = lecture_count;
                solution.second = get_index(remaining_time - t [current_index]);
            }

            return make_pair(lecture_count, get_index(remaining_time - t [current_index]));
        }
        else if (solution.first > lecture_count + 1 || solution.first == lecture_count && solution.second > get_index(remaining_time - t [current_index]))
        {
            solution.first  = lecture_count + 1;
            solution.second = get_index(remaining_time - t [current_index]);
        }

        return make_pair(lecture_count + 1, get_index(l - t [current_index]));
    }

    if (dp [current_index] [lecture_count].first != INF)
        return dp [current_index] [lecture_count];

    pair <int, int> solution(INF, INF), ret1(INF, INF), ret2(INF, INF);

    if (remaining_time >= t [current_index])
        ret1 = solve(current_index + 1, remaining_time - t [current_index], lecture_count);

    ret2 = solve(current_index + 1, l - t [current_index], lecture_count + 1);

    pair <int, int> ovaj;


    if (ret1.first < ret2.first)
        ovaj = ret1;
    else if (ret1.first > ret2.first)
        ovaj = ret2;
    else if (ret1.second < ret2.second)
        ovaj = ret1;
    else
        ovaj = ret2;

    if (dp [current_index] [remaining_time].first > ovaj.first || dp [current_index] [remaining_time].first == ovaj.first && dp [current_index] [remaining_time].second > ovaj.second)
        dp [current_index] [remaining_time] = ovaj;



    return dp [current_index] [remaining_time];
}

int main()
{
    freopen ("in.txt", "r", stdin);

    while (scanf ("%d", &n) == 1 && n)
    {
        scanf ("%d %d", &l, &c);
        for (int i = 0; i < n; i++)
            scanf ("%d", &t [i]);

        for (int i = 0; i <= 100; i++)
            for (int j = 0; j <= 100; j++)
                dp [i] [j] = make_pair(INF, INF);

        solution = make_pair(INF, INF);

        pair <int, int> sol = solve (0, l, 0);

        printf ("Minimum number of lectures: %d\nTotal dissatisfaction index: %d\n\n", sol.first, sol.second);
    }

    return 0;
}




























