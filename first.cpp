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

string words [30100];
int visited [26], n, word_index [30100], positions [30100] [28];

vector <int> solution;

vector <int> graph [27];

bool cmp(int x, int y)
{
    return words [x] < words [y];
}

int get_similarity(int x, int y)
{
    int ret = 0;

    while (ret < words [x].size() && ret < words [y].size() && words [x] [ret] == words [y] [ret])
        ret++;

    return ret;
}

void generate(int x, int y)
{
    if (x == y)
        return;

    for
}

bool circlejerk (int index)
{
    if (visited [index] == DFS_BLACK)
        return false;
    else if (visited [index] == DFS_GREY)
        return true;
    else
    {
        for (int i = 0; i < graph [index].size(); i++)
            if (visited [graph [index] [i]] != DFS_BLACK && circlejerk (graph [index] [i]))
                return true;
    }

    return false;
}

bool check (int ri)
{
    if (ri == 0)
        return true;

    for (int i = 0; i < 'z' - 'a'; i++)
        graph [i].clear();

    int index = word_index [ri];

    cout<<"index: "<<index<<" "<<"current_string: "<<words [index]<<endl;

    memset (visited, DFS_WHITE, sizeof visited);

    int similarity = 0;

    if (ri == n - 1)
        similarity = get_similarity(word_index [ri - 1], word_index [ri]);
    else
        similarity = max (get_similarity(word_index [ri - 1], word_index [ri]), get_similarity(word_index [ri], word_index [ri + 1]));

    cout<<"    similarity: "<<similarity<<endl;

    if (words [word_index [ri - 1]].length() == similarity)
        return false;

    for (int i = 0; i <= similarity; i++)
        for (int j = 0; j < 26; j++)
            if (j != words [index] [j] - 'a' && positions [i] [j] > 1)
                graph [i].push_back (j);

    for (int i = 0; i < 26; i++)
        if (circlejerk (i))
            return false;

    return true;
}

int main()
{
    freopen ("in.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        word_index [i] = i;
        cin>>words [i];

        for (int j = 0; j < words [i].size(); j++)
            positions [j] [words [i] [j] - 'a']++;
    }

    sort (word_index, word_index + n, cmp);
+

    for (int i = 0; i < n; i++)
        cout<<words [word_index [i]]<<endl;

    for (int i = 0; i < n; i++)
        if (check (i))
            solution.push_back (word_index [i]);

    //sort (solution.begin(), solution.end());

    for (int i = 0; i < solution.size(); i++)
        cout<<words [solution [i]]<<endl;

    return 0;
}





















