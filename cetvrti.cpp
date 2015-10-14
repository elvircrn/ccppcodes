#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef unsigned long long int ull;
ull gcd (ull a, ull b) {
    if (b == 0) return a;
    else return gcd (b, a % b);
}
ull Pow (ull base, int exp) {
    ull cnt = 1;
    for (ull i = 0; i < exp; i++) cnt *= base;
    return cnt;
}
ull to_dec (string arr) {
    ull decimalni = 0, stepen_dvojke = 1;
    for (int i = arr.length() - 1; i >= 0; i--){
        if (arr [i] == '1') decimalni += stepen_dvojke;
        //decimalni += ((arr[i] - '0') * stepen_dvojke);
        stepen_dvojke*= 2;
    }
    return decimalni;
}
ull hex_u_int (string str) {
    ull k = 0, val = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (isalpha (str [i])) val += (str [i] - 55) * (Pow (16, k));
        else val += (str [i] - 48) * (Pow (16, k));
        k++;
    }
    return val;
}
int main() {
    string xx, yy;
    ull x, y;
    cin>>xx>>yy;
    x = hex_u_int (xx);
    y = to_dec (yy);
    cout<<gcd (x, y)<<endl;
    return 0;
}
/*
1999999999999999
1100110011001100110011001100110011001100110011001100110011001

1999999999999999
1100110011001100110011001100110011001100110011001100110011001

*/
