#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>
#include <utility>
#include <cstdlib>

using namespace std;

struct tacka{
    int n;

    tacka(){}
    tacka(int _n){n = _n;}
};

vector <tacka> graph[1000];
bool visited[1000];

void dfs(int current)
{
    cout<<current;
    visited[current]=true;
    for(int i = 0; i < graph[current].size(); i++)
    {
        if(!visited[graph[current][i].n]){
            dfs(graph[current][i].n);
        }
    }
}
int vertices,a,b;

int main()
{
    scanf("%d", &vertices);
    for(int i = 0; i < vertices; i++){
        scanf("%d %d", &a, &b);
        graph[a].push_back(tacka(b));
        graph[b].push_back(tacka(a));
    }
    dfs(1);
    return 0;
}

