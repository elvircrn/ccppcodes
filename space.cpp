#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int n, m, solution;

struct vector2
{
    int x, y;

    bool planet;

    vector2() { x = 0; y = 0; }

    void get(bool _planet)
    {
        planet = _planet;
        scanf ("%d %d", &x, &y);
    }

    bool operator< (const vector2 &B) const
    {
        return (x != B.x) ? (x < B.x) : (y < B.y);
    }

    void set(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void print()
    {
        printf ("x: %d y: %d\n", x, y);
    }

    int dot_product(const vector2 &B) const
    {
        return x * B.y - y * B.x;
    }
};

vector2 comp_a, comp_b, global, objects[2100];

bool cmp(const vector2 &A, const vector2 &B)
{
    comp_a.set(A.x - global.x, A.y - global.y);
    comp_b.set(B.x - global.x, B.y - global.y);

    return comp_a.x * comp_b.y < comp_a.y * comp_b.x;
}

vector <vector2> ob2;
vector <vector2> ob3;

#define DEBUG

int main()
{
    freopen ("in.txt", "r", stdin);

    vector2 A, B, C, D;

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++)
        objects [i].get(i < n);

    sort (objects, objects + (n + m));

    for (int i = 0; i < (n + m) - 1; i++)
    {
        if (objects [i].planet)
        {
            global = objects [i];

            A = global;

            #ifdef DEBUG

            printf ("global: ");
            global.print();

            #endif

            ob2.clear();
            for (int j = i + 1; j < (n + m); j++)
                ob2.push_back (objects [j]);

            sort (ob2.begin(), ob2.end(), cmp);

            #ifdef DEBUG
            for (int j = 0; j < ob2.size(); j++)
                ob2 [j].print();
            #endif

            bool found(false);

            for (int j = 0; j < ob2.size() - 1; j++)
            {
                B = ob2 [j];

                if (!B.planet)
                    continue;

                global = B;

                ob3.clear();

                for (int k = j + 1; k < ob2.size(); k++)
                    ob3.push_back (ob2 [k]);

                sort (ob3.begin(), ob3.end(), cmp);

                printf (" ob3:\n");
                for (int k = 0; k < ob3.size(); k++)
                {
                    printf ("   ");
                    ob3 [k].print();
                }

                for (int k = 0; k < ob3.size(); k++)
                {
                    D = ob3 [k];

                    if (D.planet && !found)
                        solution++;
                    else if (D.planet)
                    {
                        vector2 V1, V2;
                        V1.set(C.x - B.x, C.y - B.y);
                        V2.set(D.x - B.x, D.y - B.y);

                        float product = V1.dot_product(V2);

                        if (product < 0)
                            solution++;
                    }
                    else
                    {
                        if (!found)
                            C = D;
                        else
                        {
                            vector2 V1, V2;
                            V1.set(C.x - B.x, C.y - B.y);
                            V2.set(D.x - B.x, D.y - B.y);

                            float product = V1.dot_product(V2);

                            if (product < 0)
                                C = D;
                        }

                        found = true;
                    }
                }

                printf ("sol: %d\n", solution);
            }
        }
    }

    printf ("%d\n", solution);

    return 0;
}
/*
0 1
1 1
2 1
-2 1
-1 1
*/










