#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N = 1000000;
    int k = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));

    cout<<k<<endl;

    return 0;
}
