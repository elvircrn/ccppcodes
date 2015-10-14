#include <iostream>
using namespace std;
int xx, yy;
int x [10], y [10];
int array1 [1000], array2 [1000];
int main () {
    for (int i = 0; i < 3; i++) cin>>x [i]>>y [i];
    for (int i = 0; i < 3; i++) {
        bool foundx = false, foundy = false;
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if (x [i] == x [j]) foundx = true;
            if (y [i] == y [j]) foundy = true;
        }
        if (!foundx) xx = x [i];
        if (!foundy) yy = y [i];
    }
    cout<<xx<<" "<<yy<<endl;
    return 0;
}
