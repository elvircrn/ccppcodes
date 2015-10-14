
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct tac
{
    int x,y;
    tac(int _x=0,int _y=0){x=_x;y=_y;}
};
vector<tac> red,blu;
vector<int> omr,omb;
int n,m;
bool poz(tac &t,tac &a,tac &b)
{
    if (t.x*(a.y-b.y)+a.x*(b.y-t.y)+b.x*(t.y-a.y)==0)return (a.x-t.x)*(a.x-t.x)+(a.y-t.y)*(a.y-t.y)<(b.x-t.x)*(b.x-t.x)+(b.y-t.y)*(b.y-t.y);
    int ax=a.x-t.x,ay=a.y-t.y,bx=b.x-t.x,by=b.y-t.y;
    return (ax*by-ay*bx>0);
}
double dist(tac &a,tac &b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    scanf("%d",&n);red.resize(n);
    int mino=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&red[i].x,&red[i].y);
        if (red[i].x<red[mino].x || (!(red[i].x-red[mino].x)&& red[i].y<red[mino].x))mino=i;
    }
    int tren=mino;
    omr.push_back(mino);
    while (1)
    {
        int rj=-1;
        for (int i=0;i<n;i++)
        {
            if (i==tren)continue;
            else
            {
                if (rj==-1)rj=i;
                else
                {
                    if (poz(red[tren],red[rj],red[i]))rj=i;
                }
            }
        }
        if (rj==mino ||rj==-1)break;
        omr.push_back(rj);tren=rj;
    }
    scanf("%d",&m);blu.resize(m);
    mino=0;
    for (int i=0;i<m;i++)
    {
        scanf("%d %d",&blu[i].x,&blu[i].y);
        if (blu[i].x<blu[mino].x || (!(blu[i].x-blu[mino].x)&& blu[i].y<blu[mino].x))mino=i;
    }
    tren=mino;
    omb.push_back(mino);
    while (1)
    {
        int rj=-1;
        for (int i=0;i<m;i++)
        {
            if (i==tren)continue;
            else
            {
                if (rj==-1)rj=i;
                else
                {
                    if (poz(blu[tren],blu[rj],blu[i]))rj=i;
                }
            }
        }
        if (rj==mino ||rj==-1)break;
        omb.push_back(rj);tren=rj;
    }
    double maxio=-1;
    for (int i=0;i<omr.size();i++)
        for (int j=0;j<omb.size();j++)
        {
            maxio=max(maxio,dist(blu[omb[j]],red[omr[i]]));
        }
    printf("%.3lf\n",(maxio));
    //for (int i=0;i<omr.size();i++)printf("%d ",omr[i]);
    return 0;
}
