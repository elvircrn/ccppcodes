#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool init;
FILE *outbrute;
FILE *outsol;

char matrix [100] [100];

//outbrute outsol
bool compare()
{
    if (!init)
    {
        init = true;
        return true;
    }
    outbrute = fopen ("outbrute.txt", "r");
    outsol   = fopen ("outsol.txt", "r");

    int nbrute, nsol;

    fscanf (outbrute, "%d", &nbrute);
    fscanf (outsol,   "%d", &nsol);

    if (nbrute != nsol)
        return false;

    for (int i = 0; i < nsol; i++)
    {
        int xs, ys, xb, yb;
        fscanf (outsol, "%d %d", &xs, &ys);
        fscanf (outbrute, "%d %d", &xb, &yb);

        if (xs != xb || ys != yb)
            return false;
    }

    fclose (outbrute);
    fclose (outsol);

    return true;
}

int main()
{
    while (compare())
    {
        system ("generator.exe");
        system ("blokiranjebrut.exe");
        system ("blokiranje.exe");
    }

    FILE *in = fopen ("in.txt", "r");

    int n, m;
    fscanf (in, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        fscanf (in, "%s", &matrix [i]);

    for (int i = 0; i < n; i++)
        printf ("%s\n", matrix [i]);

    fclose (in);

    return 0;
}





