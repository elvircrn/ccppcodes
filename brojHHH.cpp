#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string input, firstsolution, secondsolution;
int array [20], carray [20], odd, even;
bool compare ( string a, string b ) {
    if ( a == b ) return 0;
    if ( a [ 0 ] == '-' && isdigit ( b [ 0 ] ) == 1 ) return 1;
    if ( b [ 0 ] == '-' && isdigit ( a [ 0 ] ) == 1 ) return 0;
    if ( a.length() > b.length() ) return 0;
    if ( a.length() < b.length() ) return 1;
    if ( a [ 0 ] == '-' && b [ 0 ] == '-' ) {
        for ( int i = 0; i < a.length(); i++ ) {
            if ( int ( a [ i ] ) < int ( b [ i ] ) ) return 0;
            if ( int ( a [ i ] ) > int ( b [ i ] ) ) return 1;
        }
    }
    else if ( a.length() < b.length() ) return 1;
        for ( int i = 0; i < a.length(); i++ ) {
            if ( int ( a [ i ] ) > int ( b [ i ] ) ) return 0;
            if ( int ( a [ i ] ) < int ( b [ i ] ) ) return 1;
        }
    return 0;
}
int main () {
    //freopen ("brojhhh.txt", "r", stdin);
    cin>>input;
    for (int i = 0; i < input.length(); i++) {
        array [input [i] - '0']++;
        carray [input [i] - '0'] = array [input [i] - '0'];
        if (input [i] - '0' % 2 == 0) even++;
        else odd++;
    }
    for (int i = 1; i <= input.length(); i++) {
        for (int j = 9; j >= 0; j--) {
            //if (j == 0 && i == 1) goto l1;
            if (i % 2 == 1 && j % 2 == 1 && array [j]) {
                array [j]--;
                firstsolution += (char (j + 48));
                goto l1;
            }
            else if (i % 2 == 0 && j % 2 == 0 && array [j]) {
                //cout<<i<<endl;
                array [j]--;
                firstsolution += (char (j + 48));
                goto l1;
            }
            if (!j) goto end;
        }
            l1:;
    }
    end:;
    for (int i = 0; i < input.length(); i++) {
        for (int j = 9; j >= 0; j--) {
            //if (j == 0 && i == 1) goto l1;
            if (i % 2 == 1 && j % 2 == 1 && carray [j]) {
                carray [j]--;
                secondsolution += (char (j + 48));
                goto l12;
            }
            else if (i % 2 == 0 && j % 2 == 0 && carray [j]) {
                //cout<<i<<endl;
                carray [j]--;
                secondsolution += (char (j + 48));
                goto l12;
            }
            if (!j) goto end1;
        }
            l12:;
    }
    end1:;
    if (!compare (firstsolution, secondsolution)) cout<<firstsolution<<endl;
    else cout<<secondsolution<<endl;
    return 0;
}
