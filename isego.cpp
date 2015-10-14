#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

#define N 1030

int fenwick[N][N];

inline int read_int()
{
    int num;
    char c;
    while(!isdigit(c=getchar()));
    num=c-'0';
    while(isdigit(c=getchar()))num=num*10+c-'0';
    return num;
}



inline void updatey(int x,int y,int val)
{
    for(int i=y;i<N;i+=i&-i)
    {
        fenwick[x][i]+=val;
    }
}
inline void update_all(int x,int y,int val)
{
    for(int i=x;i<N;i+=i&-i)
    {
        updatey(i,y,val);
    }
}

inline int gety(int x,int y)
{
    int ans=0;
    for(int i=y;i>0;i-=i&-i)ans+=fenwick[x][i];
    return ans;
}


inline int get(int x,int y)
{
    int ans=0;
    for(int i=x;i>0;i-=i&-i)
    {
        ans+=gety(i,y);
    }
    return ans;
}




int main(void)
{
    int i,j,n,m,x,y,a,b,val;
    n=read_int();
    string S;
    while(1)
    {
        cin>>S;
        if(S=="END")break;
        else if(S=="SET")
        {
            scanf("%d %d %d",&x,&y,&val);
            update_all(x+2,y+2,val);
        }
        else if(S=="SUM")
        {
            scanf("%d %d %d %d",&a,&b,&x,&y);
            printf("%d\n",get(x+2,y+2)-get(a+1,b+1));
        }
    }
    return 0;
}

