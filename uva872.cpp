#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, t;
char c, cc, letters [30];
bool visited [256];

vector <char>  graph [256];
vector <char> top_sort;

void dfs(char letter, string path)
{
    printf ("   %c\n", letter);

    cout<<"path: "<<path<<endl;

    for (int i = 0; i < graph [letter].size(); i++)
        if (!visited [graph [letter] [i]])
        {
            string path2 = path + graph [letter] [i];
            visited [letter] = true;
            dfs (graph [letter] [i], path2);

            visited [letter] = false;
        }
}

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%d", &t); getchar();

    while (scanf ("%s", &letters [n++]) == 1 && getchar() != '\n');
    c = getchar();

    while (true)
    {
        printf ("%c ", c);
        getchar();
        graph [c].push_back (cc = getchar());

        printf ("%c\n", cc);

        if ((cc = getchar()) == '\n' || cc == EOF)
            break;

        c = getchar();
    }

    for (int i = 0; i < n; i++)
    {
        string path = "";
        path += letters [i];
            visited [letters [i]] = true;
            printf ("start: %c\n", letters [i]);
            dfs (letters [i], path);

            visited [letters [i]]= false;
        //}
    }

    //for (int i = 0; i < top_sort.size(); i++)
    //    printf ("%c ", top_sort [i]); printf ("\n");

    return 0;
}











