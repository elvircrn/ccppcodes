#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

vector <string> array [30000];
map <string, short> visited;
int n, m, SOLUTION;
string unos;
bool blackList [20000];
short Q;

int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &m);
        for (int j = 0; j < m; j++) {
            cin>>unos;
            array [i].push_back (unos);
            visited [array [i] [j]]++;
            cout<<array [i] [j]<<' '<<visited [array [i] [j]]<<endl;
        }
    }
    SOLUTION = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Q = visited [array [i] [j]];
            if (Q > 1) {
                SOLUTION--;
                break;
            }
        }
    }

    printf ("%d\n", SOLUTION);

    return 0;
}

