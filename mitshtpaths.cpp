#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long int ull;
struct edge
{
    ull n, w;
    edge () {}
    edge (ull _n, ull _w)
    {
        n = _n;
        w = _w;
    }

    bool operator < (const edge & x) const
    {
        return w > x.w;
    }
} help;

struct edge2
{
    ull m, n, w;
    edge2 () {}
    edge2 (ull _m, ull _n, ull _w) {m = _m; n = _n; w = _w;}

    bool operator < (const edge2 & x) const
    {
        return w > x.w;
    }
} help2;

priority_queue <edge2> Q;
vector <edge> graf [9000000];
ull d [9000000], e, v, prvi, a, parent [9000000], b, c, start, end;
bool visited [9000000];

ull dijkstra ()
{
    int eend = end + 1000001;
    Q.push (edge2 (start + 1000001, start + 1000001, 0));

    while (!Q.empty())
    {
        help2 = Q.top();
        Q.pop();

        if (!visited [help2.n])
        {
            visited [help2.n] = 1;
            d [help2.n] = help2.w;

            if (help.n == eend)
            {
                break;
            }

            for (ull i = 0; i < graf [help2.n].size(); i++)
                if (!visited [graf [help2.n] [i].n])
                    Q.push (edge2 (help2.n, graf [help2.n] [i].n, graf [help2.n] [i].w + d [help2.n]));

        }
   }

   if (!d [eend])
   {
        printf ("No path\n");
        exit (0);
   }
   return d [eend];
}
int main ()
{
    ull C, D;
    cin>>start>>end;
    ull as, sa;

    while (cin>>C)
    {
        scanf ("%lld", &D);
        as = C + 1000001;
        sa = D + 1000001;
        graf [as].push_back (edge (sa, (C + D) * (C + D)));
    }

    cout<<(dijkstra () - (start * start) + (end * end)) / 2<<endl;

    return 0;
}
