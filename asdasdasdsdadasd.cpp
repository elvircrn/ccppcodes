#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <string>
#include <cstring>

using namespace std;

long long int dp [5000000];
long long int f (long long int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (dp [n] != 0)
        return dp [n];
    dp [n] = f (n - 1) + f (n - 2);
    return dp [n];
}

long long int f2 (long long int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    return f2 (n - 1) + f2 (n - 2);
}

int main ()
{

    cout<<f2 (46)<<endl;

    return 0;
}
