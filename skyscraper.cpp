#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct segment_tree
{
    vector <int> M;

    int init(int N)
    {
        int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
        M.resize(length, 0);
        return length;
    }

    int build(int code, int node, int b, int e)
    {
        if (b == e)
            M [node] = b;
        else
        {
            build(code, 2 * node, b, (b + e) / 2);
            build(code, 2 * node + 1, (b + e) / 2 + 1, e);

            if (code == RANGE_MIN)
            {
                if (values [M [2 * node]] <= values [M[2 * node + 1]])
                    M [node] = M [2 * node];
                else
                    M [node] = M [2 * node + 1];
            }
            else if (code == RANGE_MAX)
            {
                if (values [M [2 * node]] >= values [M[2 * node + 1]])
                    M [node] = M [2 * node];
                else
                    M [node] = M [2 * node + 1];
            }
        }
    }

    int query(int code, int node, int b, int e, int i, int j)
    {
        if (i > e || j < b)
            return -1;

        if (b >= i && e <= j)
            return M[node];

        int p1 = query (code, 2 * node, b, (b + e) / 2, i, j);
        int p2 = query (code, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

        if (p1 == -1)
            return p2;
        else if (p2 == -1)
            return p1;

        if (code == RANGE_MIN)
            return min (p1, p2);
        else if (code == RANGE_MAX)
            return max (p1, p2);
        else
            return -1;
    }

    void Update (int code, int index, int value)
    {
        update (code, 1, )
        values [index] = value;
    }

    void update (int code, int node, int index, int value, int b, int e)
    {
        if (index < b || index > e)
            return;

        if (code == RANGE_MAX)
        {
            M [node] = max (M [node], value);
        }
        else if (code == RANGE_MIN)
        {
            M [node] = min (M [node], value);
        }
        else
        {

        }

        update (code, 2 * node, index, value, b, (b + e) / 2);
        update (code, 2 * node + 1, index, value, (b + e) / 2 + 1, e);
    }
};

struct Skyscraper
{
    int l, r, h;

    Skyscraper() { }
    Skyscraper(int _l, int _r, int _h) { l = _l; r = _r; h = _h; }

    bool operator < (const Skyscraper &asd) const
    {
        return h > asd.h;
    }

    void get()
    {
        scanf ("%d %d %d", &l, &r, &h);
    }
};

int n;
Skyscraper skyscrapers [100000];

vector <int> spots [1000];

int main ()
{
    int solution = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        skyscrapers [i].get();


    }
    return 0;
}






