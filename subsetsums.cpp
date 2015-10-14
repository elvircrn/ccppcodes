#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long int
#define ull unsigned long long int

vector <int> first;
vector <int> second;

vector <int> firstS;
vector <int> secondS;

int N, A, B, array [100], SOLUTION;

void iterate (int ind, int start, int end, int current, bool *visited) {

    if (current == end + 1) {
        int cnt = 0;
        for (int i = start; i <= end; i++)
            if (visited [i] == true)
                cnt += array [i];
        if (ind == 0)
            first.push_back (cnt);
        else
            second.push_back (cnt);
    }
    else {
        visited [current] = true;
        iterate (ind, start, end, current + 1, visited);
        visited [current] = false;
        iterate (ind, start, end, current + 1, visited);
    }
}

void BinarySearch (int X) {

    int left = 0, right = second.size(), pivot;

    #ifndef LEFT_BOUND
    while (left <= right) {
        pivot = (left + right) / 2;
        if (X + second [pivot] >= A && X + second [pivot - 1] + X < A) break;
        else if (X + second [pivot] >= A) pivot = right - 1;
        else pivot = left + 1;
    }
    #endif

    printf ("%d\n", pivot);

    #ifndef RIGHT_BOUND

    #endif


}

int main () {

    bool visited [100]; memset (visited, sizeof visited, false);

    #ifndef PARSE_INPUT
        scanf ("%d %d %d", &N, &A, &B);
        for (int i = 0; i < N; i++)
            scanf ("%d", &array [i]);
        for (int i = 0; i < N / 2; i++)
            first.push_back (i);
        for (int i = N / 2; i < N; i++)
            second.push_back (array [i]);
        iterate (0, 0, N / 2 - 1, 0, visited);
        memset (visited, sizeof visited, false);
        iterate (1, N / 2, N - 1, N / 2, visited);
    #endif

    sort (second.begin(), second.end());

    //#define DEBUG
    #ifndef DEBUG
    for (int i = 0; i < first.size(); i++) {
        printf ("first [%d]: %d\n", i, first [i]);
    }
    printf ("<------------------------------>\n");
    for (int i = 0; i < second.size(); i++) {
        printf ("second [%d]: %d\n", i, second [i]);
    }
    printf ("<------------------------------>\n");
    #endif

    return 0;
}
/*
    3 -1 2
    1
    -2
    3
*/
