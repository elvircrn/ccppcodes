#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define INF 1<<28
#define ret dp [current_index] [remaining_time]

//first  lecture_count
//second dissatisfaction_index

int n, l, c, t [1011];


int get_dissatisfaction(int time_left)
{
    if (1 <= time_left && time_left <= 10)
        return -c;
    else if (time_left > 10)
        return (time_left - 10) * (time_left - 10);
    else
        return 0;
}

pair <int, int> dp [1100] [600];
pair <int, int> solution;

pair<int, int> min(const pair<int, int> &A, const pair<int, int> &B)
{
    return (A.first != B.first) ? ((A.first < B.first) ? A : B) : (A.second < B.second) ? A : B;
}

void print(const pair<int, int> &A)
{
    printf ("first: %d first: %d\n", A.first, A.second);
}

pair<int, int> solve (int current_index, int remaining_time)
{
    printf ("current_index: %d remaining_time: %d\n", current_index, remaining_time);

    pair <int, int> ret1(INF, INF), ret2(INF, INF);

    if (current_index == n - 1)
    {
        //if (remaining_time >= t [current_index])
        //{
            return ret1 = make_pair(0, get_dissatisfaction (remaining_time - t [current_index]));
        //ret2 = make_pair(1, get_dissatisfaction (l - t [current_index]));
        //}
        //else
            return make_pair(1, get_dissatisfaction(l - t [current_index]));

        //return min (ret1, ret2);
    }


    if (ret.first != INF)
        return ret;

    ret2 = solve (current_index + 1, l - t [current_index]);

    ret2.first++;
    ret2.second += get_dissatisfaction(remaining_time);

    if (remaining_time >= t [current_index])
    {
        ret1 = solve (current_index + 1, remaining_time - t [current_index]);

        return ret = min (ret1, ret2);
    }
    else
        return ret = ret2;
}

int main()
{
    freopen ("in.txt", "r", stdin);

    int test_id = 1;

    while (scanf ("%d", &n) == 1)
    {
        if (!n)
            break;

        if (n && test_id > 1)
            printf ("\n");

        scanf ("%d %d", &l, &c);
        for (int i = 0; i < n; i++)
            scanf ("%d", &t [i]);

        for (int i = 0; i <= 1099; i++)
            for (int j = 0; j <= 590; j++)
                dp [i] [j] = make_pair(INF, INF);

        solution = solve (0, l);

        printf ("Case %d:\nMinimum number of lectures: %d\nTotal dissatisfaction index: %d\n", test_id++, solution.first + 1, solution.second);
    }

    return 0;
}




























