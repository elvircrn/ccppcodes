#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int N, a;
vector <int> stepenice;
bool used [4000];
int dp [1100], CC [1100];

int main () {

    cin>>N;
    for (int i = 0; i < N; i++) {

        scanf ("%d", &a);
        CC [i] = a;

        if (!used [a])
            stepenice.push_back (a);

    }

    sort (stepenice.begin(), stepenice.end());

    for (int i = 0; i < stepenice.size(); i++) {
        bool found = true;
        int ind = 0;
        cout<<CC [0]<<" "<<stepenice [i]<<endl;
        if (CC [0] - stepenice [i] == 0) goto l1;
        //else if (CC [1] - stepenice [i] <= 0) ind = 1;
        else continue;
        while (ind < N) {
            int p = ind;
            if (CC [ind + 1] - stepenice [i] > 0 || ind + 1 == N) ind++;
            else if (CC [ind + 2] - stepenice [i] > 0 || ind + 2 == N) ind += 2;
            else {found = false; break;}
        }
        l1:;
        if (found) {
            cout<<stepenice [i]<<endl;
            return 0;
        }
    }

    return 0;

}
