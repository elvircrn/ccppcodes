#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

#define INF 999999999

/*struct edge
{
    int n, w;

    edge() { }
    edge(int _n, int _w) { n = _n; w = _w; }

    bool operator< (const edge &B) const
    {
        return w > B.w;
    }
};

vector <edge> graph [10000];*/
int v, start, eend, matrix [1001] [1001];

class SalesmansDilemma
{
public:
    string bestRoute(int towns, int origin, int destination, vector<string> travelCosts, vector <int> profits)
    {
        stringstream ss;
        start = origin;
        eend = destination;

        v = towns;

        int from, where, cost;

        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                matrix [i] [j] = -INF;

        matrix [start] [start] = 0;

        for (int i = 0; i < travelCosts.size(); i++)
        {
            sscanf (travelCosts [i].c_str(), "%d %d %d", &from, &where, &cost);
            matrix [from] [where] = max (profits [where] - cost, matrix [from] [where]);
        }

        for (int k = 0; k < v; k++)
            for (int i = 0; i < v; i++)
                for (int j = 0; j < v; j++)
                    if (matrix [i] [k] != -INF && matrix [k] [j] != -INF)
                        matrix [i] [j] = max (matrix [i] [k] + matrix [k] [j], matrix [i] [j]);

        for (int i = 0; i < v; i++)
            if (matrix [start] [i] != -INF && matrix [i] [eend] != -INF && matrix [i] [i] > 0)
            {
                printf ("i: %d\n", i);
                return "ENDLESS PROFIT";
            }

        if (matrix [start] [eend] == -INF)
            return "IMPOSSIBLE";

        ss<<"BEST PROFIT: "<<matrix [start] [eend] + profits [start];


        return ss.str();
    }
};
//{5, 0, 4, {"0 1 10", "1 2 10", "2 3 10", "3 1 10", "0 4 987654"}, {1000, 1000, 1000, 1000, 0}}
//153000 140000
int main()
{
    vector <string> A;
    vector <int>    B;

    A.push_back("0 1 10");
    A.push_back("1 2 10");
    A.push_back("2 3 10");
    A.push_back("3 1 10");
    A.push_back("0 4 987654");

    B.push_back(1000);
    B.push_back(1000);
    B.push_back(1000);
    B.push_back(0);

    SalesmansDilemma sd;

    cout<<sd.bestRoute(5, 0, 4, A, B)<<endl;

    return 0;
}











