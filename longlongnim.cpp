#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int mask = 0;
bool win [10000];

class LongLongNim
{
public:

    int numberOfWins(int maxN, vector <int> moves)
    {
        memset (win, false, sizeof win);

        sort (moves.begin(), moves.end());

        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < moves.size(); j++)
            {
                if (i - moves [j] < 0)
                    break;
                else if (i - moves [j] == 0 || !win [i - moves [j]])
                    win [i] = true;
            }
        }

        for (int i = 0; i < 100; i++)
            printf ("%3d", i); printf ("\n");
        for (int i = 0; i < 100; i++)
            printf ("%3d", win [i]);

        /*printf ("\n\n\n\n");

        for (int i = 26; i < 50; i++)
            printf ("%3d", i); printf ("\n");
        for (int i = 26; i < 50; i++)
            printf ("%3d", win [i]);*/

        return 0;
    }
};

int main()
{
    freopen ("in.txt", "r", stdin);
    char in [1000];

    scanf ("%[^\n]", &in);

    cout<<in [strlen (in) - 1]<<endl;

    /*freopen ("out.txt", "w", stdout);
    LongLongNim asd;

    vector <int> moves;

    moves.push_back(2);
    moves.push_back(4);
    moves.push_back(7);
    moves.push_back(11);

    asd.numberOfWins(1231, moves);*/

    return 0;
}
//1111111111111111111111
