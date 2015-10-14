#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int input, n, maxsum, RealLeft, RealRight, FakeLeft, FakeRight, cnt;

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &input);
        cnt += input;
        if (cnt < 0)
        {
            cnt = 0;
            FakeLeft = i;
        }
        if (cnt > maxsum)
        {
            RealLeft = FakeLeft;
            RealRight = i;
            cnt = maxsum;
        }
        if (cnt == maxsum)
        {
            if (
        }
    }

    return 0;
}










