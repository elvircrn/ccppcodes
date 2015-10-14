#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector <string> names = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string input;

int main()
{
    int d;
    cin>>d;
    cin>>input;
    for (int i = 0; i < names.size(); i++)
    {
        bool found = true;
        if (input.length() != names [i].length())
            continue;
        for (int j = 0; j < input.length(); j++)
        {
            if (input [j] != '.' && input [j] != names [i] [j])
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            cout<<names [i]<<endl;
            return 0;
        }
    }

    return 0;
}
