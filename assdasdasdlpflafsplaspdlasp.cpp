#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char c1, c2, temp, a[5];
int C1, C2;

int main()
{
    cin>>c1;
    cin>>c2;
    if( c1 == c2){ printf("%c%c%c%c\n", c1, c1, c1, c1); return 0; }
    if( c1 > c2){ temp= c1; c1= c2; c2= temp; }
    C1= (int)c1;
    C2= (int)c2;
    for( int i=C1; i<=C2; ++i){
        for( int j=C1; j<=C2; ++j){
            for( int l=C1; l<=C2; ++l){
                for( int k=C1; k<=C2; ++k) {
                    a [0] = char (i);
                    a [1] = char (j);
                    a [2] = char (l);
                    a [3] = char (k);
                    puts (a);
                }
            }
        }
    }
    return 0;
}
