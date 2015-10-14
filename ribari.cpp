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

int capacity [1010] [1010], parent [1010];
vector <int> graph [1010];

class maximum_flow {

    public: int e, v, source, sink, Maximum_Flow;
    private: bool visited [1010];

    private: void input () {

        int k, x, tokens, clubs; e = 0; source = 0;
        scanf ("%d %d", &tokens, &clubs);

        for (int i = 1; i <= tokens; i++) {
            graph [0].push_back (i);
            capacity [0] [i] = INF;
        }

        for (int i = tokens + 1; i <= tokens + clubs; i++) {
            capacity [i] [tokens + clubs + 1] = 1;
            graph [i].push_back (tokens + clubs + 1);
        }

        sink = tokens + clubs + 1;

        for (int i = 1; i <= tokens; i++) {
            scanf ("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf ("%d", &x);
                graph [i].push_back (x + tokens);
                capacity [i] [x + tokens] = 1;
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
