#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

long long int n, m, k, solution;
bool used[50100];

struct queue_element
{
    long long int index, value;

    queue_element() { }
    queue_element(long long int _index, long long int _value) { index = _index; value = _value; }
};

struct greater_first
{
    bool operator() (const queue_element &A, const queue_element &B)
    {
        return A.value < B.value;
    }
};

struct lesser_first
{
    bool operator() (const queue_element &A, const queue_element &B)
    {
        return A.value > B.value;
    }
};

vector <pair <long long int, long long int> > cows;

priority_queue <queue_element, vector<queue_element>, lesser_first> cheap;
priority_queue <queue_element, vector<queue_element>, lesser_first> expensive;
priority_queue <queue_element, vector<queue_element>, greater_first> recover;

int main()
{
    scanf ("%lld %lld %lld", &n, &k, &m);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf ("%lld %lld", &a, &b);
        cows.push_back(make_pair(a, b));
    }

    for (int i = 0; i < n; i++)
    {
        expensive.push(queue_element(i, cows[i].first));
        cheap.push(queue_element(i, cows[i].second));
    }

    while(k--)
        recover.push(queue_element(0, 0));

    while (m > 0 && solution < n)
    {
        while (used[expensive.top().index])
            expensive.pop();
        while (used[cheap.top().index])
            cheap.pop();

        if (recover.top().value + cheap.top().value < expensive.top().value)
        {
            long long int index = cheap.top().index;
            long long int cost = recover.top().value + cheap.top().value;

            if (m < cost)
                break;

            m -= cost;

            used [index] = true;
            recover.push(queue_element(0, cows[index].first - cows[index].second));
            recover.pop();
            cheap.pop();
        }
        else
        {
            long long int index = expensive.top().index;
            long long int cost  = expensive.top().value;

            if (m < cost)
                break;

            used[index] = true;
            m -= cost;
            expensive.pop();
        }

        solution++;
    }

    printf ("%lld\n", solution);

    return 0;
}


































