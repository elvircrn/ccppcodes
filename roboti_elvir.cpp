#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int ll;

const ll INF = 1<<27;

ll matrix [200] [200];
ll dp [200] [200] [3];
ll solution, result;

int BrojMinimalnihPotrosnji(int r, int p, int q, int v, int e, int* energije)
{

    solution = 0;
    for (ll i = 0; i <= v; i++)
        for (ll j = 0; j <= v; j++)
        {
            matrix [i] [j] = -1;
            for (ll k = 0; k < 3; k++)
            {
                dp [i] [j] [k] = INF;
            }
        }

    for (ll i = 0; i < 3 * e; i += 3)
    {
        matrix [energije [i]] [energije [i + 1]] = energije [i + 2];
        dp [energije [i]] [energije [i + 1]] [energije [i + 2] % 3] = energije [i + 2];
    }

    for (ll k = 1; k <= v; k++)
    {
        for (ll i = 1; i <= v; i++)
        {
            for (ll j = 1; j <= v; j++)
            {

                for (ll l = 0; l < 3; l++)
                {
                    if (i == j && !l)
                    {
                        dp [i] [j] [0] = 0;
                        continue;
                    }

                    ll f = i;
                    ll w =  j;
                    if (l == 0)
                    {
                        dp [i] [j] [l] = min (min (dp [f] [k] [0] + dp [k] [w] [0], dp [f] [k] [1] + dp [k] [w] [2]),
                                         min (dp [f] [k] [2] + dp [k] [w] [1], dp [i] [j] [l]));
                    }
                    else if (l == 1)
                    {
                        dp [i] [j] [l] = min (min (dp [f] [k] [0] + dp [k] [w] [1], dp [f] [k] [1] + dp [k] [w] [0]),
                                         min (dp [f] [k] [2] + dp [k] [w] [2], dp [i] [j] [l]));
                    }
                    else if (l == 2)
                    {
                        dp [i] [j] [l] = min (min (dp [f] [k] [0] + dp [k] [w] [2], dp [f] [k] [2] + dp [k] [w] [0]),
                                         min (dp [f] [k] [1] + dp [k] [w] [1], dp [i] [j] [l]));
                    }
                }
            }
        }
    }

    for (ll i = 1; i <= v; i++)
        for (ll j = 1; j <= v; j++)
            if (p <= dp [i] [j] [r] && dp [i] [j] [r] <= q) //||
                //p <= dp [j] [i] [r] && dp [j] [i] [r] <= q)
                solution++;


    return solution;
}

int main()
{
    int r, p, q, v, e, asd [10000];
    for (int t = 0; t < 12; t++)
    {
        char input [12], output [12], rijad_out[12];

        sprintf (input, "input%d", t);
        sprintf (output, "output%d", t);
        sprintf (rijad_out, "rijad_out%d", t);

        FILE *in = fopen (input, "r"), *in2 = fopen (output, "r"), *o1 = fopen (rijad_out, "r");

        fscanf (in, "%d %d %d %d %d", &r, &p, &q, &v, &e);

        for (int i = 0; i < 3 * e; i++)
            fscanf (in, "%d", &asd [i]);

        int a = BrojMinimalnihPotrosnji(r, p, q, v, e, asd);

        fclose (in);

        in = fopen (output, "r");

        int zvanicno;

        fscanf (in2, "%d", &zvanicno);

        int rjd;

        fscanf (o1, "%d", &rjd);

        printf ("ja: %d zvanicno: %d rijad: %d ", a, zvanicno, rjd);

        if (a == rjd)
        {
            printf ("Test case %d OK\n", t);
            result++;
        }

        else
            printf ("Test case %d NOT OK\n", t);

        fclose (in2);

        fclose (o1);
    }

    printf ("passed: %d\n", result);


    return 0;
}

















