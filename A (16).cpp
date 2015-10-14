#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class exam
{
public:
    int a, b;

    exam() { }
    exam(int _a, int _b)
    {
        a = _a;
        b = _b;
    }
};

    bool operator< (const exam &B) const
    {
        if (a == B.a)
            return b < B.b;
        else
            return a < B.a;
    }
};

exam exams [5100];
int n;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        exams [i].get();

    sort (exams, exams + n);

    int current_day = exams [0].b;
    bool gate = false;

    for (int i = 1; i < n; i++)
    {
        if (current_day <= exams [i].b)
            current_day = exams [i].b;
        else
            current_day = exams [i].a;
    }

    printf ("%d\n", current_day);

    return 0;
}

/*
8
3 1
4 2
5 2
6 3
7 2
100 99
103 102
103 101
*/













































