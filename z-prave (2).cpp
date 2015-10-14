#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
struct dupli {
    long long int prvi, drugi;
    dupli () {}
    dupli (long long int _prvi, long long int _drugi) {prvi = _prvi; drugi = _drugi;}
};
vector <dupli> garden;
int x, y, sol, cnt, n;
bool check (dupli a, dupli b, dupli c) {
     return ((c.prvi - a.prvi)*(b.drugi - a.drugi)-(b.prvi-a.prvi)*(c.drugi-a.drugi));
}
int main () {
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>x>>y;
        garden.push_back (dupli (x, y));
        //cout<<garden [garden.size() - 1].prvi<<" "<<garden [garden.size() - 1].drugi<<endl;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            //cnt++;
            for (int z = 0; z < n; z++) {
                if (i == z || j == z || j == i) continue;
                else if (!check (garden [i], garden [j], garden [z])) cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
