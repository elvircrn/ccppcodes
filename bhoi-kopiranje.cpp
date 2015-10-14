#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int knjige[10000005];

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d",&knjige[i]);
    //binarna pretraga za optimalnim brojem
    long long high = 100000000000ll;
    long long low = 1,mid;

    long accu;
    int j;

    while (low < high)
    {
        mid = (high + low) / 2;
        accu = 0;

        j = 0;
        for(int i=0; i<n && j<m; i++)
        {
            while(knjige[i]+accu > mid && j<m)
            {
                accu=0;
                j++;
            }
            accu += knjige[i];
        }
        if (j >= m)
            low = mid + 1;
        else
            high = mid;
    }
    //greedy dodjela
    long copy = high;
    vector<int> start(m,-1);

    accu = 0;

    int current = m - 1;
    for(int i = n -1; i>= 0; i--)
    {
        if(accu+knjige[i]>copy)
        {
            start[current] = i+1;
            accu = 0;
            current --;
        }
        accu+=knjige[i];
    }

    start[current] = 0;
    int top = 0;
    for(int i=0; i<start.size(); i++)
    {
        if(start[i]==-1)
            start[i] = top++;
    }

    for(int i=0; i<start.size()-1; i++)
    {
        if (start[i] >= start[i + 1])
            start[i + 1] += (start[i] - start[i + 1] + 1);
    }

    //ispisivanje

    int next;
    for (int i = 0; i < start.size(); i++)
    {
        next = n;
        if (i + 1 < start.size())
            next = start[i + 1];
        for (int j = start[i]; j < next; j++)
        {
            printf("%d",knjige[j]);
            if(j< next -1 || i<start.size()-1) printf(" ");
        }
        if(i < start.size()-1) printf("/ ");
    }
    printf("\n");
    return 0;
}











