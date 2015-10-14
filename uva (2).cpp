#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

int n;
char input [1001] [1010];

bool used [1000] [1000];

int powers [7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int nDigits(int x)
{
    int ret = 0;
    while (x)
    {
        ret++;
        x /= 10;
    }

    return ret;
}

char c, imena [1000] [100];

vector <int> votes [1000];

int main ()
{
    freopen ("unos.txt", "r", stdin);

    scanf ("%d", &n);

    int it = 0;

    for (int i = 0; i < n; i++)
    {
        cin.getline (imena [i], '\n');
        cout<<imena [i]<<endl;
    }

    char line [100];

    fgets (line, 100, stdin);

    while (line [0] != EOF && line [1])
    {
        fgets (line, 100, stdin);
        for (int i = 0; (line [i] && line [i] != '\n'); i++)
        {
            if (isdigit (line [i]) && isdigit (line [i + 1]))
            {
                votes [it].push_back ((line [i] - '0') * 10 + (line [i] - '0'));
            }
            else
            {
                votes [it].push_back (line [i] - '0');
            }
        }
        fgets (line, 100, stdin);
        it++;
    }

    return 0;
}










