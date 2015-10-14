#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <climits>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;

//#define RIJAD //n dijkstri
#define OFC //floyd warshall


#ifdef RIJAD
const int INF=1<<29;
typedef long long lint;
typedef pair<int,int> ii;
struct edge
{
    int x,y;
    lint d;
    edge(){}
    edge(int _x,int _y,lint _d){x=_x;d=_d;y=_y;}
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
        tmp=pq.top();pq.pop();
        if(dist[tmp.d%3][tmp.y]<tmp.d)continue;
        dist[tmp.d%3][tmp.y]=tmp.d;
        for(int i=0;i<ve[tmp.y].size();i++)
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

int BrojMinimalnihPotrosnji(int r, int p, int q, int v, int e, int* en) {
        //Ovdje napisite svoje rjesenje

        int a,b,c;
        ve.clear();
        ve.resize(v);
        for(int i=0;i<e;i++)
        {
            a=en[i*3];b=en[i*3+1];c=en[i*3+2];
            a--;b--;
            ve[a].pb(edge(a,b,c));
        }
        c=0;
        for(int i=0;i<v;i++)
        {
            dist.clear();
            dist.resize(3,vector<lint>(v,INF));
            dijkstra(i);
            for(int j=0;j<v;j++)
            {
                //printf("%d ",dist[r][j]);
                //if(i==j)continue;
                if(dist[r][j]>=p && dist[r][j]<=q)c++;
            }
            //puts("");
        }
        return c;
}
#endif // RIJAD
#ifdef OFC
void FloydWarshall (int number_of_vertexes, int number_of_edges, vector<vector<int> > &lengths_solution_label0, vector<vector<int> > &lengths_solution_label1, vector<vector<int> > &lengths_solution_label2, const vector<vector<int> > &graph_matrix)
{
    for (int i = 0; i < number_of_vertexes; i++)
        lengths_solution_label0[i][i] = 0;
    for (int i = 0; i < number_of_edges; i++)
    {
        if (graph_matrix[i][2] < lengths_solution_label0[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] && graph_matrix[i][2] % 3 == 0) lengths_solution_label0[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] = graph_matrix[i][2];
        if (graph_matrix[i][2] < lengths_solution_label1[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] && graph_matrix[i][2] % 3 == 1) lengths_solution_label1[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] = graph_matrix[i][2];
        if (graph_matrix[i][2] < lengths_solution_label2[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] && graph_matrix[i][2] % 3 == 2) lengths_solution_label2[graph_matrix[i][0] - 1][graph_matrix[i][1] - 1] = graph_matrix[i][2];
    }
    /*dodano*/
    for(int f_1=0;f_1<5;f_1++)
    /*kraj dodanog*/
    for (int k = 0; k < number_of_vertexes; k++)
        for (int i = 0; i < number_of_vertexes; i++)
            for (int j = 0; j < number_of_vertexes; j++)
            {
                if(lengths_solution_label0[i][k] + lengths_solution_label0[k][j] < lengths_solution_label0[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label0[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label0[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label0[k][j] < lengths_solution_label1[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label0[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label0[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label0[k][j] < lengths_solution_label2[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label0[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label0[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label1[k][j] < lengths_solution_label0[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label1[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label0[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label1[k][j] < lengths_solution_label1[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label1[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label0[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label1[k][j] < lengths_solution_label2[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label1[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label0[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label2[k][j] < lengths_solution_label0[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label2[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label0[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label2[k][j] < lengths_solution_label1[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label2[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label0[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label0[i][k] + lengths_solution_label2[k][j] < lengths_solution_label2[i][j] && lengths_solution_label0[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label0[i][k] + lengths_solution_label2[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label0[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label0[k][j] < lengths_solution_label0[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label0[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label1[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label0[k][j] < lengths_solution_label1[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label0[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label1[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label0[k][j] < lengths_solution_label2[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label0[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label1[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label1[k][j] < lengths_solution_label0[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label1[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label1[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label1[k][j] < lengths_solution_label1[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label1[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label1[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label1[k][j] < lengths_solution_label2[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label1[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label1[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label2[k][j] < lengths_solution_label0[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label2[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label1[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label2[k][j] < lengths_solution_label1[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label2[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label1[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label1[i][k] + lengths_solution_label2[k][j] < lengths_solution_label2[i][j] && lengths_solution_label1[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label1[i][k] + lengths_solution_label2[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label1[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label0[k][j] < lengths_solution_label0[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label0[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label2[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label0[k][j] < lengths_solution_label1[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label0[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label2[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label0[k][j] < lengths_solution_label2[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label0[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label0[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label2[i][k] + lengths_solution_label0[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label1[k][j] < lengths_solution_label0[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label1[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label2[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label1[k][j] < lengths_solution_label1[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label1[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label2[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label1[k][j] < lengths_solution_label2[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label1[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label1[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label2[i][k] + lengths_solution_label1[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label2[k][j] < lengths_solution_label0[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label2[k][j]) % 3 == 0) lengths_solution_label0[i][j] = lengths_solution_label2[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label2[k][j] < lengths_solution_label1[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label2[k][j]) % 3 == 1) lengths_solution_label1[i][j] = lengths_solution_label2[i][k] + lengths_solution_label2[k][j];
                if(lengths_solution_label2[i][k] + lengths_solution_label2[k][j] < lengths_solution_label2[i][j] && lengths_solution_label2[i][k]!=INT_MAX && lengths_solution_label2[k][j]!=INT_MAX && (lengths_solution_label2[i][k] + lengths_solution_label2[k][j]) % 3 == 2) lengths_solution_label2[i][j] = lengths_solution_label2[i][k] + lengths_solution_label2[k][j];
            }
}

int Paths (int remainder, int lower_bound, int upper_bound, int number_of_vertexes, int number_of_edges, const vector<vector<int> > &graph_matrix)
{
    vector<vector<int> > lengths_solution_label0 (number_of_vertexes, vector<int>(number_of_vertexes, INT_MAX)), lengths_solution_label1 (number_of_vertexes, vector<int>(number_of_vertexes, INT_MAX)), lengths_solution_label2 (number_of_vertexes, vector<int>(number_of_vertexes, INT_MAX));
    FloydWarshall (number_of_vertexes, number_of_edges, lengths_solution_label0, lengths_solution_label1, lengths_solution_label2, graph_matrix);
    int counter (0);
    if (remainder == 0)
    {
        for (int i = 0; i < number_of_vertexes; i++)
            for (int j = 0; j < number_of_vertexes; j++)
                if (lengths_solution_label0[i][j] >= lower_bound && lengths_solution_label0[i][j] <= upper_bound) counter++;
    }
    if (remainder == 1)
    {
        for (int i = 0; i < number_of_vertexes; i++)
            for (int j = 0; j < number_of_vertexes; j++)
                if (lengths_solution_label1[i][j] >= lower_bound && lengths_solution_label1[i][j] <= upper_bound) counter++;
    }
    if (remainder == 2)
    {
        for (int i = 0; i < number_of_vertexes; i++)
            for (int j = 0; j < number_of_vertexes; j++)
                if (lengths_solution_label2[i][j] >= lower_bound && lengths_solution_label2[i][j] <= upper_bound) counter++;
    }
    return counter;
}

int BrojMinimalnihPotrosnji(int r, int p, int q, int v, int e, int* energije)
{
    vector<vector<int> > graph_matrix(e, vector<int>(3));
    for (int i = 0; i < e * 3; i += 3)
    {
        graph_matrix[i / 3][0] = energije[i];
        graph_matrix[i / 3][1] = energije[i + 1];
        graph_matrix[i / 3][2] = energije[i + 2];
    }
    return Paths (r, p, q, v, e, graph_matrix);
}
#endif

int main()
{
    int r,p,q,v,e;
    scanf("%d %d %d %d %d",&r,&p,&q,&v,&e);
    int ener[3*e+5];
    for(int i=0;i<3*e;i++)scanf("%d",&ener[i]);
    printf("%d\n",BrojMinimalnihPotrosnji(r,p,q,v,e,ener));
    return 0;
}
