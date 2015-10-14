#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    while (true) {
        vector <int> array;
        array.push_back (1); array.push_back (2); array.push_back (3);
        sort (array.begin(), array.end());
        for (int i = 0; i < 3; i++)
            cout<<array [i]<<" ";
        cout<<endl;
    }
    return 0;
}
