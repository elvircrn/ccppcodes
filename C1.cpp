#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int zeros, total, ones;

int main()
{
    scanf ("%d %d", &zeros, &ones);

    total = zeros + ones;

    if (zeros > ones)
    {
        if (zeros - ones >= 2)
        {
            printf ("-1\n");
            return 0;
        }
        else if (zeros - ones == 1)
        {
            for (int i = 0; i < total; i++)
            {
                if (i % 2 == 0)
                    printf ("0");
                else
                    printf ("1");
            }
            printf ("\n");
            return 0;
        }
    }
    else if (zeros < ones)
    {
        if (ones - zeros >= 4)
        {
            printf ("-1\n");
            return 0;
        }

        if (ones - zeros == 3)
        {
            for (int i = 0; i < total - 1; i++)
            {
                if (i % 3 == 2)
                    printf ("0");
                else
                    printf ("1");
            }
            printf ("1\n");
            return 0;
        }
        else if (ones - zeros == 2)
        {
            for (int i = 0; i < total - 1; i++)
            {
                if (i % 2 == 0)
                    printf ("1");
                else
                    printf ("0");
            }
            printf ("1\n");
            return 0;
        }
        else if (ones - zeros == 1)
        {
            for (int i = 0; i < total; i++)
            {
                if (i % 2 == 0)
                    printf ("1");
                else
                    printf ("0");
            }
            printf ("\n");
            return 0;
        }
    }
    else if (zeros == ones)
    {
        for (int i = 0; i < total; i++)
            printf ("%d", i % 2);
        printf ("\n");
        return 0;
    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int zeros, total, ones;

int main()
{
    scanf ("%d %d", &zeros, &ones);

    total = zeros + ones;

    if (zeros > ones)
    {
        if (zeros - ones >= 2)
        {
            printf ("-1\n");
            return 0;
        }
        else if (zeros - ones == 1)
        {
            for (int i = 0; i < total; i++)
            {
                if (i % 2 == 0)
                    printf ("0");
                else
                    printf ("1");
            }
            printf ("\n");
            return 0;
        }
    }
    else if (zeros < ones)
    {
        if (ones - zeros >= 4)
        {
            printf ("-1\n");
            return 0;
        }

        if (ones - zeros == 3)
        {
            for (int i = 0; i < total - 1; i++)
            {
                if (i % 3 == 2)
                    printf ("0");
                else
                    printf ("1");
            }
            printf ("1\n");
            return 0;
        }
        else if (ones - zeros == 2)
        {
            for (int i = 0; i < total - 1; i++)
            {
                if (i % 2 == 0)
                    printf ("1");
                else
                    printf ("0");
            }
            printf ("1\n");
            return 0;
        }
        else if (ones - zeros == 1)
        {
            for (int i = 0; i < total; i++)
            {
                if (i % 2 == 0)
                    printf ("1");
                else
                    printf ("0");
            }
            printf ("\n");
            return 0;
        }
    }
    else if (zeros == ones)
    {
        for (int i = 0; i < total; i++)
            printf ("%d", i % 2);
        printf ("\n");
        return 0;
    }

    return 0;
}

