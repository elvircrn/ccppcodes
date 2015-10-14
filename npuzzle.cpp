#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int abs (int x)
{
    if (x < 0)
        return x * (-1);
    else
        return x;
}

string field [4] = { "ABCD", "EFGH", "IJKL", "MNOP" };
string input [4];

int sum;

int main ()
{
    for (int i = 0; i < 4; i++)
        cin>>input [i];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < 4; l++)
                    if (input [i] [j] == field [k] [l])
                        sum += (abs (i - k) + abs (j
                                                    - l));

    printf ("%d\n", sum);

    return 0;
}





