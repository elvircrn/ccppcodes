#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <sstream>

using namespace std;

int N, solution, deg [1000100], px1 [600], odd, even, py1 [600], px2 [600], py2 [600];
vector <int> list_x, list_y;
map <int, int> hash_x, hash_y;
vector <int> graph [1000100];

bool vertical [1000] [1000], visited [1000100], horizontal [200] [200];

int dimensions;

class Penlift2
{
public:
    int encode (int x, int y)
    {
        return x<<7|y;
    }

    void add_edge(int x1, int y1, int x2, int y2)
    {
        int u = encode (x1, y1);
        int v = encode (x2, y2);

        graph [u].push_back (v);
        graph [v].push_back (u);

        deg [u]++;
        deg [v]++;
    }

    void dfs (int u)
    {
        visited [u] = true;

        odd += (deg [u] % 2 && (N % 2 == 1));

        for (int i = 0; i < graph [u].size(); i++)
        {
            int v = graph [u] [i];
            if (!visited [v])
                dfs (v);
        }

        return;
    }

    int numTimes(vector <string> segments, int n)
    {
        N = n;

        memset (visited, false, sizeof visited);
        memset (horizontal, false, sizeof horizontal);
        memset (vertical, false, sizeof vertical);
        memset (deg, 0, sizeof deg);

        solution = 0;

        for (int i = 0; i < segments.size(); i++)
        {
            stringstream ss (segments [i]);
            ss>>px1 [i]>>py1 [i]>>px2 [i]>>py2 [i];
            list_x.push_back (px1 [i]);
            list_x.push_back (px2 [i]);
            list_y.push_back (py1 [i]);
            list_y.push_back (py2 [i]);
        }

        sort (list_x.begin(), list_x.end());
        sort (list_y.begin(), list_y.end());

        for (int i = 0; i < list_x.size(); i++)
        {
            if (hash_x [list_x [i]] == 0)
                hash_x [list_x [i]] = hash_x.size();
            if (hash_y [list_y [i]] == 0)
                hash_y [list_y [i]] = hash_y.size();
        }

        dimensions = max (hash_x.size(), hash_y.size()) + 5;

        for (int i = 0; i < segments.size(); i++)
        {
            px1 [i] = hash_x [px1 [i]];
            px2 [i] = hash_x [px2 [i]];
            py1 [i] = hash_y [py1 [i]];
            py2 [i] = hash_y [py2 [i]];


            if (px1 [i] == px2 [i])
                for (int j = min (py1 [i], py2 [i]); j < max (py1 [i], py2 [i]); j++)
                    vertical [px1 [i]] [j] = true;
            if (py1 [i] == py2 [i])
                for (int j = min (px1 [i], px2 [i]); j < max (px1 [i], px2 [i]); j++)
                    horizontal [j] [py1 [i]] = true;
        }


        for (int i = 0; i < 20; i++, printf ("\n"))
            for (int j = 0; j < 20; j++)
                printf ("%d ", vertical [i] [j]);
        printf ("\n\n");

        for (int i = 0; i < 20; i++, printf ("\n"))
            for (int j = 0; j < 20; j++)
                printf ("%d ", horizontal [i] [j]);

        for (int i = 0; i <= 110; i++)
        {
            for (int j = 0; j <= 110; j++)
            {
                if (vertical [i] [j])
                    add_edge(i, j, i, j + 1);
                if (horizontal [i] [j])
                    add_edge(i, j, i + 1, j);
            }
        }

        for (int i = 0; i < 1<<14; i++)
        {
            if (!visited [i] && deg [i])
            {
                odd = 0;
                dfs (i);
                solution += max (1, odd / 2);
            }
        }

        return solution - 1;
    }
};

const int array_size = 22;

string array[array_size] = { "0 0 1 0",   "2 0 4 0",   "5 0 8 0",   "9 0 13 0",
 "0 1 1 1",   "2 1 4 1",   "5 1 8 1",   "9 1 13 1",
 "0 0 0 1",   "1 0 1 1",   "2 0 2 1",   "3 0 3 1",
 "4 0 4 1",   "5 0 5 1",   "6 0 6 1",   "7 0 7 1",
 "8 0 8 1",   "9 0 9 1",   "10 0 10 1", "11 0 11 1",
 "12 0 12 1", "13 0 13 1" };

int main()
{
    vector <string> seg(array, array + array_size);

    Penlift2 pen;

    cout<<pen.numTimes(seg, 1)<<endl;
    cout<<pen.encode (600, 600)<<endl;

    return 0;
}
//C:\Users\Student_2.STUDENT-PC-5\AppData\Roaming\CodeBlocks









