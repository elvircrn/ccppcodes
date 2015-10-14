#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Tacka
{
public:
    double x,y;
    Tacka() {}
    Tacka(double _x, double _y):x(_x),y(_y) {}
    friend istream& operator>>(istream& xin, Tacka &t);
};

class TackaUConvexHullu: public Tacka
{
public:
    bool posjecena;
    TackaUConvexHullu():Tacka()
    {
        posjecena=false;
    }
};

istream& operator>>(istream& xin, Tacka &t)
{
    double a,b;
    xin>>a>>b;
    t.x=a;
    t.y=b;
    return xin;
}

ostream& operator<<(ostream& xout, Tacka t)
{
    xout<<t.x<<' '<<t.y;
    return xout;
}

bool bolji(const Tacka &t, const Tacka &a, const Tacka &b)
{
    return ((t.x-a.x)*(t.y-b.y)-(t.y-a.y)*(t.x-b.x)>0);
}

double bolji2(const Tacka &t, const Tacka &a, const Tacka &b)
{
    return ((t.x-b.x)*(t.y-a.y)-(t.y-b.y)*(t.x-a.x));
}

double euklidskaDaljina(const Tacka &a, const Tacka &b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}


int main()
{
    int n,prvi;
    cin>>n;
    vector<TackaUConvexHullu> t;
    for (int i=0; i<n; i++)
    {
        TackaUConvexHullu a;
        cin>>a;
        t.push_back(a);
    }

    vector<int> rjesenje;
    double miny(t[0].y);
    int minyy(0);
    for (int i=0; i<n; i++)
    {
        if(t[i].y<miny)
        {
            minyy=i;
            miny=t[i].y;
        }
    }

    rjesenje.push_back(minyy);
    t[minyy].posjecena=true;
    int zadnjaTacka(minyy);
    int startnaTacka(minyy);
    printf ("%d\n", zadnjaTacka);
    while((rjesenje.size()<n) && (1))
    {
        int gledanaTacka;
        for (int i=0; i<n; i++)
            if (!t[i].posjecena)
            {
                gledanaTacka=i;
                break;
            }


        for (int i=0; i<n; i++)
        {
            if (!t[i].posjecena)
            {
                if (bolji(t[zadnjaTacka],t[gledanaTacka],t[i]))gledanaTacka=i;
            }
        }
        printf ("%d %d\n", zadnjaTacka, gledanaTacka);
        if (bolji(t[zadnjaTacka],t[gledanaTacka],t[startnaTacka])) break;
        t[gledanaTacka].posjecena=true;
        rjesenje.push_back(gledanaTacka);
        zadnjaTacka=gledanaTacka;
    }

    double rjes(0);

    for (int i = 0; i < rjesenje.size(); i++)
        cout<<t [rjesenje [i]]<<endl;

    for (int i=1; i<rjesenje.size(); i++)
    {
        rjes+=euklidskaDaljina(t[rjesenje[i-1]],t[rjesenje[i]]);
    }
    rjes+=euklidskaDaljina(t[rjesenje.front()],t[rjesenje.back()]);

    printf ("%.2lf\n", rjes);

    return 0;
}
