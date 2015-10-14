#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <sstream>

using namespace std;

int solution, len, dp3 [1010] [13], dp1 [1010] [13], dp2 [1010] [13], dp4 [1010] [13], n, len_s;
char matrix [1001] [1001], input [1000], s [100], rev_s [100];
int main()
{
    scanf ("%d %s", &n, &s);
    len_s = strlen (s);

    for (int i = 0; i < len_s; i++)
        rev_s [i] = s [len_s - i - 1];

//horizontal
    for (int t = 0; t < n; t++)
    {
        scanf ("%s", &matrix [t]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= len_s; j++)
            {
                dp1 [i] [j] = 0;
                dp2 [i] [j] = 0;

                if (j > i)
                {
                    dp1 [i] [j] = 0;
                    dp2 [i] [j] = 0;
                }
                else if (j == 1 && matrix [t] [i - 1] == s [j - 1])
                    dp1 [i] [j] = dp1 [i - 1] [j] + 1;
                else if (j == 1 && matrix [t] [i - 1] == rev_s [j - 1])
                    dp2 [i] [j] = dp2 [i - 1] [j] + 1;
                else
                {
                    if (matrix [t] [i - 1] == s [j - 1])
                        dp1 [i] [j] = dp1 [i - 1] [j - 1] + dp1 [i - 1] [j];
                    else
                        dp1 [i] [j] = dp1 [i - 1] [j];

                    if (matrix [t] [i - 1] == rev_s [j - 1])
                        dp2 [i] [j] = dp2 [i - 1] [j - 1] + dp2 [i - 1] [j];
                    else
                        dp2 [i] [j] = dp2 [i - 1] [j];
                }
            }
        }

        solution += (dp1 [n] [len_s] + dp2 [n] [len_s]);
    }

//vertical

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i < j)
                swap (matrix [i] [j], matrix [j] [i]);


    for (int t = 0; t < n; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= len_s; j++)
            {
                dp1 [i] [j] = 0;
                dp2 [i] [j] = 0;

                if (j > i)
                {
                    dp1 [i] [j] = 0;
                    dp2 [i] [j] = 0;
                }
                else if (j == 1 && matrix [t] [i - 1] == s [j - 1])
                    dp1 [i] [j] = dp1 [i - 1] [j] + 1;
                else if (j == 1 && matrix [t] [i - 1] == rev_s [j - 1])
                    dp2 [i] [j] = dp2 [i - 1] [j] + 1;
                else
                {
                    if (matrix [t] [i - 1] == s [j - 1])
                        dp1 [i] [j] = dp1 [i - 1] [j - 1] + dp1 [i - 1] [j];
                    else
                        dp1 [i] [j] = dp1 [i - 1] [j];

                    if (matrix [t] [i - 1] == rev_s [j - 1])
                        dp2 [i] [j] = dp2 [i - 1] [j - 1] + dp2 [i - 1] [j];
                    else
                        dp2 [i] [j] = dp2 [i - 1] [j];
                }
            }
        }

        solution += (dp1 [n] [len_s] + dp2 [n] [len_s]);
    }



    printf ("%d\n", solution);

    return 0;
}
/*
10 silba
oooooooooo
ooooaooooo
oooobooooo
oooolooooo
ooooiooooo
aooosooooo
booooooooo
looooooooo
iooooooooo
sooooooooo
*/



