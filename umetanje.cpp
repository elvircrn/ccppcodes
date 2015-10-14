#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

//ABCDEFGH

int number, L;

int Tens [10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};


//123456

//2 4

int getRange (int Left, int Right)
{
    int ten = L - Left + 1;
    int ten2 = L - Right;

    return (number % Tens [ten]) / Tens [ten2];
}

int len (int N)
{
    int cnt = 0;
    while (N)
    {
        cnt++;
        N /= 10;
    }
    return cnt;
}

int find (int N, int used, int index)
{
    if (index == L || used == N)
    {
        return;
    }

    find (N, used + 1, index + 1);
    find (N, used, index + 1);

}

int main ()
{

    scanf ("%d", &number);
    L = len (number);

    return 0;
}
