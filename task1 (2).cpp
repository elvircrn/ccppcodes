#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string str;
int n;

int main()
{
    int ind(0);
    char c;
    while ((c = getchar()) != '\n')
    {
        word [ind] = c;
        if (ind == 0)
        {
            if (c != '<' && c != '>')
                left_right [ind] = 1;
        }
        else if (c == '=' || c == '-')
        {
            if (word [ind - 1] == word [ind])
                left_right [ind] = left_right [ind - 1] + 1;
            else
                left_right [ind] = 1;
        }
        else
            left_right [ind] = 0;
        ind++;
    }

    for (int i = 1; i < ind; i++)
    {
        if (word [i] == '>')
            max_len = max (left_right [i - 1], max_len);
    }

    for (int i = 0; i < ind - 1; i++)
        if (word [i] == '<')
            max_len = max (max_len, left_right [i + 1]);

    for (int i = 0; i < ind; i++)
        printf ("%d ", left_right [i]); printf ("\n");

    if (max_len)
        printf ("%d\n", max_len);
    else
        printf ("%d\n", -1);


    return 0;
}
