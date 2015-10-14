#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
unsigned long long int n, k, l, c, d, p, nl, np, moveml, movelime, movesalt, one, two, three;
int main () {
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    moveml = k * l;
    movelime = c * d;
    movesalt = p;
    cout<<min (min (moveml / nl, movesalt / np), movelime) / n<<endl;
    return 0;
}
