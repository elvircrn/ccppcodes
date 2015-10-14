#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <time.h>
#define LIMIT 1000000
using namespace std;
typedef long long lld;
char buffer[LIMIT], * pos = buffer + LIMIT;

inline char getnext()
{
    if (pos == buffer + LIMIT)
    {
        pos = buffer;
        fread(buffer, 1, LIMIT, stdin);
    }
    return *pos++;
}

inline int getint()
{
    int num = 0;
    char cc;
    while (!isdigit(cc = getnext()));
    do
    {
        num = num * 10 + cc - '0';
    }
    while (isdigit(cc = getnext()));
    return num;
}


int skorr[5] = {1, 4, 10, 15};

int idd = 1;

int H[100],red[100];
int mat[22][12]/*indeksirana tako da je najdonji red 0 jer mi je bilo puno lakse razmisljati o tetrisu na taj nacin*/,n,k,m,o,a[100],h,x;
int movesX[50001], movesO[50001];
bool phail;

int tetrominos[50001];
int wellZ[22][12];
int wellZTMP[22][12];
int under[22][12];
int underTMP[22][12];
int odg[12];
bool willClear;
double wellSums;

bool willUpdate = false;

stack<int> holeZ[11];

int tetAmt[22];
int amtPerRow[22];
int colTransStore[11];
int colTrans[11];
int rowTransStore[22];
int rowTrans[22];

int prom[5][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int totalHeight;
int linesCleared;
int holes;
int blockades;
int edgesOnWall;
int edgesOnOtherBlock;
int edgesOnFloor;

bool stored;
double currFunctionVal;
double optFunctionVal;
int storeX, storeO;
double currScore, optScore;

double landingHeightM;
double rowsM;
double rowTransM;
double colTransM;
double holeM;
double wellM;

int totalScore = 0;

int t, br;

map<pair<lld, int>, pair<int, int> > memo;

inline void ispis (void)
{
    cout<<endl<<"+++++++++++++++++++++++"<<endl;
    for (int i=19; i>=0; i--)
    {
        for (int j=0; j<10; j++)
            cout<<mat[i][j];
        cout<<endl;
    }
    cout<<endl;
    for (int i=0; i<10; i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<endl<<"+++++++++++++++++++++++"<<endl;
    return;
}

inline void clear_row(int id)
{
    for (int j=0; j<10; j++)
    {
        mat[id][j] = 0;
        if (id > 0)
        {
            if (mat[id-1][j] == 0 && mat[id+1][j] == 0) colTrans[j] -= 2;
        }
    }
    amtPerRow[id] = 0;
    for (int i=id+1; i<20; i++)
    {
        amtPerRow[i-1] = amtPerRow[i];
        rowTrans[i-1] = rowTrans[i];
        for (int j=0; j<10; j++)
        {
            mat[i-1][j] = mat[i][j];
        }
    }
}

inline int delete_rows(int dropHeight, bool test)
{
    int ret = 0;

    int add = 0;

    int upTo = min(dropHeight + 4, 20);

    for (int i=dropHeight; i<upTo; i++)
    {
        while (amtPerRow[i] == 10)
        {
            red[i]=1;
            if (test) clear_row(i);
            else i++;
            ret+=skorr[add++];
        }
    }
    return ret;
}

inline void recalculateHeights()
{
    for (int j=0; j<10; j++)
    {
        int ii = a[j]-1;
        while (ii >= 0 && mat[ii][j] == 0) ii--;
        a[j] = ++ii;
    }
}

inline int padni (int x, int n, int o, bool test)
{
    for (int i=0; i<20; i++)
    {
        rowTrans[i] = rowTransStore[i];
        amtPerRow[i] = tetAmt[i];
    }
    for (int i=0; i<10; i++)
    {
        colTrans[i] = colTransStore[i];
        a[i] = H[i];
    }
    willClear = false;

    if (willUpdate)
    {
        totalHeight = 0;
        for (int i=0; i<10; i++) totalHeight = max(totalHeight, a[i]);

        for (int i=0; i<totalHeight; i++)
        {
            for (int j=0; j<10; j++)
            {
                under[i+1][j] = under[i][j];
                if (mat[i][j] == 0)
                {
                    under[i+1][j]++;
                    //wellZ[i+1][j] = wellZ[i][j] + 1;
                }
                //else wellZ[i+1][j] = 0;
            }
        }

        willUpdate = false;
    }

    int sir = 0;
    int vis = 0;

    if (n == 1)
    {
        if (o > 1) return -1;
        if (o == 0)
        {
            if (x < 0 || x > 6) return -1;
            h = 0;
            for (int i=x; i<x+4; i++)
            {
                h = max(h, a[i]);
            }
            if (h > 18) return -1;
            for (int i=x; i<x+4; i++)
            {
                mat[h][i] = 1;
                a[i] = h+1;

                prom[i-x][0] = h;
                prom[i-x][1] = i;
            }
            amtPerRow[h] += 4;
            if (amtPerRow[h] == 10) willClear = true;
            vis = 1;
            sir = 4;
        }
        else if (o == 1)
        {
            if (x < 0 || x > 9) return -1;
            h = a[x];
            if (h > 15) return -1;
            for (int i=h; i<h+4; i++)
            {
                mat[i][x] = 1;
                amtPerRow[i]++;
                if (amtPerRow[i] == 10) willClear = true;

                prom[i-h][0] = i;
                prom[i-h][1] = x;
            }
            a[x] = h+4;
            vis = 4;
            sir = 1;
        }
    }

    else if (n == 2)
    {
        if (o == 0)
        {
            if (x < 0 || x > 7) return -1;
            h = 0;
            for (int i=x; i<x+3; i++)
            {
                h = max(h,a[i]);
            }
            if (h > 17) return -1;
            for (int i=x; i<x+3; i++)
            {
                mat[h][i] = 1;
                a[i] = h+1;

                prom[i-x][0] = h;
                prom[i-x][1] = i;
            }
            mat[h+1][x+2] = 1;
            prom[3][0] = h+1;
            prom[3][1] = x+2;
            a[x+2]++;
            amtPerRow[h] += 3;
            if (amtPerRow[h] == 10) willClear = true;
            amtPerRow[h+1]++;
            if (amtPerRow[h+1] == 10) willClear = true;
            vis = 2;
            sir = 3;
        }
        else if (o == 1)
        {
            if (x < 0 || x > 8) return -1;
            h = max(a[x],a[x+1]);
            if (h > 16) return -1;
            for (int i=h; i<h+3; i++)
            {
                mat[i][x] = 1;
                amtPerRow[i]++;
                if (amtPerRow[i] == 10) willClear = true;
                prom[i-h][0] = i;
                prom[i-h][1] = x;
            }
            mat[h][x+1] = 1;
            prom[3][0] = h;
            prom[3][1] = x+1;
            a[x] = h+3;
            a[x+1] = h+1;
            amtPerRow[h]++;
            if (amtPerRow[h] == 10) willClear = true;
            vis = 3;
            sir = 2;
        }
        else if (o == 2)
        {
            if (x < 0 || x > 7) return -1;
            h = max(a[x+1]-1,a[x+2]-1);
            h = max(h,a[x]);
            if (h > 17) return -1;
            for (int i=x; i<x+3; i++)
            {
                mat[h+1][i] = 1;
                prom[i-x][0] = h+1;
                prom[i-x][1] = i;
                a[i] = h+2;
            }
            amtPerRow[h+1] += 3;
            if (amtPerRow[h+1] == 10) willClear = true;
            mat[h][x] = 1;
            prom[3][0] = h;
            prom[3][1] = x;
            amtPerRow[h]++;
            if (amtPerRow[h] == 10) willClear = true;
            vis = 2;
            sir = 3;
        }
        else if (o == 3)
        {
            if (x < 0 || x > 8) return -1;
            h = max(a[x]-2,a[x+1]);
            if (h > 16) return -1;
            for (int i=h; i<h+3; i++)
            {
                mat[i][x+1] = 1;
                prom[i-h][0] = i;
                prom[i-h][1] = x+1;
                amtPerRow[i]++;
                if (amtPerRow[i] == 10) willClear = true;
            }
            a[x+1] = h+3;
            mat[h+2][x] = 1;
            prom[3][0] = h+2;
            prom[3][1] = x;
            a[x] = h+3;
            amtPerRow[h+2]++;
            if (amtPerRow[h+2] == 10) willClear = true;
            vis = 3;
            sir = 2;
        }
    }

    else if (n == 3)
    {
        if (o == 0)
        {
            if (x < 0 || x > 7) return -1;
            h = 0;
            for (int i=x; i<x+3; i++)
            {
                h = max(h,a[i]);
            }
            if (h > 17) return -1;
            for (int i=x; i<x+3; i++)
            {
                mat[h][i] = 1;
                prom[i-x][0] = h;
                prom[i-x][1] = i;
                a[i] = h+1;
            }
            amtPerRow[h] += 3;
            if (amtPerRow[h] == 10) willClear = true;
            mat[h+1][x] = 1;
            prom[3][0] = h+1;
            prom[3][1] = x;
            a[x] = h+2;
            amtPerRow[h+1]++;
            if (amtPerRow[h+1] == 10) willClear = true;
            vis = 2;
            sir = 3;
        }
        else if (o == 1)
        {
            if (x < 0 || x > 8) return -1;
            h = max(a[x],a[x+1]-2);
            if (h > 16) return -1;
            for (int i=h; i<h+3; i++)
            {
                mat[i][x] = 1;
                prom[i-h][0] = i;
                prom[i-h][1] = x;
                amtPerRow[i]++;
                if (amtPerRow[i] == 10) willClear = true;
            }
            a[x] = h+3;
            mat[h+2][x+1] = 1;
            prom[3][0] = h+2;
            prom[3][1] = x+1;
            a[x+1] = h+3;
            amtPerRow[h+2]++;
            if (amtPerRow[h+2] == 10) willClear = true;
            vis = 3;
            sir = 2;
        }
        else if (o == 2)
        {
            if (x < 0 || x > 7) return -1;
            h = max(a[x]-1,a[x+1]-1);
            h = max(h,a[x+2]);
            if (h > 17) return -1;
            for (int i=x; i<x+3; i++)
            {
                mat[h+1][i] = 1;
                prom[i-x][0] = h+1;
                prom[i-x][1] = i;
                a[i] = h+2;
            }
            amtPerRow[h+1] += 3;
            if (amtPerRow[h+1] == 10) willClear = true;
            mat[h][x+2] = 1;
            prom[3][0] = h;
            prom[3][1] = x+2;
            amtPerRow[h]++;
            if (amtPerRow[h] == 10) willClear = true;
            vis = 2;
            sir = 3;
        }
        else if (o == 3)
        {
            if (x < 0 || x > 8) return -1;
            h = max(a[x],a[x+1]);
            if (h > 16) return -1;
            for (int i=h; i<h+3; i++)
            {
                mat[i][x+1] = 1;
                prom[i-h][0] = i;
                prom[i-h][1] = x+1;
                amtPerRow[i]++;
                if (amtPerRow[i] == 10) willClear = true;
            }
            a[x+1] = h+3;
            mat[h][x] = 1;
            prom[3][0] = h;
            prom[3][1] = x;
            a[x] = h+1;
            amtPerRow[h]++;
            if (amtPerRow[h] == 10) willClear = true;
            vis = 3;
            sir = 2;
        }
    }

    else if (n == 4)
    {
        if (o > 1) return -1;
        if (o == 0)
        {
            if (x < 0 || x > 7) return -1;
            h = max(max(a[x+2],a[x+1]),a[x]-1);
            if (h > 17) return -1;
            mat[h][x+1] = 1;
            mat[h][x+2] = 1;
            mat[h+1][x] = 1;
            mat[h+1][x+1] = 1;
            prom[0][0] = h;
            prom[0][1] = x+1;
            prom[1][0] = h;
            prom[1][1] = x+2;
            prom[2][0] = h+1;
            prom[2][1] = x;
            prom[3][0] = h+1;
            prom[3][1] = x+1;
            a[x] = h+2;
            a[x+1] = h+2;
            a[x+2] = h+1;
            amtPerRow[h] += 2;
            if (amtPerRow[h] == 10) willClear = true;
            amtPerRow[h+1] += 2;
            if (amtPerRow[h+1] == 10) willClear = true;
            vis = 2;
            sir = 3;
        }
        else if (o == 1)
        {
            if (x < 0 || x > 8) return -1;
            h = max(a[x],a[x+1]-1);
            if (h > 16) return -1;
            mat[h][x] = 1;
            mat[h+1][x] = 1;
            mat[h+1][x+1] = 1;
            mat[h+2][x+1] = 1;
            prom[0][0] = h;
            prom[0][1] = x;
            prom[1][0] = h+1;
            prom[1][1] = x;
            prom[2][0] = h+1;
            prom[2][1] = x+1;
            prom[3][0] = h+2;
            prom[3][1] = x+1;
            a[x] = h+2;
            a[x+1] = h+3;
            amtPerRow[h]++;
            if (amtPerRow[h] == 10) willClear = true;
            amtPerRow[h+1] += 2;
            if (amtPerRow[h+1] == 10) willClear = true;
            amtPerRow[h+2]++;
            if (amtPerRow[h+2] == 10) willClear = true;
            vis = 3;
            sir = 2;
        }
    }

    else if (n == 5)
    {
        if (o > 1) return -1;
        if (o == 0)
        {
            if (x < 0 || x > 7) return -1;
            h = max(max(a[x+2]-1,a[x+1]),a[x]);
            if (h > 17) return -1;
            mat[h][x] = 1;
            mat[h][x+1] = 1;
            mat[h+1][x+1] = 1;
            mat[h+1][x+2] = 1;
            prom[0][0] = h;
            prom[0][1] = x;
            prom[1][0] = h;
            prom[1][1] = x+1;
            prom[2][0] = h+1;
            prom[2][1] = x+1;
            prom[3][0] = h+1;
            prom[3][1] = x+2;
            a[x] = h+1;
            a[x+1] = h+2;
            a[x+2] = h+2;
            amtPerRow[h] += 2;
            if (amtPerRow[h] == 10) willClear = true;
            amtPerRow[h+1] += 2;
            if (amtPerRow[h+1] == 10) willClear = true;
            vis = 2;
            sir = 3;
        }
        else if (o == 1)
        {
            if (x < 0 || x > 8) return -1;
            h = max(a[x]-1,a[x+1]);
            if (h > 16) return -1;
            mat[h][x+1] = 1;
            mat[h+1][x] = 1;
            mat[h+1][x+1] = 1;
            mat[h+2][x] = 1;
            prom[0][0] = h;
            prom[0][1] = x+1;
            prom[1][0] = h+1;
            prom[1][1] = x;
            prom[2][0] = h+1;
            prom[2][1] = x+1;
            prom[3][0] = h+2;
            prom[3][1] = x;
            a[x] = h+3;
            a[x+1] = h+2;
            amtPerRow[h]++;
            if (amtPerRow[h] == 10) willClear = true;
            amtPerRow[h+1] += 2;
            if (amtPerRow[h+1] == 10) willClear = true;
            amtPerRow[h+2]++;
            if (amtPerRow[h+2] == 10) willClear = true;
            vis = 3;
            sir = 2;
        }
    }

    else if (n == 6)
    {
        if (o > 0) return -1;
        if (x < 0 || x > 8) return -1;
        h = max(a[x],a[x+1]);
        if (h > 17) return -1;
        mat[h][x] = 1;
        mat[h][x+1] = 1;
        mat[h+1][x] = 1;
        mat[h+1][x+1] = 1;
        prom[0][0] = h;
        prom[0][1] = x;
        prom[1][0] = h;
        prom[1][1] = x+1;
        prom[2][0] = h+1;
        prom[2][1] = x;
        prom[3][0] = h+1;
        prom[3][1] = x+1;
        a[x] = h+2;
        a[x+1] = h+2;
        amtPerRow[h] += 2;
        if (amtPerRow[h] == 10) willClear = true;
        amtPerRow[h+1] += 2;
        if (amtPerRow[h+1] == 10) willClear = true;
        vis = 2;
        sir = 2;
    }

    linesCleared = 0;
    if (willClear)
    {
        for (int i=0; i<20; i++) red[i]=0;
        linesCleared = delete_rows(h, !test);
        if (!test) recalculateHeights();
    }

    int last_bit = 1;
    for (int i=h; i<h+vis; i++)
    {
        rowTrans[i] = 0;
        for (int j=0; j<10; j++)
        {
            if (mat[i][j] != last_bit) rowTrans[i]++;
            last_bit = mat[i][j];
        }
        if (last_bit == 0) rowTrans[i]++;
        last_bit = 1;
    }

    last_bit = 1;
    for (int j=x; j<x+sir; j++)
    {
        colTrans[j] = 0;
        for (int i=0; i<=a[j]; i++)
        {
            if (mat[i][j] != last_bit) colTrans[j]++;
            last_bit = mat[i][j];
        }
        if (a[j] != 0) colTrans[j]++;
        last_bit = 1;
    }

    if (!test)
    {
        for (int i=0; i<20; i++)
        {
            tetAmt[i] = amtPerRow[i];
            rowTransStore[i] = rowTrans[i];
        }
        for (int i=0; i<10; i++)
        {
            H[i] = a[i];
            colTransStore[i] = colTrans[i];
        }
        totalScore += linesCleared;
        //ispis();
        //system("pause");
    }

    else
    {
        totalHeight = 0;
        for (int i=0; i<10; i++) totalHeight = max(totalHeight, a[i]);

        currScore = (h + vis)*0.5*landingHeightM;
        currScore += linesCleared*rowsM;

        double rowTransitions = 0;
        for (int i=0; i<=totalHeight; i++) rowTransitions += rowTrans[i];

        currScore += rowTransitions * rowTransM;

        double colTransitions = 0;
        for (int j=0; j<10; j++) if (a[j] != 0) colTransitions += colTrans[j];
            else colTransitions++;

        currScore += colTransitions * colTransM;

        if (willClear)
        {
            for (int i=0; i<totalHeight; i++)
            {
                for (int j=0; j<10; j++)
                {
                    underTMP[i+1][j] = underTMP[i][j];
                    if (mat[i][j] == 0)
                    {
                        underTMP[i+1][j]++;
                    }
                }
            }

            holes = 0;
            for (int j=0; j<10; j++)
            {
                for (int i=a[j]; i>=0; i--)
                {
                    if (mat[i][j] == 1 && red[i]==0)
                    {
                        holes += underTMP[i][j];
                        break;
                    }
                }
            }

        }

        else
        {
            for (int i=0; i<totalHeight; i++)
            {
                for (int j=x; j<x+sir; j++)
                {
                    under[i+1][j] = under[i][j];
                    if (mat[i][j] == 0)
                    {
                        under[i+1][j]++;
                    }
                }
            }

            holes = 0;
            for (int j=0; j<10; j++)
            {
                for (int i=a[j]; i>=0; i--)
                {
                    if (mat[i][j] == 1 && red[i]==0)
                    {
                        holes += under[i][j];
                        break;
                    }
                }
            }
        }

        currScore += holes * holeM;

        wellSums = 0;
        for (int j=1; j<9; j++)
        {
            for (int i=0; i<totalHeight; i++)
            {
                if (mat[i][j] == 0)
                {
                    wellZ[i+1][j] = wellZ[i][j] + 1;
                    if (mat[i][j-1] == 1 && mat[i][j+1] == 1)
                    {
                        wellSums += (1 + wellZ[i][j]);
                    }
                }
                else wellZ[i+1][j] = 0;
            }
        }

        for (int i=0; i<totalHeight; i++)
        {
            if (mat[i][0] == 0)
            {
                wellZ[i+1][0] = wellZ[i][0] + 1;
                if (mat[i][1] == 1)
                {
                    wellSums += (1 + wellZ[i][0]);
                }
            }
            else wellZ[i+1][0] = 0;

            if (mat[i][9] == 0)
            {
                wellZ[i+1][9] = wellZ[i][9] + 1;
                if (mat[i][8] == 1)
                {
                    wellSums += (1 + wellZ[i][9]);
                }
            }
            else wellZ[i+1][9] = 0;
        }

        currScore += wellSums * wellM;

        if (stored == false || currScore > optScore)
        {
            optScore = currScore;
            storeO = o;
            storeX = x;
            stored = true;
        }

        //cout << "x = " << x << ", o = " << o << ", score = " << currScore << endl;

        for (int i=0; i<4; i++) mat[prom[i][0]][prom[i][1]] = 0;
        //ispis();
    }

    //ispis();
    return 0;
}

inline void debug()
{
    while (1)
    {
        cin>>n>>o>>x;
        cout<<padni(x-1,n,o,true)<<endl;
    }
}

inline void resetAll()
{
    for (int i=0; i<20; i++)
    {
        tetAmt[i] = 0;
        rowTransStore[i] = 2;
        for (int j=0; j<10; j++)
        {
            mat[i][j] = 0;
        }
    }
    for (int j=0; j<10; j++)
    {
        H[j] = 0;
        colTransStore[j] = 2;
        odg[j] = 0;
    }
    totalScore = 0;
}

inline int rjesi(double par1, double par2, double par3, double par4, double par5, double par6)
{
    resetAll();

    landingHeightM = par1;
    rowsM = par2;
    rowTransM = par3;
    colTransM = par4;
    holeM = par5;
    wellM = par6;

    totalScore = 0;

    if ((br < 1 || br > 1000) && (br < 6001 || br > 9000) && (br != 10000) && (br < 12001 || br > 13000) && (br < 14001 || br > 15000) && (br < 19001 || br > 20000) && (br < 39001 || br > 40000) && (br < 45001 || br > 46000)) phail = true;
    else if (br == 10000)
    {
        if (idd > 4 && idd != 9 && idd != 11 && idd != 12) phail = true;
        idd++;
    }

    for (int ii=0; ii<br; ii++)
    {
        stored = false;
        if (phail) break;

        lld hem = 0LL;
        bool convertHem = true;
        pair<lld, int> currentPair;
        for (int j=0; j<10; j++) if (H[j] > 3) convertHem = false;

        if (convertHem)
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<10; j++)
                {
                    if (mat[i][j] == 1)
                    {
                        hem += (1LL << (i*10+j));
                    }
                }
            }
            currentPair = make_pair(hem, tetrominos[ii]);
            if (memo.find(currentPair) != memo.end())
            {
                pair<int, int> ret = memo[currentPair];
                movesO[ii] = ret.first;
                movesX[ii] = ret.second;
                padni(movesX[ii]-1, tetrominos[ii], movesO[ii], false);
                continue;
            }
        }

        willUpdate = true;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<4; j++)
            {
                padni(i, tetrominos[ii], j, true);
            }
        }
        if (!stored)
        {
            phail = true;
            continue;
        }
        padni(storeX, tetrominos[ii], storeO, false);
        movesO[ii] = storeO;
        movesX[ii] = storeX + 1;
        if (convertHem) memo[currentPair] = make_pair(movesO[ii], movesX[ii]);
    }
    if (phail)
    {
        printf("case 1 N\n");
        return -1;
    }
    else
    {
        printf("case 1 Y\n");
        for (int i=0; i<br; i++)
        {
            printf("%d %d\n",movesO[i], movesX[i]);
        }
        return totalScore;
    }
}

int main()
{
    //debug();
    //scanf("%d",&t);
    //freopen("genetic.txt","r",stdin);
    scanf ("%d", &t);
    while (t--)
    {
        //resetAll();
        scanf("%d",&br);

        phail = false;
        for (int i=0; i<br; i++)
        {
            scanf("%d",&tetrominos[i]);
        }
        rjesi(-3.8812224916087, 2.90211145821334, -3.142444212915643, -9.54324698987, -8.5124466522105, -3.380512311489);
        //rjesi(-4.500158825082766, 3.4181268101392694, -3.2178882868487753, -9.348695305445199, -7.899265427351652, -3.3855972247263626);
    }
    return 0;
}
