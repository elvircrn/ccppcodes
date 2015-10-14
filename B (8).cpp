#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long int solution, n, red_count, blue_count;
char balls [100];

long long int SOLUTION;

int main()
{
    scanf ("%I64d %s", &n, &balls);
    for (long long int i = 0, asd = 1; i < n; i++, asd *= 2)
        if (balls [i] == 'B')
            SOLUTION += asd;

    cout<<SOLUTION<<endl;

    return 0;
}









