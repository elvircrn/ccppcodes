/*
Problem link
Type: Graph - Single source shortest path
Algorithm:
    First run Floyd (or Dijkstra to every vertex n), for each vertex
    find the distance to the nearest station, get the max of those nearest station.

    For the vertex which is not a station, place a station there and run Dijkstra
    for that vertex. Recalculate the distance to the nearest station for each vertex
    by the distance array from the Dijkstra and update the for the "better max".
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int oo = 100000000;

bool isStation[maxn], visited[maxn];
int d[maxn][maxn];
int start[maxn],end[maxn],dist[maxn],nearest[maxn],tmp[maxn];

class Edge
{
public:
    int a,b,t;

    Edge() {}

    Edge(int aa, int bb, int tt): a(aa), b(bb), t(tt) {}

    bool operator<(const Edge& E) const { return (this->a<E.a); }
    bool operator>(const Edge& E) const { return (this->a>=E.a); }
};

class Vertex
{
public:
    int v;

    Vertex() {}
    Vertex(int vv): v(vv) {}

    bool operator<(const Vertex& V) const { return (dist[this->v]<dist[V.v]); }
    bool operator>(const Vertex& V) const { return (dist[this->v]>=dist[V.v]);}
};

vector<Edge> Elist;
priority_queue<Vertex, vector<Vertex>, greater<Vertex> > pq;
int n,f;

void readfile();
void Dijkstra(int s);
int process();

int main()
{
    freopen ("in.txt", "r", stdin);
    int ntest;
    string str;
    cin >> ntest;
    for (int test=1; test<=ntest; test++)
    {
        readfile();
        if (test>1) cout << endl;
        sort(Elist.begin(), Elist.end(), less<Edge>());
        start[Elist[0].a] = 0;
        for (unsigned int i=1; i<Elist.size(); i++)
            if (Elist[i].a!=Elist[i-1].a)
            {
                end[Elist[i-1].a] = i-1;
                start[Elist[i].a] = i;
            }
        end[Elist[Elist.size()-1].a] = Elist.size()-1;
        cout << process() << endl;
        Elist.clear();
    }
    return 0;
}

void readfile()
{
    cin >> f >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) d[i][j] = oo;
    for (int i=0; i<=n; i++)
    {
        isStation[i] = false;
        nearest[i] = oo;
        d[i][i] = 0;
    }
    int value;
    for (int i=1; i<=f; i++)
    {
        cin >> value;
        isStation[value] = true;
        nearest[value] = 0;
    }
    string line;
    getline(cin,line);
    while (true)
    {
        getline(cin,line);
        if (line=="" || cin.eof()) break;
        int value[3] = {0,0,0}, j = 0;
        for (unsigned int i=0; i<line.length(); i++)
            if (line[i]==' ') j++;
            else value[j] = value[j]*10+int(line[i])-48;
        Elist.push_back(Edge((value[0]),(value[1]),(value[2])));
        Elist.push_back(Edge((value[1]),(value[0]),(value[2])));
        d[value[0]][value[1]] = value[2];
        d[value[1]][value[0]] = value[2];
    }
}

void Dijkstra(int s)
{
    for (int i=1; i<=n; i++)
    {
        dist[i] = +oo;
        visited[i] = false;
    }
    dist[s] = 0;
    visited[s] = true;
    pq.push(Vertex(s));

    while(!pq.empty())
    {
        int u = pq.top().v; pq.pop();
        visited[u] = true;
        for (int i = start[u]; i<=end[u]; i++)
        {
            int v = Elist[i].b;
            if (!visited[v] && dist[v]>dist[u]+Elist[i].t)
            {
                dist[v] = dist[u]+Elist[i].t;
                pq.push(Vertex(v));
            }
        }
    }
}

int process()
{
    int result = 1,
        maxlen = 0,
        minlen = oo;

    //Floyd
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (d[i][j]>d[i][k]+d[k][j]) d[i][j] = d[i][k]+d[k][j];

    //Calculate nearest
    for (int i=1; i<=n; i++)
        if (!isStation[i])
        {
            for (int j=1; j<=n; j++)
                if (isStation[j] && d[i][j]<nearest[i]) nearest[i] = d[i][j];
            if (nearest[i]>maxlen) maxlen = nearest[i];
        }

    minlen = maxlen;
    for (int i=n; i>= 1; i--)
        if (!isStation[i])
        {
            isStation[i] = true;
            Dijkstra(i);    // Run Dijkstra
            maxlen = 0;
            for (int j=1; j<=n; j++) tmp[j] = nearest[j];
            tmp[i] = 0;
            for (int j=1; j<=n; j++)
                if (!isStation[j] && dist[j]<tmp[j]) tmp[j] = dist[j]; // update nearest
            for (int j=1; j<=n; j++)
                if (tmp[j]>maxlen) maxlen = tmp[j];
            if (maxlen<minlen)  // update better max
            {
                result = i;
                minlen = maxlen;
            }
            isStation[i] = false;
        }
    return(result);
}
