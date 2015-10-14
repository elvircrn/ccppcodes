#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> SET;

int main ()
{

    SET.push_back (10);
    SET.push_back (20);
    SET.push_back (30);
    SET.push_back (40);

    vector <int>::iterator b = SET.begin();
    vector <int>::iterator it = (SET.lower_bound (20));

    cout<<it - b<<endl;

    return 0;
}
