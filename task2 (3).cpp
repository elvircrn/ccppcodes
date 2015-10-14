#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string strings [100];
int n;
bool visited [100];
vector <int> graph [100];

int dfs (int v)
{
    visited [v] = true;
    int ret = 1;

    for (int i = 0; i < graph [v].size(); i++)
        if (!visited [graph [v] [i]])
            ret *= dfs (graph [v] [i]);

    return ret + 1;
}

int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>strings [i];

    sort (strings, strings + n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool found(false);
            for (int k = 0; k < strings [i].size(); k++)
            {
                if (strings [i] [k] != strings [j] [k])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                graph [i].push_back (j);
        }
    }

    int ret = 1;

    for (int i = 0; i < n; i++)
        if (!visited [i])
            ret *= dfs (i);

    printf ("%d\n", ret);

    return 0;
}















