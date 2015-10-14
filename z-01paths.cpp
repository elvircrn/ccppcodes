#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

char end;
int n, k, cnt;

char TP (char current_room, int command)
{
    if (command == 0)
    {
        if (current_room == 'B')
            return 'D';
        if (current_room == 'D')
            return 'B';

        if (current_room == 'A')
            return 'C';
        if (current_room == 'C')
            return 'A';
    }
    else
    {
        if (current_room == 'B')
            return 'A';
        if (current_room == 'A')
            return 'B';

        if (current_room == 'D')
            return 'C';
        if (current_room == 'C')
            return 'D';
    }
}

void dfs (char current_room, int depth, string path)
{
    if (depth == 0 && current_room == end)
    {
        cnt++;
        if (cnt == k)
        {
            cout<<path<<endl;
            exit (0);
        }
        return;
    }
    if (depth == 0)
        return;
    char next = TP (current_room, 0);
    dfs (next, depth - 1, path + '0');
    next = TP (current_room, 1);
    dfs (next, depth - 1, path + '1');
}

int main()
{
    scanf ("%c %d %d", &end, &n, &k);

    dfs ('A', n, "");
    printf ("impossible\n");
    return 0;
}










