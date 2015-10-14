#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>

using namespace std;

set <int> SET;

int main ()
{

    SET.insert (1);
    SET.insert (2);
    SET.insert (3);
    SET.insert (4);

    for (set<int>::iterator it = SET.begin(); it != SET.end(); it++)
    {
        cout<<(*it)<<endl;
    }


    return 0;
}
