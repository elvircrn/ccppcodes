#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
string a, sol [1001], cnt [1001];
int n;
int main () {
    cin>>a;
    for (int i = 0; i < a.length(); i++) {
            int z = int (a [i]) - 48;
            if (i == 0) {
                if (z == 1) cnt [i] = "M";
                if (z == 2) cnt [i] = "MM";
                else if (z == 3) cnt [i] = "MMM";
            }
            else if (i == 2) {
                if (z == 3) cnt [i] = "II";
                else if (z == 3) cnt [i] = "III";
                else if (z == 4) cnt [i] = "IV";
                else if (z == 5) cnt [i] = "V";
                else if (z == 6) cnt [i] = "VI";
                else if (z == 7) cnt [i] = "VII";
                else if (z == 8) cnt [i] = "VIII";
                else if (z == 9) cnt [i] = "IX";
            }
            else if (i == 2) {
                if (z == 1) cnt [i] = "X";
                else if (z == 2) cnt [i] = "XX";
                else if (z == 3) cnt [i] = "XXX";
                else if (z == 4) cnt [i] = "XL";
                else if (z == 5) cnt [i] = "L";
                else if (z == 6) cnt [i] = "LX";
                else if (z == 7) cnt [i] = "LXX";
                else if (z == 8) cnt [i] = "LXXX";
                else if (z == 9) cnt [i] = "XC";
            }
            else if (i == 1) {
                if (z == 1) cnt [i] = "C";
                else if (z == 2) cnt [i] = "CC";
                else if (z == 3) cnt [i] = "CCC";
                else if (z == 4) cnt [i] = "CD";
                else if (z == 5) cnt [i] = "D";
                else if (z == 6) cnt [i] = "DC";
                else if (z == 7) cnt [i] = "DCC";
                else if (z == 8) cnt [i] = "DCCC";
                else if (z == 9) cnt [i] = "CM";
            }
    }
    for (int i = 0; i < a.length(); i++) {
        cout<<cnt [i];
    }
    return 0;
}
