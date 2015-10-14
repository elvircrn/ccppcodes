#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define DFS_WHITE 0
#define DFS_GREY  1
#define DFS_BLACK 2

char word [300100];
int visited [30], n, positions [30100] [30];
vector <int>   graph [30];
vector <char*> words;

int to_int (char c)
{
    return c - 'a';
}

void clear()
{
    memset (visited, DFS_WHITE, sizeof visited);

    for (int i = 0; i < 26; i++)
        graph [i].clear();
}

bool circle_jerk(int current_index)
{
    printf ("current_index: %d\n", current_index);

    if (visited [current_index] == DFS_GREY)
        return true;

    visited [current_index] = DFS_GREY;

    for (int i = 0; i < graph [current_index].size(); i++)
    {
        if (visited [graph [current_index] [i]] != DFS_BLACK)
            if (circle_jerk (graph [current_index] [i]))
                return true;
    }

    visited [current_index] = DFS_BLACK;

    return false;
}

bool check (int index)
{
    printf ("\n\n<---------->");

    clear();

    for (int i = 0; isalpha (words [index] [i]); i++)
        for (int j = 0; j < 26; j++)
            if (positions [i] [j] > 1 && to_int (words [index] [i]) != j)
                graph [to_int (words [index] [i])].push_back (j);

    for (int i = 0; i < 26; i++)
    {
        if (visited [i] == DFS_WHITE)
        {
            visited [i] = DFS_GREY;

            if (circle_jerk(i))
                return false;

            visited [i] = DFS_BLACK;
        }
    }
    return true;
}

int main()
{
    freopen ("in.txt", "r", stdin);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &word);
        words.push_back (word);

        for (int j = 0; isalpha (words [i] [j]); j++)
            positions [i] [to_int (words [i] [j])]++;

        cout<<endl;
    }

    for (int i = 0; i < n; i++)
    {

        if (check (i))
        {
            printf ("%s\n", words [i]);

        }
    }
    return 0;
}






























