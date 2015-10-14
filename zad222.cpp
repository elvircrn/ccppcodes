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
        bool found = false;
        int ind = N - 1;
        if (CC [N - 1] - stepenice [i] <= 0) {
            found = true;
            goto l1;
        }
        while (ind >= 0) {
            int p = ind;
            if (ind - 1 == -1 || ind - 2 == -1) break;
            if (CC [ind - 2] - stepenice [i] > 0 || ind - 2 == N) ind -= 2;
            else if (CC [ind - 1] - stepenice [i] > 0 || ind - 1 == N) ind--;
            else {found = true; break;}
        }
        l1:;
        if (found) {
            cout<<stepenice [i]<<endl;
            return 0;
        }
    }

    return 0;

}
