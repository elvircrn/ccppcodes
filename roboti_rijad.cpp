#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <iostream>
#include <utility>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
using namespace std;
const int INF=1<<29;
typedef long long lint;
typedef pair<int,int> ii;
struct edge
{
    int x,y;
    lint d;
    edge() {}
    edge(int _x,int _y,lint _d)
    {
        x=_x;
        d=_d;
        y=_y;
    }
    bool operator <(const edge &o)const
    {
        return d>o.d;
    }
};
vector<vector<lint> > dist;
vector<vector<edge> > ve;
priority_queue<edge> pq;
void dijkstra(int u)
{
    //printf("%d\n",u);
    while (!pq.empty())pq.pop();
    pq.push(edge(-1,u,0));
    dist[0][u]=0;
    edge tmp;
    lint neu;
    int ide;
    while (!pq.empty())
    {
        tmp=pq.top();
        pq.pop();
        if(dist[tmp.d%3][tmp.y]<tmp.d)continue;
        dist[tmp.d%3][tmp.y]=tmp.d;
        for(int i=0; i<ve[tmp.y].size(); i++)
        {
            neu=tmp.d+ve[tmp.y][i].d;
            ide=ve[tmp.y][i].y;
            //printf("%d %d\n",neu,ide);
            if(dist[neu%3][ide]>neu)
            {
                dist[neu%3][ide]=neu;
                pq.push(edge(-1,ide,neu));
            }
        }
    }
    return ;
}

int BrojMinimalnihPotrosnji(int r, int p, int q, int v, int e, int* en)
{
    //Ovdje napisite svoje rjesenje

    int a,b,c;
    ve.clear();
    ve.resize(v);
    for(int i=0; i<e; i++)
    {
        a=en[i*3];
        b=en[i*3+1];
        c=en[i*3+2];
        a--;
        b--;
        ve[a].pb(edge(a,b,c));
    }
    c=0;
    for(int i=0; i<v; i++)
    {
        dist.clear();
        dist.resize(3,vector<lint>(v,INF));
        dijkstra(i);
        for(int j=0; j<v; j++)
        {
            //printf("%d ",dist[r][j]);
            //if(i==j)continue;
            if(dist[r][j]>=p && dist[r][j]<=q)c++;
        }
        //puts("");
    }
    return c;
}

int main()
{
    freopen ("rijad.txt", "w", stdout);


    int r, p, q, v, e, asd [10000];
    for (int t = 0; t < 12; t++)
    {
        char input [12], output[12];

        sprintf (input, "input%d", t);
        sprintf (output, "rijad_out%d", t);

        FILE *in  = fopen (input, "r");
        FILE *out = fopen (output, "w");

        fscanf (in, "%d %d %d %d %d", &r, &p, &q, &v, &e);

        for (int i = 0; i < 3 * e; i++)
            fscanf (in, "%d", &asd [i]);

        fprintf (out, "%d\n", BrojMinimalnihPotrosnji(r, p, q, v, e, asd));

        fclose (in);
        fclose (out);
    }


    return 0;
}




