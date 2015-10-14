#include <cstdio>
#include <cstdlib>

using namespace std;

long long int n;

int main()
{
    while (scanf ("%lld", &n) == 1 && n)
    {
        long long int sol(0LL);
        for (int i = 0; i < n; i++)
            sol += (n - i) * (n - i);

        printf ("%lld\n", sol);
    }

    return 0;
}
