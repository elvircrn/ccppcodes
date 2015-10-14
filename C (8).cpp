#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


long long int array [100100], a, b;

int main()
{
    cin>>a>>b;

    int n = a + b;
        long long int solution(0);

        long long int positive(0), negative(0);



    if (a >= b)
    {
        int parity = (n - 1) % 2;

        for (int i = n - 1; i > -1; i--)
        {
            if (i % 2 == parity && b)
            {
                array [i] = 1;
                b--;
            }
            else
                a--;
        }

        if (b)
        {
            for (int i = 0; i < n; i++)
            {
                if (!array [i])
                {
                    b--;
                    array [i] = 1;
                }
                if (!b)
                    break;
            }
        }
    }
    else if (a < b)
    {

        for (int i = 0; i < n; i++)
            array [i] = 1;

        if (a == 0)
            goto l1;


        //ooxooo
        //
        //
        int  middle = n / 2 + (n % 2);

        if (a == 1)
            middle = n / 2;

        for (int i = 0; i < n; i++)
        {
            if (middle - i * 2 > -1)
            {
                a--;
                array [middle - i * 2] = 0;
            }
            if (a == 0)
                break;

            if (i == 0)
                continue;

            if (middle + i * 2 < n)
            {
                array [middle + i * 2] = 0;
                a--;

                if (a == 0)
                    break;
            }
        }
    }

    l1:;

    if (array [0] == 0)
        positive++;
    else
        negative++;

    for (int i = 1; i < n; i++)
    {

        if (array [i] == 1)
        {
            if (array [i - 1] != array [i])
            {
                solution += (positive * positive);
                negative = 1;
                positive = 0;
            }
            else
                negative++;
        }
        else
        {
            if (array [i - 1] != array [i])
            {
                solution -= (negative * negative);
                negative = 0;
                positive = 1;
            }
            else
                positive++;
        }
    }

    if (positive)
        solution += (positive * positive);
    else

        solution -= (negative * negative);
    cout<<solution<<endl;
    for (int i = 0; i < n; i++)
    {
        if (array [i] == 0)
            putchar ('o');
        else
            putchar ('x');
    }
    putchar ('\n');


    return 0;
}
/*
xoxoxxxxx
-25
xxxoxoxxx
-9 + 1 - 9


3 4
xoxoxox

4 5
xxoxoxoxo -1
xxoxoxoxo-4 - 1

ooooxoxox
ooooooxxx


xoxoxx


oooooo
xxxxox
-16

xxoxxx

xoxxx
-9

xxoxx
-7


-4 - 9 + 1 = -12

*/
