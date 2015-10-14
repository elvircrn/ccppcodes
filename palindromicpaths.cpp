#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

char matrix [100] [100];
int t, n, dp [100] [100];
string str [100] [100];

int main()
{
    //freopen ("in.txt", "r", stdin);

    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf ("%s", &matrix [i]);
            for (int j = 0; j < n; j++)
            {
                str [i] [j] = "";
                dp  [i] [j] =  0;

                if (i < j)
                {
                    dp  [i] [j] = 1;
                    str [i] [j] = matrix [i] [j];
                }
            }
        }

        for (int k = 1; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + k;

                if (j >= n)
                    continue;

                for (int l = i + 1; l < j; l++)
                {
                    for (int m = l; m < j; m++)
                    {
                        if (matrix [i] [l] == matrix [m] [j])
                        {
                            string ret = matrix [i] [l] + str [l] [m] + matrix [m] [j];

                            if (ret.length() > str [i] [j].length() ||
                                ret.length() == str [i] [j].length() && ret < str [i] [j])
                                    str [i] [j] = ret;
                        }
                    }
                }
            }
        }

        cout<<str [0] [n - 1]<<endl;
    }

    return 0;
}





















