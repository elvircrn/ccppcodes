#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAXV = 1<<14;
vector <int> gg [MAXV];
bool hor [110][110], ver [110] [110], vis [MAXV];
int deg [MAXV];
int xx[110], yy[110], cx, cy;
int xa[60], ya [60], xb [60], yb [60];
map<int, int> idx, idy;
int N;

class PenLift
{
public:
    int encode(int x, int y)
    {
        return x<<7|y;
    }
    void addedge(int x1, int y1, int x2, int y2)
    {
        int u = encode(x1, y1), v = encode (x2, y2);
        gg[u].push_back (v);
        gg[v].push_back (u);
        deg [u]++;
        deg [v]++;
    }
    int dfs(int u)
    {
        vis [u] = true;
        int r = (deg [u] % 2 && N % 2);
        for (int i = 0; i < gg [u].size(); i++)
        {
            int v = gg [u] [i];
            if(deg [v] > 0 && !vis[v])
                r += dfs(v);
        }
        return r;
    }
    int numTimes(vector<string> seg, int n)
    {
        N = n;
        cx = cy = 0;
        for (int i = 0; i < MAXV; i++)
            gg [i].clear();
        memset(deg, 0, sizeof deg);
        memset(hor, 0, sizeof hor);
        memset(ver, 0, sizeof ver);

        for(int i = 0; i < seg.size(); i++)
        {
            istringstream is (seg [i]);
            is>>xa [i]>>ya [i]>>xb [i]>>yb [i];
            if (xa [i] > xb [i]) swap (xa [i], xb [i]);
            if (ya [i] > yb [i]) swap (ya [i], yb [i]);
            xx[cx++] = xa [i];
            xx [cx++] = xb [i];
            yy[cy++] = ya [i];
            yy [cy++] = yb [i];
        }

        sort (xx, xx + cx);
        sort (yy, yy + cy);

        //cout<<idx.size()<<endl;

        idx.clear();
        idy.clear();

        for (int i = 0; i < cx; i++)
        {
            if (idx [xx [i]] == 0)
                idx [xx [i]] = idx.size();
        }
        /*for (int i = 0; i < 110; i++)
        {
            for (int j = 0; j < 110; j++)
                cout<<ver [i] [j]<<' ';
            cout<<endl;
        }
        cout<<endl<<endl;
        for (int i = 0; i < 110; i++)
        {

        }*/

        for (int i = 0; i < cy; i++)
        {
            if (idy [yy [i]] == 0)
                idy [yy [i]] = idy.size();
        }

        for (int i = 0; i < seg.size(); i++)
        {
            xa [i] = idx [xa [i]];
            xb [i] = idx [xb [i]];
            ya [i] = idy [ya [i]];
            yb [i] = idy [yb [i]];

            if (xa [i] == xb [i])
                for (int j = ya [i]; j < yb [i]; j++)
                    ver [xa [i]] [j] = true;
            if (ya [i] == yb [i])
                for (int j = xa [i]; j < xb [i]; j++)
                    hor [j] [ya [i]] = true;
        }

        for (int i = 0; i < 110; i++)
        {
            for (int j = 0; j < 110; j++)
            {
                if (ver [i] [j])
                    addedge(i, j, i, j + 1);
                if (hor [i] [j])
                    addedge(i, j, i + 1, j);
            }
        }
        /*cout<<endl<<endl;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
                cout<<ver [i] [j]<<' ';
            cout<<endl;
        }
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
                cout<<hor [i] [j]<<' ';
            cout<<endl;
        }*/

        int ans = 0;
        memset (vis, false, sizeof (vis));
        for (int i = 0; i < MAXV; i++)
        {
            if (!vis [i] && deg [i] > 0)
            {
                int od = dfs (i);
                ans += max (1, od / 2);
                //cout<<ans<<' '<<ans<<endl;
            }
        }
        return max (0, ans - 1);
    }
};

/*PenLift2 pen;

int main()
{
//"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"
    vector <string> input;

    input.push_back ("-1 0 0 0");
    input.push_back ("0 0 1 0");
    input.push_back ("0 -1 0 0");
    input.push_back ("0 0 0 1");

    pen.NumTimes(input, 1);

    return 0;
}
*/
