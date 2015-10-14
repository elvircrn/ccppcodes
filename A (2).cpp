#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, m, sock_count;

int main()
{
    scanf ("%d %d", &n, &m);
    sock_count = n;

    int cnt(0);

    while (sock_count)
    {
        cnt++;


        sock_count--;
        if (cnt % m == 0 && cnt != 1)
            sock_count++;

    }

    printf ("%d\n", cnt);

    return 0;
}
