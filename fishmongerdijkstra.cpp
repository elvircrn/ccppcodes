#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

struct edge
{
    int time, cost, current_node;

    edge() { }
    edge(int _time, int _cost, int _current_node) { time = _time; cost = _cost; current_node = _current_node; }

    bool operator < (const edge &B) const
    {
        if (time == B.time)
            return time > B.time;
        else
            return cost > B.cost;
    }
};

int main ()
{
    return 0;
}









