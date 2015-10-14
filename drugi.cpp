#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
char names [300] [30];
int solutionp [1000], solutionhelp = 0, maxpizza, maxtaxi, maxgirl;
struct prijatelj {
    int nameind, pizza, taxi, girl;
    prijatelj () {pizza = taxi = girl = 0;}
    prijatelj (int _ind) {pizza = taxi = girl = 0; nameind = _ind;}
} prijatelji [1000];
struct pizza {
    int val, ind;
    pizza () {}
    pizza (int _v, int _i) {val = _v; ind = _i;}
    bool operator < (const pizza & xx) const
    {
        if (val == xx.val) return ind > xx.ind;
        return val < xx.val;
    }
} h;
struct taxi {
    int val, ind;
    taxi () {}
    taxi (int _v, int _i) {val = _v; ind = _i;}
    bool operator < (const taxi & xx) const
    {
        if (val == xx.val) return ind > xx.ind;
        return val < xx.val;
    }
} hh;
struct girl {
    int val, ind;
    girl () {}
    girl (int _v, int _i) {val = _v; ind = _i;}
    bool operator < (const girl & xx) const
    {
        if (val == xx.val) return ind > xx.ind;
        return val < xx.val;
    }
} hhh;
priority_queue <pizza> P;
priority_queue <taxi> T;
priority_queue <girl> G;
int n, s, jedan, dva, tri;
int main () {
    //freopen ("out.txt", "w", stdout);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %s", &s, &names [i]);
        prijatelji [i] = prijatelj (i);
        for (int j = 0; j < s; j++) {
            scanf ("%d-%d-%d", &jedan, &dva, &tri);
            if (jedan == dva && dva == tri && jedan == tri) prijatelji [i].taxi++;
            else if (jedan / 10 > jedan % 10 && jedan % 10 > dva / 10 && dva / 10 > dva % 10 && tri / 10 > tri % 10) prijatelji [i].pizza++;
            else prijatelji [i].girl++;
        }
        P.push (pizza (prijatelji [i].pizza, i));
        T.push (taxi (prijatelji [i].taxi, i));
        G.push (girl (prijatelji [i].girl, i));
    }
    h = P.top();
    hh = T.top();
    hhh = G.top();
    maxpizza = h.val, maxtaxi = hh.val, maxgirl = hhh.val;
    int ddd = 0;
    printf ("If you want to call a taxi, you should call:");
    while (hh.val == maxtaxi) {
        if (ddd >= 1) printf (",");
        printf (" %s", names [hh.ind]);
        T.pop();
        hh = T.top();
        ddd++;
    }
    printf (".\n");
    printf ("If you want to order a pizza, you should call:");
    ddd = 0;
    while (h.val == maxpizza) {
        if (ddd >= 1) printf (",");
        printf (" %s", names [h.ind]);
        P.pop();
        h = P.top();
        ddd++;
    }
    printf (".\n");
    printf ("If you want to go to a cafe with a wonderful girl, you should call:");
    ddd = 0;
    while (hhh.val == maxgirl) {
        if (ddd >= 1) printf (",");
        printf (" %s", names [hhh.ind]);
        G.pop();
        hhh = G.top();
        ddd++;
    }
    printf (".\n");
    return 0;
}
