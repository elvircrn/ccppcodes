#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int serve = 1;
bool gamess;
struct player {
    int point, game, set, serve;
    player () {point = game = set = serve = 0;}
} player1, player2;
struct match {
    int player1, player2;
    match () {player1 = 0; player2 = 0;}
} match;
string Match;
char a;
int my (int x) {
    if (x < 0) return x * (-1);
    else return x;
}
int main () {
    //freopen ("tenis.txt", "r", stdin);
    cin>>Match;
    int len = Match.length();
    for (int i = 0; i < len; i++) {
        a = Match [i];
        if (serve == 1) {
            if (a == 'S') {
                player1.point++;
                //new game
                if (player1.point > 3 && my (player1.point - player2.point) > 1) {
                    player1.game++;
                    gamess = 1;
                    //new set
                    player1.point = 0;
                    player2.point = 0;
                    if (player1.game > 5 && my (player1.game - player2.game) > 1) {
                        printf ("%d %d\n", player1.game, player2.game);
                        player1.game = 0;
                        player2.game = 0;
                        player1.set++;
                        gamess = 0;
                    }
                    serve = 2;
                    goto newpoint;
                }
            }
            else {
                player2.point++;
                //new game
                if (player2.point > 3 && my (player1.point - player2.point) > 1) {
                    player2.game++;
                    gamess = 1;
                    //new set
                    player1.point = 0;
                    player2.point = 0;
                    if (player2.game > 5 && my (player1.game - player2.game) > 1) {
                        printf ("%d %d\n", player1.game, player2.game);
                        player1.game = 0;
                        player2.game = 0;
                        player2.set++;
                        gamess = 0;
                    }
                    serve = 2;
                    goto newpoint;
                }
            }
        }
        else if (serve == 2) {
            if (a == 'P') {
                player1.point++;
                //new game
                if (player1.point > 3 && my (player1.point - player2.point) > 1) {
                    player1.game++;
                    gamess = 1;
                    //new set
                    player1.point = 0;
                    player2.point = 0;
                    if (player1.game > 5 && my (player1.game - player2.game) > 1) {
                        printf ("%d %d\n", player1.game, player2.game);
                        player1.game = 0;
                        player2.game = 0;
                        player1.set++;
                        gamess = 0;
                    }
                    serve = 1;
                    goto newpoint;
                }
            }
            else {
                player2.point++;
                //new game
                if (player2.point > 3 && my (player1.point - player2.point) > 1) {
                    player2.game++;
                    gamess = 1;
                    //new set
                    player1.point = 0;
                    player2.point = 0;
                    if (player2.game > 5 && my (player1.game - player2.game) > 1) {
                        printf ("%d %d\n", player1.game, player2.game);
                        player1.game = 0;
                        player2.game = 0;
                        player2.set++;
                        gamess = 0;
                    }
                    serve = 1;
                    goto newpoint;
                }
            }
        }
        newpoint:;
        //printf ("%d: %d %d\n", i, player1.point, player2.point);
    }

    if (!gamess) printf ("0 0\n");
    if (player1.game || player2.game) printf ("%d %d\n", player1.game, player2.game);
    return 0;
}
