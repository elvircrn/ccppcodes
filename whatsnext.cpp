#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define d 10e-5

double a [5];

double myabs (double x) {
	if (x < 0) return x * (-1);
	else return x;
}

bool cmp (double x, double y) {
   if (myabs (x - y) < d) return true;
   else return false;
}

int main () {
    cin>>a [0]>>a [1]>>a [2];
    while (a [0] || a [1] || a [2]) {
        if (cmp ((a [2] / a [1]), (a [1] / a [0]))) cout<<"GP: "<<(a [2] * (a [1] / a [0]))<<endl;
        else cout<<"AP: "<<((a [1] - a [0]) + a [2])<<endl;
        cin>>a [0]>>a [1]>>a [2];
    }
    return 0;
}
