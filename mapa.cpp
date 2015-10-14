#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

struct element
{
    int x;

    bool operator < (const element &E) const
    {
        return x < E.x;
    }
};

map <element, element> elements;

int main ()
{
    return 0;
}
