#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
int takmicari [ 100 ] [ 80000 ], d = -1, in, i, j, x, y, start;
int main () {
    //freopen ( "takmicari.txt", "r", stdin );
    while ( 1 ) {
          scanf ( "%d", &in );
          if ( in == 0 ) {
              cin>>x>>start;
              d++;
             }
          if ( in == 3 ) break;
          if ( in == 1 ) {
               cin>>x>>y;
               takmicari [ d ] [ x ] += y;
               }
          if ( in == 2 ) {
               cin>>x;
               cout<<takmicari [ d ] [ x ] + start<<endl;
               }
          }
    return 0;
}
