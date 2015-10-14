#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

long long int l, r;

long long int gcd ( long long int a, long long int b )
{
  long long int c;
  while ( a != 0LL ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}


int main()
{
    cin>>l>>r;

    for (long long int i = l; i <= r; i++)
    {
        for (long long int j = l; j <= r; j++)
        {
            for (long long int k = l; k <= r; k++)
            {
                if (i == j || j == k || i == k || i > j || i > k || j > k)
                    continue;
                if (gcd (i, j) == 1 && gcd (j, k) == 1 && gcd (i, k) != 1)
                {
                    cout<<i<<' '<<j<<' '<<k<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"-1\n";

    return 0;
}










/*
░░░░░░░░░░░░▄▐
░░░░░░▄▄▄░░▄██▄
░░░░░▐▀█▀▌░░░░▀█▄
░░░░░▐█▄█▌░░░░░░▀█▄
░░░░░░▀▄▀░░░▄▄▄▄▄▀▀     you have been spooked by the spooky skeleton
░░░░▄▄▄██▀▀▀▀
░░░█▀▄▄▄█░▀▀
░░░▌░▄▄▄▐▌▀▀▀
*/
