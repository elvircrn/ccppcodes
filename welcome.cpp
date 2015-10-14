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

int len, dp [1000] [1000], n, len_s;
char matrix [1001] [1001], input [1000], s [100], ;

int main()
{
    scanf ("%s %s", &input, &s);

    len   = strlen (input);
    len_s = strlen (s);

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len_s; j++)
        {
            if (j > i)
                dp [i] [j] = 0;
            else
            {
                if (input [i - 1] == s [j - 1])
                    dp [i] [j] = max (dp [i] [j - 1] + dp [i - 1] [j] + 1, 1);
                else
                    dp [i] [j] = dp [i - 1] [j];
            }
            cout<<dp [i] [j]<<' ';
        }
        cout<<endl;
    }

    cout<<dp [len] [len_s]<<endl;

    return 0;
}
/*
siolobba
silba
*/


