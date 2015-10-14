#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef unsigned long long int ull;
ull to_dec (string arr) {
    string decimalni;
    ull stepen_dvojke = 1;
    for (int i = arr.length() - 1; i >= 0; i--){
        if (arr [i] == '1') decimalni += stepen_dvojke;
        //decimalni += ((arr[i] - '0') * stepen_dvojke);
        stepen_dvojke*= 2;
    }
    return decimalni;
}
