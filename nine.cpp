#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int t, n;
char c;

bool used [300] [20];

int countt [100], count2 [100], array [10000], solution;
vector <int> permute;

int main () {

    scanf ("%d", &t);

    while (t--) {

        solution = 0;

        for (int i = 0; i < 11; i++)
            countt [i] = 0;

        n = 1;

        while (!isdigit (c = getchar()));
        array [0] = c - '0';
        used [t] [c - '0'] = true;
        countt [c - '0']++;

        while (isdigit (c = getchar())) {
            array[n] = c - '0';
            countt [c - '0']++;
            n++;
        }

        for (int i = 0; i < 10; i++) used [t] [i] = 0;

        //one
        for (int i = 9; i <= 9; i++) {
            int sum = i;
            if (sum % 9 != 0 && sum) continue;
            vector <int> asd;
            asd.push_back (i);
            sum = asd [0];
            for (int ii = 0; ii <= 9; ii++) count2 [ii] = 0;
            for (int ii = 0; ii <= 0; ii++) count2 [asd [ii]]++;
            if (used [t] [sum] == false) {
                used [t] [sum] = true;
                solution += countt [asd [0]] / count2 [asd [0]];
            }
        }

        //two
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 10; j++) {
                int sum = i + j;
                if (sum % 9 != 0 && sum) continue;
                vector <int> asd;
                asd.push_back (i);
                asd.push_back (j);
                sort (asd.begin(), asd.end());
                sum = asd [1] * 10 + asd [0];
                for (int ii = 0; ii <= 9; ii++) count2 [ii] = 0;
                for (int ii = 0; ii <= 1; ii++) count2 [asd [ii]]++;
                if (used [t] [sum] == false) {
                    used [t] [sum] = true;
                    solution += min (countt [asd [1]] / count2 [asd [1]], countt [asd [0]] / count2 [asd [0]]);
                }
            }
        }

        for (int i = 0; i < 10; i++) used [t] [i] = 0;

        //three
        for (int i = 0; i <= 7; i++) {
            for (int j = i + 1; j <= 8; j++) {
                for (int k = j + 1; k <= 9; k++) {
                    int sum = i + j + k;
                    if (sum % 9 != 0 && sum) continue;
                    vector <int> asd;
                    asd.push_back (i);
                    asd.push_back (j);
                    asd.push_back (k);
                    sort (asd.begin(), asd.end());
                    sum = asd [2] * 100 + asd [1] * 10 + asd [0];
                    for (int ii = 0; ii <= 9; ii++) count2 [ii] = 0;
                    for (int ii = 0; ii <= 2; ii++) count2 [asd [ii]]++;
                    if (used [t] [sum] == false) {
                        used [t] [sum] = true;
                        solution += min (countt [asd [2]] / count2 [asd [2]],
                                            min (countt [asd [1]] / count2 [asd [1]], countt [asd [0]] / count2 [asd [0]]));
                    }
                }
            }
        }

        for (int i = 0; i < 10; i++) used [t] [i] = 0;

        //four
        for (int i = 0; i <= 6; i++) {
            for (int j = i + 1; j <= 7; j++) {
                for (int k = j + 1; k <= 8; k++) {
                    for (int l = k + 1; l <= 9; l++) {
                        int sum = i + j + k + l;
                        if (sum % 9 != 0 && sum) continue;
                        vector <int> asd;
                        asd.push_back (i);
                        asd.push_back (j);
                        asd.push_back (k);
                        asd.push_back (l);
                        sort (asd.begin(), asd.end());
                        sum = asd [3] * 1000 + asd [2] * 100 + asd [1] * 10 + asd [0];
                        for (int ii = 0; ii <= 9; ii++) count2 [ii] = 0;
                        for (int ii = 0; ii <= 3; ii++) count2 [asd [ii]]++;
                        if (used [t] [sum] == false) {
                            used [t] [sum] = true;
                            solution += min (min (countt [asd [3]] / count2 [asd [3]], countt [asd [2]] / count2 [asd [2]]),
                                             min (countt [asd [1]] / count2 [asd [1]], countt [asd [0]] / count2 [asd [0]]));
                        }
                    }
                }
            }
        }

        printf ("%d\n", solution);
    }

    return 0;
}
