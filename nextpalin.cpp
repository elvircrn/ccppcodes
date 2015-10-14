#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int modifier = 5;

char input [1100000];
int len;

int to_int(char c)
{
    return c - '0';
}

void add_one (int index)
{
    int carry(1);
    for (int i = index; i >= modifier && carry; i--)
    {
        int val = to_int (input [i]) + carry;
        input [i] = val % 10 + '0';
        carry = val / 10;
    }

    if (carry)
    {
        input [modifier - 1] = '1';
        modifier--;
        len++;
    }
}

bool is_palin()
{
    for (int i = 0; i < len / 2; i++)
        if (input [modifier + i] != input [modifier + (len - 1) - i])
            return false;

    return true;
}

int main()
{
    int t;
    bool isnine(true);

    scanf ("%d", &t);
    while (t--)
    {
        bool flag(false), flag2(false);

        for (int i = 0; i < 10; i++)
            input [i] = '\0';

        scanf ("%s", input + modifier);

        len = strlen (input + modifier);

        if (input [modifier + len - 1] == '9')
            flag = true;

        if (input [modifier + len - 1] == '0')
            flag2 = true;

        isnine = true;

        for (int i = 0; i < len; i++)
            if (input [modifier + i] != '9')
            {
                isnine = false;
                break;
            }

        if (isnine)
        {
            putchar ('1');
            for (int i = 0; i < len - 1; i++)
                putchar ('0');
            putchar ('1'); putchar ('\n');
        }
        else if (len == 1)
        {
            putchar (((int)input [modifier] + 1));
            putchar ('\n');
        }
        else
        {
            if (len % 2 == 0)
            {
                bool flag3(false);
                while (!flag3)
                {
                    for (int i = 1; i <= len / 2; i++)
                        if (input [modifier + len / 2 - i] > input [modifier + len / 2 + i - 1])
                        {
                            flag3 = true;
                            break;
                        }
                        else if (input [modifier + len / 2 - i] < input [modifier + len / 2 + i - 1])
                            break;

                    if (!flag3)
                        add_one(modifier + (len / 2) - 1);
                    break;
                }


                //cout<<"flag3: "<<flag3<<endl;

                for (int i = modifier; i <= modifier + (len / 2) - 1; i++)
                    putchar (input [i]);
                for (int i = modifier + (len / 2) - 1; i >= modifier; i--)
                    putchar (input [i]);
            }
            else
            {
                bool flag3(false);
                while (!flag3)
                {
                    for (int i = 1; i <= len / 2; i++)
                        if (input [modifier + len / 2 - i] > input [modifier + len / 2 + i])
                        {
                            flag3 = true;
                            break;
                        }
                        else if (input [modifier + len / 2 - i] < input [modifier + len / 2 + i])
                            break;
                    if (!flag3)
                        add_one(modifier + (len / 2));
                    break;
                }


                for (int i = modifier; i <= modifier + (len / 2); i++)
                    putchar (input [i]);
                for (int i = modifier + (len / 2) - 1; i >= modifier; i--)
                    putchar (input [i]);
            }
            putchar ('\n');
        }
    }

    return 0;
}

/*
11
83128
1
99
112
199
999
1999
4572
18992
1000000
1239999321

83138
2
101
121
202
1001
2002
4664
19091
1000001
1240000421

*/







