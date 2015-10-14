#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

class par {
    public: int x, y;
    par () {}
    par (int _x, int _y) {x = _x; y = _y;}
};

int getRandomInt () {
    return (rand () % 10 + 1);
}

int getRandomDirection () {
    return (rand () % 2);
}

class FIELD {
    public: int field [30] [30], ships [10], shipcount;
    FIELD () {
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                field [i] [j] = 0;
        shipcount = 7;
        ships [1] = ships [2] = 2;
        ships [3] = ships [4] = 3;
        ships [5] = ships [6] = 4;
        ships [7] = 5;
        vector <par> parovi;
        while (parovi.size()) parovi.pop_back ();
        bool found, gore, dole;
        found = gore = dole = false;
        int shipcountforsetting = 7, ind = 1, A, B, D;
        while (shipcountforsetting) {
            int COPY = ships [ind] - 1;
            while (field [A = getRandomInt()] [B = getRandomInt()]);
            D = getRandomDirection ();
            if (D) {
                for (int i = 1; i <= ships [ind]; i++) {
                    if (field [A - i - 1] [B] || field [A - i] [B] || !(A - i) || field [A - i] [B - 1] || field [A - i] [B + 1]) gore = true;
                    if (field [A + i + 1] [B] || field [A + i] [B] || (A + i) > 10 || field [A + i] [B - 1] || field [A + i] [B + 1]) dole = true;
                    if (not gore) {parovi.push_back (par (A - i, B)); COPY--;}
                    if (!COPY) {found = true; break;}
                    if (not dole) {parovi.push_back (par (A + i, B)); COPY--;}
                    if (!COPY) {found = true; break;}
                }
                if (found) {
                    for (int i = parovi.size() - 1; i >= 0; i--) {
                        field [parovi [i].x] [parovi [i].y] = ind;
                        parovi.pop_back();
                    }
                    field [A] [B] = ind;
                    shipcountforsetting--; ind++;
                    gore = dole = found = false;
                    goto l1;
                }
            }
            else {
                for (int i = 1; i <= ships [ind]; i++) {
                        if (field [A] [B - i - 1] || field [A] [B - i] || !(B - i)) gore = true;
                        if (field [A] [B + i + 1] || field [A] [B + i] || (B + i) > 10) dole = true;
                        if (not gore) {parovi.push_back (par (A, B - i)); COPY--;}
                        if (!COPY) {found = true; break;}
                        if (not dole) {parovi.push_back (par (A, B + i)); COPY--;}
                        if (!COPY) {found = true; break;}
                    }
                    if (found) {
                        for (int i = parovi.size() - 1; i >= 0; i--) {
                            field [parovi [i].x] [parovi [i].y] = ind;
                            parovi.pop_back();
                        }
                        field [A] [B] = ind;
                        shipcountforsetting--; ind++;
                        gore = dole = found = false;
                        goto l1;
                    }
            }
            if (!found) {
                if (!D) {
                    for (int i = 1; i <= ships [ind]; i++) {
                        if (field [A - i - 1] [B] || field [A - i] [B] || !(A - i)) gore = true;
                        if (field [A + i + 1] [B] || field [A + i] [B] || (A + i) > 10) dole = true;
                        if (!gore) {parovi.push_back (par (A - i, B)); COPY--;}
                        if (!COPY) {found = true; break;}
                        if (!dole) {parovi.push_back (par (A + i, B)); COPY--;}
                        if (!COPY) {found = true; break;}
                    }
                    if (found) {
                        for (int i = parovi.size() - 1; i >= 0; i--) {
                            field [parovi [i].x] [parovi [i].y] = ind;
                            parovi.pop_back();
                        }
                        field [A] [B] = ind;
                        shipcountforsetting--; ind++;
                        gore = dole = found = false;
                        goto l1;
                    }
                }
                else {
                    for (int i = 1; i <= ships [ind]; i++) {
                        if (field [A] [B - i - 1] || field [A] [B - i] || !(B - i)) gore = true;
                        if (field [A] [B + i + 1] || field [A] [B - i] ||(B + i) > 10) dole = true;
                        if (not gore) {parovi.push_back (par (A, B - i)); COPY--;}
                        if (!COPY) {found = true; break;}
                        if (not dole) {parovi.push_back (par (A, B + i)); COPY--;}
                        if (!COPY) {found = true; break;}
                    }
                    if (found) {
                        for (int i = parovi.size() - 1; i >= 0; i--) {
                            field [parovi [i].x] [parovi [i].y] = ind;
                            parovi.pop_back();
                        }
                        field [A] [B] = ind;
                        shipcountforsetting--; ind++;
                        gore = dole = found = false;
                        goto l1;
                    }
                    else {
                        while (parovi.size()) parovi.pop_back ();
                        gore = dole = false;
                    }
                }
            }
            l1:;
        }
    }
    public: void print_f () {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                cout<<field [i] [j]<<" ";
            }
            cout<<endl;
        }
    }
};

class player {

    public: FIELD Field;
    public: int ships [10], player_ind, ship_count, field_count;
    public: string hitmarkers [40] [40];

    public: void is_lost () {

        if (!ship_count) printf ("Plyer %d lost.\n", player_ind);
        return;

    }

    player () {}

    player (int pI) {

        for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        hitmarkers [i] [j] = '0';

        player_ind = pI;
        ship_count = 7;
        field_count = 23;

        ships [1] = ships [2] = 2;
        ships [3] = ships [4] = 3;
        ships [5] = ships [6] = 4;
        ships [7] = 5;

        Field = FIELD ();

    }

    public: void print_hitmarkers () {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                cout<<hitmarkers [i] [j]<<" ";
            }
            printf ("\n");
        }
    }

    public: void print_matrix () {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                printf ("%d ", Field.field [i] [j]);
            }
            printf ("\n");
        }
    }

};

vector <player> PLAYER (20);

class game {

    public: int n_moves;

    public: game () {
        n_moves = 0;
        printf ("Let the games begin!\n");
        PLAYER [1] = player (1);
        PLAYER [2] = player (2);
    }

    public: void make_move (int pIND) {

        int opposing_ind;
        if (pIND == 1) opposing_ind = 2;
        else opposing_ind = 1;

        int x;
        int y;

        scanf ("%d%d", &x, &y);

        if (!PLAYER [opposing_ind].Field.field [x] [y]) {PLAYER [opposing_ind].hitmarkers [x] [y] = 'o'; printf ("MISS!\n"); return;}

        else if (!(PLAYER [opposing_ind].ships [PLAYER [opposing_ind].Field.field [x] [y] - 1])) {printf ("A SHIP JUST DIED BECAUSE OF YOU!\n");}

        else {printf ("HIT!\n");}

        PLAYER [opposing_ind].hitmarkers [x] [y] = 'x';
        PLAYER [opposing_ind].ships [PLAYER [opposing_ind].Field.field [x] [y]]--;
        PLAYER [opposing_ind].Field.field [x] [y] = 0;
        PLAYER [opposing_ind].ship_count--;

        PLAYER [opposing_ind].is_lost();

        return;

    }

    public: void game_start () {

        int i = 0;

        while (true) {

            printf ("PLAYER %d 's choices: \n", i % 2 + 1);

            if ((i % 2 + 1) == 1) PLAYER [2].print_hitmarkers ();
            else PLAYER [1].print_hitmarkers ();

            printf ("Player %d is on the move: ", i % 2 + 1);

            make_move (i % 2 + 1); i++;

            system ("PAUSE");
            system ("CLS");

        }

    }

};

int main () {

    srand (time (0));

    game Game = game ();
    PLAYER [1].Field.print_f ();
    //Game.game_start ();

    return 0;

}
