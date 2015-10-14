#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    int cnt = 1, x, i;
    scanf ( "%d", &x );
    int a = sqrt ( x );
    if (x % 2 == 0) printf ("%d\n", x / 2);
    for ( i = (x + 1) / 3; i >= a - 5; i-- ) {
        if ( x % i == 0 ) {
             printf ( "%d \n", x - i );
             return 0;
             }
        cnt++;
        }
     printf ( "%d \n", x - 1 );
     //system ( "PAUSE" );
     return 0;
}
