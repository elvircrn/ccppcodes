#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#region
int myaps (int ss) {
    if (!ss) return (ss * (-1));
    else return
}
int calculate (mjesto one, baka two) {
    return (myaps (one.x - two.x) + myaps (one.y - two.y));
}
struct mjesto {
    int x, y;
    seat () {}
    seat (int _x, int _y) {x = _x; y = _y;}
} help1;
struct baka {
    int x, y;
    granny () {}
    granny (int _x, int _y) {x = _x; y = _y;}
} help2;
#endregion

bool bake [1000];
vector <mjesto> mjesta [1000];
vector <baka> bake [1000];
char bus [200] [200];
int lol [300] [300];
int n, m, explosions;
int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%s", &bus [i]);
        for (int j = 0; j < m; j++) {
            if (bus [i] [j] == 'L') mjesta.push_back (mjesto (i, j));
            else if (bus [i] [j] == 'X') bake.push_back (baka (i, j));
        }
    }
    for (int i = 0; i < mjesta.size(); i++) {
        help1 = mjesta [i];
        for (int j = 0; j < bake.size(); j++) {
            help2 = bake [j];
            int dist = calculate (help1, help2);
            lol [i] [dist]++;
        }
    }
    return 0;
}
