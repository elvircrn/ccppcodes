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

struct word {
    char AAA [100];
    int ind;
    word () {}
    word (char asd [], int ii) {strcpy (AAA, asd); ind = ii;}
    bool operator < (const word & xx) const {
        if (AAA [strlen (AAA) - 2] == xx.AAA [strlen (AAA) - 2]) return AAA [strlen (AAA) - 1] < xx.AAA [strlen (AAA) - 1];
        else return AAA [strlen (AAA) - 1] < xx.AAA [strlen (AAA) - 1];
    }
    bool operator == (const word & xx) const {
        return ((int (AAA [strlen (AAA) - 2]) == int (xx.AAA [0])) && (int (AAA [strlen (AAA) - 1]) == int (xx.AAA [1])));
    }
};

vector <word> WORDS;
bool visited [100001];
string aa [100001];
map <string, int> MAP;

int main () {
    scanf ("%d", &a); cnt = a;
    for (int i = 0; i < a; i++) {
        cin>>aa [i];
        MAP [aa [0] + aa [1]] = true;
    }
    for (int i = 0; i < a; i++) {
        aaa = aa [i] [aa [i].length () - 2] + aa [i] [aa [i].length() - 1];
        if (MAP [aaa]) cout<<aa [i]<<endl;
    }
    return 0;
}
