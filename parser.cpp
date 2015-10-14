#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define getX(x) (x) / n
#define getY(x) n - ((x) % n + 1)
#define get(X,Y) (X) * n + (Y)

FILE *in;
int matrix [11] [11];

vector <vector <int> > solutions [111];
vector <int> solution;

int main()
{

    freopen ("ASD.txt", "w", stdout);
    in = fopen ("out.txt", "r");
    int n, k;
    char buffer [5];


    while (fscanf (in, "%s %d %s %d", &buffer, &n, &buffer, &k) == 4)
    {
        solution.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fscanf (in, "%d", &matrix [i] [j]);
                solution.push_back (matrix [i] [j]);
            }
        }


        printf ("solution[%d].push_back({ ", n * 10 + k);
        for (int i = 0; i < solution.size(); i++)
            printf ("%d, ", solution [i]);
        printf ("});\n");
    }

    return 0;
}











































