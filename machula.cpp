#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cctype>

using namespace std;

typedef long long int ll;

int t;
ll a, b, c;
char one [100], two [100], three [100], dummy [100];

int main()
{
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%s %s %s %s %s", &one, &dummy, &two, &dummy, &three);

        int l_one = strlen (one), l_two = strlen (two), l_three = strlen (three);

        for (int i = 0; i < l_one; i++)
            if (!isdigit (one [i]))
            {
                a = -1;
                break;
            }

        for (int i = 0; i < l_two; i++)
            if (!isdigit (two [i]))
            {
                b = -1;
                break;
            }

        for (int i = 0; i < l_three; i++)
            if (!isdigit (three [i]))
            {
                c = -1;
                break;
            }

        if (a == -1)
        {
            sscanf (two, "%lld", &b);
            sscanf (three, "%lld", &c);
            printf ("%lld + %lld = %lld\n", c - b, b, c);
        }
        else if (b == -1)
        {
            sscanf (one, "%lld", &a);
            sscanf (three, "%lld", &c);
            printf ("%lld + %lld = %lld\n", a, c - a, c);
        }
        else if (c == -1)
        {
            sscanf (one, "%lld", &a);
            sscanf (two, "%lld", &b);
            printf ("%lld + %lld = %lld\n", a, b, a + b);
        }
        else
        {
            sscanf (one, "%lld", &a);
            sscanf (two, "%lld", &b);
            sscanf (three, "%lld", &c);
            printf ("%lld + %lld = %lld\n", a, b, c);
        }

        a = 0;
        b = 0;
        c = 0;
    }



    return 0;
}
