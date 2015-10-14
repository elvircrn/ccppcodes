#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct segment
{
    int l, r;

    segment () { }
    segment (int _l, int _r) { l = _l; r = _r; }

    bool operator < (const segment &B) const
    {
        if (l != B.l)
            return l < B.l;
        else
            return r > B.r;
    }

    void print()
    {
        printf ("%d %d\n", l, r);
    }
};

vector <segment> segments;
vector <segment> solution;
int a, b, t, m;

void clear_case()
{
    segments.clear();
    solution.clar();
}

int main ()
{
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &m);
        scanf ("%d %d", &a, &b);

        bool nasao = false;

        while (a != 0 || b != 0)
        {
            if (b >= 0)
            {
                if (a < 0)
                    a = 0;

                if (b >= m)
                    nasao = true;

                segments.push_back (segment (a, b));
            }
            scanf ("%d %d", &a, &b);
        }

        if (nasao)
        {
            printf ("0\n");
            continue;
        }

        sort (segments.begin(), segments.end());

        if (segments [0].l != 0)
            continue;

        int far_right = segments [0].r;
        segment far_right_segment = segments [0];
        solution.push_back (far_right_segment);

        int i = 1;

        while (far_right < m)
        {
            while (segments [i].l > far_right)
            {

                i++;
            }
        }

        clear_case();
    }

    return 0;
}










