#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

string aaa;
int a;
int cnt;

string aa [100001], aaaa = "";
map <string, int> MAP;

int main () {
    cin>>a;
    for (int i = 0; i < a; i++) {
        cin>>aa [i];
        aaa = "";
        aaa += aa [i] [0];
        aaa += aa [i] [1];
        MAP [aaa] = true;
    }
    for (int i = 0; i < a; i++) {
        aaa = "";
        aaa += aa [i] [aa [i].length () - 2];
        aaa += aa [i] [aa [i].length() - 1];
        if (MAP [aaa] != true) cout<<aa [i]<<endl;
    }
    return 0;
}
