#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
bool ajacency_matrix [1000] [1000], visited [1000];
vector <int> graph [1000];
int aa, bb, hash [1000], maxn, cnt, n, m;
string a, b, gradovi [1000], querry;
int find_index (string a) {
    int i;
    for (i = 0; i <= cnt; i++)
        if (gradovi [i] == a)
            return i;
    gradovi [cnt + 1] = a;
    cnt++;
    return i;
}
bool bfs (int x, int y) {
    for (int i = 0; i <= cnt; i++) visited [i] = false;
    int help;
    queue <int> Q;
    Q.push (x);
    while (!Q.empty()) {
        help = Q.front();
        if (help == y) return true;
        Q.pop();
        if (!visited [help]) {
            visited [help] = true;
            for (int i = 0; i < graph [help].size(); i++) {
                if (!visited [graph [help] [i]] && ajacency_matrix [help] [graph [help] [i]]) {
                    Q.push (graph [help] [i]);
                }
            }
        }
    }
    return false;
}
int main () {
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        aa = find_index (a);
        bb = find_index (b);
        graph [aa].push_back (bb);
        graph [bb].push_back (aa);
        ajacency_matrix [aa] [bb] = true;
        ajacency_matrix [bb] [aa] = true;
    }
    cin>>querry;
    while (querry != "X") {
        cin>>a>>b;
        aa = find_index (a);
        bb = find_index (b);
        if (querry == "N") {
            ajacency_matrix [aa] [bb] = false;
            ajacency_matrix [bb] [aa] = false;
        }
        else if (querry == "P") {
            ajacency_matrix [aa] [bb] = true;
            ajacency_matrix [bb] [aa] = true;
        }
        else {
            if (bfs (aa, bb)) cout<<"MOZE.\n";
            else cout<<"NE MOZE.\n";
        }
        cin>>querry;
    }
    return 0;
}
