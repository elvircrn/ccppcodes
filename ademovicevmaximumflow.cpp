#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[50];
int c[50][50];
int visited[50],parent[50];
int maximumFlow(int source,int sink);
int findPath(int source,int sink);
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);

    int v1,v2,ccc;
    memset(c,0,sizeof c);
    memset(visited,0,sizeof visited);
    for(int i=0;i<e;i++)
    {
            scanf("%d %d %d",&v1,&v2,&ccc);
            v[v1].push_back(v2);
            v[v2].push_back(v1);
            c[v1][v2]=ccc;
    }
    int source,sink;
    scanf("%d %d",&source,&sink);
    int rj=maximumFlow(source,sink);
    cout<<rj<<endl;
    return 0;
}

int maximumFlow(int source,int sink)
{
    int mf=0,t(1);
    while(t)
    {
              t=findPath(source,sink);
              mf+=t;
    }
    return mf;
}
int findPath(int source,int sink)
{
    queue<int>q;
    bool going(true);
    memset(parent,-1,sizeof parent);
    memset(visited,0,sizeof visited);
    int tmp;
    q.push(source);
    visited[source]=1;
    while(going && !q.empty())
    {
                     tmp=q.front();q.pop();
                                      for(int i=0;i<v[tmp].size();i++)
                                      {
                                              if(!visited[v[tmp][i]])
                                              if(c[tmp][v[tmp][i]])
                                              {
                                                                   visited[v[tmp][i]]=1;
                                                                   q.push(v[tmp][i]);
                                                                   parent[v[tmp][i]]=tmp;
                                                                   if(v[tmp][i]==sink)
                                                                   {
                                                                       going = false;
                                                                       break;
                                                                   }
                                              }
                                      }
    }
    int ppp=99999999;
    tmp=sink;
    int prev;
    while(parent[tmp]!=-1)
    {
             prev=parent[tmp];
             ppp=min(ppp,c[prev][tmp]);
             tmp=prev;
    }

    tmp=sink;
    while(parent[tmp]!=-1)
    {
                              prev=parent[tmp];
                              c[prev][tmp]-=ppp;
                              c[tmp][prev]+=ppp;
                              tmp=prev;
    }
    if(ppp==99999999) return 0;
    return ppp;
}
/*
7 8
0 1 3
0 2 1
1 3 3
2 3 5
2 4 4
4 5 2
5 6 3
3 6 3
0 6
*/
