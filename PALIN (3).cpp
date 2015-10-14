#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string x, y [ 10000 ], sol, m;
int cnt = 0, len, len1, len2;
int main () {
    cin>>x;
    len = x.length();
    len1 = len;
    len2 = len1;
    for ( int i = len - 1; i >= 0; i-- ) {
        m = x [ i ];
        y [ cnt ] = m;
        cnt++;
    }
    /*for ( int i = 0; i < len; i++ ) {
        m = x [ i ];
        if ( m != y [ i ] ) goto startuj;
    }
    cout<<x<<endl;
    return 0;*/
    startuj:;
    cnt = 0;
    while ( cnt < len ) {
        len1 = 0;
        for ( int i = cnt; i < len; i++ ) {
            m = x [ i ];
            if ( m != y [ len1 ] ) goto novi;
            len1++;
        }
        cout<<x;
        for ( int i = cnt - 1; i >= 0; i-- ) cout<<x [ i ];
        cout<<endl;
        return 0;
        novi:;
        cnt++;
    }
    return 0;
}
