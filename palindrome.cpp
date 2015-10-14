#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector <char> word;

int main()
{

    scanf ("%d", &t);
    while (t--)
    {
        char c;
        while (!isdigit (c = getchar()));
        word.push_back (c);
        while (isdigit (c = getchar()))
            word.push_back (c);
    }



    return 0;
}
