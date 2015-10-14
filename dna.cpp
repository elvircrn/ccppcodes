#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int n, m;

char input [100] [10000];
char query [100] [6];

int matrix [1000] [26] [26] [26] [26], max_len;

int num_size(int x)
{
    int cnt = 0;

    if (x == 0)
        return 1;

    while (x)
    {
        cnt++;
        x /= 10;
    }

    return cnt;
}

struct cluster
{
    int string_index, occurence;

    cluster() { }
    cluster(int _string_index, int _occurence) { string_index = _string_index; occurence = _occurence; }

    bool operator< (const cluster &B) const
    {
        return occurence < B.occurence;
    }
};

vector <cluster> clusters;

int main()
{
    FILE *in = fopen ("in.txt", "r");
    FILE *out = fopen ("out.txt", "w");

    fprintf (out, "<-- part 1 -->\n\n");

    fscanf (in, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf (in, "%s", input [i]);
        int len = strlen (input [i]);
        max_len = max (len, max_len);
        for (int j = 0; j < len - 3; j++)
            matrix [i] [input [i] [j] - 'a'] [input [i] [j + 1] - 'a'] [input [i] [j + 2] - 'a'] [input [i] [j + 3] - 'a']++;
    }

    fscanf (in, "%d", &m);
    for (int i = 0; i < m; i++)
        fscanf (in, "%s", &query [i]);

    int large = num_size (n);

    for (int i = 0; i < num_size (n) + 3 + 2; i++)
            fprintf (out, " ");
    for (int i = 0; i < m; i++)
        fprintf (out, "%s ", query [i]); fprintf (out, "\n");


    for (int i = 0; i < n; i++)
    {
        fprintf (out, "DNA%d: ", i + 1);
        for (int j = 0; j < large - num_size (i + 1); j++)
            fprintf (out, " ");
        for (int j = 0; j < m; j++)
            fprintf (out, "%4d ", matrix [i] [query [j] [0] - 'a'] [query [j] [1] - 'a'] [query [j] [2] - 'a'] [query [j] [3] - 'a']);
        fprintf (out, "\n");
    }

    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
            cnt += matrix [j] [query [i] [0] - 'a'] [query [i] [1] - 'a'] [query [i] [2] - 'a'] [query [i] [3] - 'a'];
        clusters.push_back (cluster (i, cnt));
    }

    fprintf (out, "\n\n<-- part 2 -->\n\n\n");


    char file_name[1000];


    sort (clusters.begin(), clusters.end());

    int current_occurence = clusters [0].occurence;

    fprintf (out, "%d\n", clusters [0].occurence);
    fprintf (out, "%s\n", query [clusters [0].string_index]);

    for (int i = 1; i < clusters.size(); i++)
    {
        if (clusters [i - 1].occurence != clusters [i].occurence)
        {
            fprintf (out, "%d\n", clusters [i].occurence);
        }
        fprintf (out, "%s\n", query [clusters [i].string_index]);

    }

    return 0;
}












