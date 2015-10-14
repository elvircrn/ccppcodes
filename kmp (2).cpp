#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAX_N 100010
char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P
void kmpPreprocess()   // call this before calling kmpSearch()
{
    int i = 1, j = 0;
    while (i < m)
    {
        if (P [i] == P [j])
        {
            j++;
            b [i] = j;
            i++;
        }
        else if (P [i] != P [j])
        {
            if (j > 0)
                j = b [j - 1];
            else
            {
                b [i] = 0;
                i++;
            }
        }
    }
} // in the example of P = "SEVENTY SEVEN" above
void kmpSearch()   // this is similar as kmpPreprocess(), but on string T
{

}
int main ()
{
    scanf ("%s %s", &T, &P);
    n = strlen (T);
    m = strlen (P);

    kmpPreprocess();

    for (int i = 0; i < m; i++)
        printf ("%3c ", P [i]);

    putchar ('\n');

    for (int i = 0; i < m; i++)
        printf ("%3d ", b [i]); printf ("\n");

    return 0;
}
/*
A
AAACAAAA

                             _
  A  B  A  B  C  A  B  A  B  A  S  D  A  D
 -1  0  1  2  0  1  2  3  4  3  0  0  1  0
*/












