#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

struct competitor {

    int score, n_tasks, ID;

    competitor () {}
    competitor (int a, int b, int c) {score = a; n_tasks = b; ID = c;}

    bool operator < (const competitor & xx) const {
        if (score != xx.score)
            return score > xx.score;
        else if (n_tasks != xx.n_tasks)
            return n_tasks > xx.n_tasks;
        else
            return ID < xx.ID;
    }

};

int n, t, p, Q, P, score_task [2010], p1, p2, p3, solved [2010], S;
vector <competitor> competitors;
bool input [2010] [2010];

int PERO_POSITION;
char a, c;

int main () {

    scanf ("%d %d %d", &n, &t, &p); getchar();

    for (int i = 0; i < 2008; i++)
        score_task [i] = n;

    PERO_POSITION = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            a = getchar(); getchar(); //if (i != n - 1 && j != t - 1) getchar();
            Q = a - '0';
            if (Q == 1) {
                input [i] [j] = true;
                score_task [j]--;
                solved [i]++;
            }
        }
    }

    for (int j = 0; j < t; j++) {
        if (input [p - 1] [j] == 1) {
            S += score_task [j];
            P++;
        }
    }

    competitor Pero = competitor (S, P, p);

    for (int i = 0; i < n; i++) {
        S = 0, P = 0;
        if (i == p - 1)
            continue;
        for (int j = 0; j < t; j++) {
            if (input [i] [j] == 1) {
                S += score_task [j];
                P++;
            }
        }
        competitor cmp = competitor (S, P, i + 1);
        if (!(cmp < Pero)) PERO_POSITION--;
    }

    printf ("%d %d\n", Pero.score, PERO_POSITION);

    return 0;

}

//2432902008176640000
