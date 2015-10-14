#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct Job
{
    int priority, location;
    bool myJob;

    Job () { }
    Job (int _priority, int _location, bool _myJob) { priority = _priority; location = _location; myJob =_myJob; }

    bool operator < (const Job &B) const
    {
        if (priority != B.priority)
            return priority < B.priority;
        else
            return location < B.location;
    }
};

priority_queue <Job> jobs;
int t, A, n, m;

void clear_case()
{

}

int main ()
{

    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d %d", &n, &m);
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            scanf ("%d", &A);
            if (found == true)
                continue;

            jobs.push (Job (A, i, (i == m)));
        }

        for (int i = 0; i < n; i++)
        {
            Job J = jobs.top();
            jobs.pop();

            printf ("%d\n", J.priority);

            if (J.myJob == true)
            {
                printf ("%d %d\n", J.priority, i);
                break;
            }
        }
    }

    return 0;
}
/*
3
6 0
1 1 9 1 1 1
4 2
1 2 3 4
*/


