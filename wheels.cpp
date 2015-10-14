#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct Number
{
    int digits [5];

    Number () { }
    Number (int number)
    {
        digits [3] = number % 10;
        digits [2] = (number / 10) % 10;
        digits [1] = (number / 100) % 10;
        digits [0] = number / 1000;
    }
    Number (int a, int b, int c, int d)
    {
        digits [0] = a;
        digits [1] = b;
        digits [2] = c;
        digits [3] = d;
    }

    int& operator [] (int index)
    {
        return digits [index];
    }

    bool operator == (const Number &B) const
    {
        for (int i = 0; i < 4; i++)
            if (B.digits [i] != digits[i])
                return false;

        return true;
    }

    int GetNumber()
    {
        return digits [0] * 1000 + digits [1] * 100 + digits [2] * 10 + digits [3];
    }

    void Input()
    {
        for (int i = 0; i < 4; i++)
            scanf ("%d", &digits [i]);
    }

    void Print()
    {
        printf ("%d", GetNumber());
    }
};

Number start, end;
Number numbers [20000];
bool visited [20000];
int t, n, d [20000];

int bfs ()
{
    queue <Number> Q;
    Q.push (start);

    while (!Q.empty())
    {
        Number help = Q.front();
        //help.Print(); printf ("\n");
        Number CPY = help;
        Q.pop();

        if (!visited [help.GetNumber()])
        {
            visited [help.GetNumber()] = true;

            if (help == end)
            {
                //cout<<"akoasdo: "<<d [end.GetNumber()]<<endl;
                return d [end.GetNumber()];
            }

            for (int i = 0; i < 4; i++)
            {
                CPY = help;

                //POSITIVE
                CPY.digits [i]++;
                CPY.digits [i] %= 10;

                if (!visited [CPY.GetNumber()])
                {
                    d [CPY.GetNumber()] = d [help.GetNumber()] + 1;
                    Q.push (CPY);
                }

                CPY = help;

                //NEGATIVE
                CPY.digits [i] --;
                if (CPY.digits [i] < 0)
                    CPY.digits [i] = 9;

                if (!visited [CPY.GetNumber()])
                {
                    d [CPY.GetNumber()] = d [help.GetNumber()] + 1;
                    Q.push (CPY);
                }
            }
        }
    }

    return -1;
}

void clear_case()
{
    memset (visited, false, sizeof visited);
    memset (d, 0, sizeof d);
}

int main ()
{
    scanf ("%d", &t);

    while (t--)
    {
        clear_case();

        start.Input();
        end.Input();

        scanf ("%d", &n);

        for (int i = 0; i < n; i++)
        {
            numbers [i].Input();
            visited [numbers [i].GetNumber()] = true;
        }

        int solution = bfs ();

        printf ("%d\n", solution);
    }

    return 0;
}

/*
1
0 0 0 0
1 0 0 0
0
*/









