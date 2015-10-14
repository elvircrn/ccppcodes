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

#define INF 1<<27
#define INFF 1<<27 - 1

int capacity [2010] [2010], parent [2010];
vector <int> graph [2010];
bool visited [2010];

class maximum_flow {

    public: int e, v, source, sink, Maximum_Flow;
    private: bool visited [2010];

    private: void input () {

        int maxH = 0, k, x, tokens, clubs; e = 0; source = 0; sink = 2009;
        scanf ("%d %d", &tokens, &clubs);

        for (int i = 1; i <= tokens; i++) {

            graph [source].push_back (i);
            graph [i].push_back (source);
            capacity [source] [i] = 1;

            scanf ("%d", &k);

            for (int j = 0; j < k; j++) {

                scanf ("%d", &x);

                graph [i].push_back (x);
                graph [x + tokens + 1].push_back (i);
                capacity [i] [x + tokens + 1] = 1;
                capacity [x + tokens + 1] [sink] = 1;

                if (!visited [x]) {visited [x] = true; graph [x].push_back (sink);}

            }
        }

        return;

    }

    private: int bfs () {

        memset (visited, false, sizeof visited);
        memset (parent, -1, sizeof parent);
        int help;
        bool nasao = false;
        queue <int> Q;
        Q.push (source);
        visited [source] = true;

        while (Q.empty() == false && nasao == false) {

            help = Q.front();
            Q.pop();

            for (int i = 0; i < graph [help].size(); i++) {

                if (!visited [graph [help] [i]] && capacity [help] [graph [help] [i]]) {

                    visited [graph [help] [i]] = true;
                    Q.push (graph [help] [i]);
                    parent [graph [help] [i]] = help;

                    if (graph [help] [i] == sink) {nasao = true; break;}

                }
            }
        }

        int BFS = INF, ind = sink;

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

        int x;
        while (x = bfs ()) Maximum_Flow += x;

    }

};

int main () {

    maximum_flow MF = maximum_flow ();

    printf ("%d\n", MF.Maximum_Flow);

    return 0;
}
