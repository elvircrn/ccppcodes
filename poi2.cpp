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

const int maxbuff = 10000;
int pos = maxbuff;
char buff[ maxbuff ];
inline char read_char () {
       if ( pos == maxbuff ) {
            fread ( buff, 1, maxbuff, stdin );
            pos = 0;
       }
       return buff[ pos++ ];
}
inline int read_int () {
    char c;
    int a;
    while ( !isdigit ( c = read_char () ) );
    a = c - '0';
    while ( isdigit ( c = read_char () ) ) a = a * 10 + ( c - '0' );
    return a;
}

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

int n, t, p, Q, P, score_task [3000], p1, p2, p3, solved [3000], S;
vector <competitor> competitors;
vector <int> input [3000];

int PERO_POSITION;

int main () {

    n = read_int();
    t = read_int();
    p = read_int();

    for (int i = 0; i < 3000; i++)
        score_task [i] = n;

    PERO_POSITION = n;

    char a, b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            Q = read_int();
            input [i].push_back (Q);
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
