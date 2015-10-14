#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int solution, t, n, m, b [1000];
string strings [1000], needle, haystack;

void kmpPreprocess()
{
    b [0] = -1;
    int i = 0, j = -1;
    while (i < needle.length())
    {
        while (j >= 0 && needle [i] != needle [j])
            j = b [j];
        i++;
        j++;
        b [i] = j;
    }
}

int kmpSearch()
{
    int i = 0, j = 0;
    while (i < haystack.length())
    {
        while (j >= 0 && haystack [i] != needle [j])
            j = b [j];
        i++;
        j++;
    }

    return j;
}

int main()
{
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d %d", &n, &m);
        cin>>strings [0];
        solution = strings [0].length();
        for (int i = 1; i < m; i++)
        {
            cin>>strings [i];

            haystack = strings [i - 1];
            needle   = strings [i];

            kmpPreprocess();

            solution += needle.length() - kmpSearch();
        }

        printf ("%d\n", solution);
    }

    return 0;
}
