#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long int ull;

#define INF 1<<30

ull capacity [250] [250], parent [250];
vector <ull> graph [250];
bool visited [250];

class maximum_flow {

    public: ull e, v, source, sink, Maximum_Flow;

    private: void input () {
        ull A, B, C;
        scanf ("%lld %lld", &e, &v); source = 1; sink = v;
        for (ull i = 0; i < e; i++) {
            scanf ("%lld %lld %lld", &A, &B, &C);
            graph [A].push_back (B);
            graph [B].push_back (A);
            capacity [A] [B] += C;
        }
    }

    private: ull bfs () {

        memset (visited, false, sizeof visited);
        memset (parent, -1, sizeof parent);
        ull help;
        bool nasao = false;
        queue <ull> Q;
        Q.push (source);
        visited [source] = true;

        while (Q.empty() == false && nasao == false) {

            help = Q.front();
            Q.pop();

            for (ull i = 0; i < graph [help].size(); i++) {

                if (!visited [graph [help] [i]] && capacity [help] [graph [help] [i]]) {

                    visited [graph [help] [i]] = true;
                    Q.push (graph [help] [i]);
                    parent [graph [help] [i]] = help;

                    if (graph [help] [i] == sink) {nasao = true; break;}

                }
            }
        }

        ull BFS = INF, ind = sink;

        while (parent [ind] != -1) {
            BFS = min (BFS, capacity [parent [ind]] [ind]);
            ind = parent [ind];
        }

        ind = sink;

        while (parent [ind] != -1) {
            capacity [parent [ind]] [ind] -= BFS;
            capacity [ind] [parent [ind]] += BFS;
            ind = parent [ind];
        }

        return BFS == INF ? 0 : BFS;

    }

    public: maximum_flow () {

        Maximum_Flow = 0;
        memset (capacity, 0, sizeof capacity);

        input();

        ull x;
        while (x = bfs ()) Maximum_Flow += x;

    }

};

int main () {

    maximum_flow MF = maximum_flow ();

    printf ("%lld\n", MF.Maximum_Flow);

    return 0;
}
