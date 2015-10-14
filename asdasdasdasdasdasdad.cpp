#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <math.h>
using namespace std;

#define SIZE 1000001

static unsigned short table[SIZE];

unsigned short calcCycleLength( register unsigned long n )
{
        if(n < SIZE && table[n])
                return table[n];
        if(n & 1)
        { /* if n is odd */
                 if( n < SIZE)
                 {
                         /* calc two steps at one */
                         table[n] = 2 + calcCycleLength( (3*n+1) >> 1 );
                         return table[n];
                 }
                 else
                 {
                          return 2 + calcCycleLength( (3*n+1) >> 1 );
                  }
         }
         else
        {
                  if( n < SIZE)
                 {
                          table[n] = 1 + calcCycleLength( n >> 1 ); /* n/2 */
                          return table[n];
                 }
                 else
                 {
                          return 1 + calcCycleLength( n >> 1 );
                  }
        }
}

int main()
{
        unsigned long fn = 0;
        unsigned long sn = 0;
        unsigned long i;
        short out = 0, temp;
        table[1] = 1;
        while(cin>>fn>>sn)
        {
                 if( fn > sn)
                {
                        for( i = sn; i <= fn; ++i )
                        {
                                 temp = calcCycleLength( i );
                                 if( temp > out)
                                         out = temp;
                         }
                }
                else
                {
                        for( i = fn; i <= sn; ++i )
                       {
                                temp = calcCycleLength( i );
                                if( temp > out)
                                        out = temp;
                        }
                }
                cout<< fn<<" "<< sn<<" "<< out<<endl;
                out = 0;
        }
        return 0;
}
