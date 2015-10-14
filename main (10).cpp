#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MOD = 1000000007, MAXN = 11;
#define A (*this)

inline int mul(int a, int b)
{
    long long r = a;
    r *= b;
    return (r % MOD);
}

vector <vector <int> > keep;

struct matrix
{

    static void init()
    {
        keep.resize(100);
        for (int i = 0; i < 100; i++)
            keep [i].resize(100);
    }

    vector <vector <int> > mat;
    int w, h;

    matrix() {  }
    matrix(int _h, int _w)
    {
        h = _h;
        w = _w;
        mat.resize(h);
        for (int i = 0; i < h; i++)
            mat [i].resize(w);
    }

    int get(int x, int y) const
    {
        return mat [x] [y];
    }

    void make_one()
    {
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                mat [i] [j] = (i == j);
    }

    matrix operator* (matrix &B)
    {
        matrix ret(A.h, B.w);
        for (int i = 0; i < A.h; i++)
            for (int j = 0; j < B.w; j++)
                for (int k = 0; k < A.w; k++)
                    ret.mat [i] [j] = ((ret.mat [i] [j] + mul(A.get(i, k), B.get(k, j))) % MOD);
        return ret;
    }

    void operator *= (const matrix &B)
    {
        for (int i = 0; i < A.h; i++)
        {
            for (int j = 0; j < B.w; j++)
            {
                keep [i] [j] = 0;
                for (int k = 0; k < A.w; k++)
                    keep [i] [j] = ((keep [i] [j] + mul(A.get(i, k), B.get(k, j))) % MOD);
            }

            for (int j = 0; j < B.w; j++)
                mat [i] [j] = keep [i] [j];
        }
    }

    void operator= (const vector <vector <int> > m)
    {
        mat = m;
        h = m.size();
        w = m [0].size();
    }

    void print() const
    {
        for (int i = 0; i < h; i++, printf ("\n"))
        {
            printf("(%d) ", i);
            for (int j = 0; j < w; j++)
                printf ("%d ", mat [i] [j]);
        }
    }
};

matrix fast_pow(matrix p, int q)
{
    matrix r (p.h, p.h);
    r.make_one();

    while (q != 0)
    {
        if (q % 2 == 1)      // q is odd
        {
            r *= p;
            q--;
        }
        p *= p;
        q /= 2;
    }

    return r;
}

int N, M, H, S, E, MF, MW;

inline int ID(int a, int b, int c)
{
    return (5 * a + b) * N + c;
}

struct oaza
{
    int F, W;
};

oaza oaze[MAXN];
matrix MAT, vec;

void initEdges(int a, int b)
{
    if(oaze[a].F == 1 && oaze[a].W == 1)
    {
        for(int i = 1; i <= MF; ++i)
            for(int j = 1; j <= MW; ++j)
            {
                MAT.mat[ID(MF, MW, a)][ID(i, j, b)] = 1;
                //if(a == 0 && b == 2) cout << ID(MF, MW, a) << "; " << ID(i, j, b) << "\n";
            }
    }

    else if(oaze[a].F == 1)
    {
        for(int i = 1; i <= MF; ++i)
            for(int j = 1; j < MW; ++j)
                MAT.mat[ID(MF, j, a)][ID(i, j+1, b)] = 1;
    }

    else if(oaze[a].W == 1)
    {
        for(int i = 1; i < MF; ++i)
            for(int j = 1; j <= MW; ++j)
                MAT.mat[ID(i, MW, a)][ID(i+1, j, b)] = 1;
    }

    else
    {
        for(int i = 1; i < MF; ++i)
            for(int j = 1; j < MW; ++j)
                MAT.mat[ID(i, j, a)][ID(i+1, j+1, b)] = 1;
    }
}



int main()
{
    matrix::init();
    freopen("ulaz.txt","r",stdin);
    //ios_base::sync_with_stdio(0);
    cin >> N >> M >> H >> S >> E >> MF >> MW;
    --S, --E;

    MAT = matrix(1 + N + (5*MF + MW) * N, 1 + N + (5*MF + MW) * N);
    vec = matrix(1 + N + (5*MF + MW) * N, 1);

    for(int i = 0; i < MAT.mat.size(); ++i)
    {
        vec.mat[i][0] = 0;
        for(int j = 0; j < MAT.mat.size(); ++j)
            MAT.mat[i][j] = 0;
    }

    int sz = N + (5*MF + MW) * N;

    vec.mat[ID(MF, MW, S)][0] = 1;
    //cout <<ID(MF, MW, S) << "\n";
    //vec.print();

    for(int i = 0; i < N; ++i)
    {
        int F, W, P;
        cin >> oaze[i].F >> oaze[i].W >> P;
    }

    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        initEdges(a, b);
        initEdges(b, a);
        //printf("(%d, %d)\n",a, b);
    }

    MAT.mat[sz][sz] = 1;

    for(int i = 1; i <= MF ; ++i)
    {
        for(int j = 1; j <= MW; ++j)
        {
            MAT.mat[sz][ID(i, j, E)] = 1;
        }
    }

    //MAT.print();
    matrix t = fast_pow(MAT, H+1);
    matrix res = t * vec;
    //res.print();

    int sol = res.mat[sz][0];

    /*/for(int i = 1; i <= MF ; ++i){
        for(int j = 1; j <= MW; ++j){
            sol = (res.mat[ID(i, j, E)][0] + sol) % MOD;
        }
    }/*/

    cout << sol << "\n";

    return 0;
}
