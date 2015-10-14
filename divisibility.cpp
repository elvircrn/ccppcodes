#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int n, SIZE, SUM;
char word [2000], for_seven [2000], kopija [2000];

vector <int> factors;

void factorise (int number)
{
    for (int i = 2; i <= number && number > 1; i++)
    {
        if (number % i)
        {
            factors.push_back (i);
            while (number % i == 0)
                number /= i;
        }
    }
}

bool two ()
{
    return ((word [SIZE - 1] - '0') % 2 == 0);
}

bool three()
{

    SUM = 0;

    for (int i = 0; i < SIZE; i++)
        SUM += word [i] - '0';

    return !(SUM % 3 == 0);
}

bool four ()
{
    if (SIZE == 1)
        return !((word [0] - '0') % 4);

    return !(((word [SIZE - 2] - '0') * 10 + word [SIZE - 1] - '0') % 4);

}

bool five()
{
    if (word [SIZE - 1] == '5' || word [SIZE - 1] == '0')
        return true;
    else
        return false;
}

bool six()
{
    return ((three()) && (six()));
}

bool seven()
{
    if (SIZE == 1 && word [0] == '7')
        return true;

    int current_size = SIZE;

    while (true)
    {
        //printf ("%d\n", current_size);
        if (current_size < 3)
        {
            return !(((kopija [0] - '0') * 10 + kopija [1] - '0') % 7);
        }
        int counter = (current_size / 2) + current_size % 2 - 1;
        bool gore = true;
        for (int i = 0; i < current_size; i += 2, counter--)
        {
            int broj = (for_seven [i] - '0') * 10 + for_seven [i + 1] - '0', djeljivo;

            if (current_size % 2 == 1 && i == 0)
                broj = for_seven [i] - '0';

            if (gore)
            {
                if (broj % 7 == 0)
                    djeljivo = broj;
                else
                    djeljivo = broj - (broj % 7) + 7;

                kopija [counter] = (djeljivo - broj) + '0';
            }
            else
            {
                if (broj % 7 == 0)
                    djeljivo = broj;
                else
                    djeljivo = broj - (broj % 7);

                kopija [counter] = (broj - djeljivo) + '0';
            }

            gore = !gore;

            if (current_size % 2 == 1 && i == 0)
                i = -1;
        }

        current_size = (current_size / 2) + current_size % 2;

        strcpy (for_seven, kopija);
    }

    return false;
}

bool eight()
{
    if (SIZE == 1)
        return !((word [0] - '0') % 8);
    else if (SIZE == 2)
        return !((word [0] - '0') * 10 + (word [1] - '0') % 8);
    else
    {
        !((word [0] - '0') * 100 + (word [1] - '0') * 10 + (word [2] - '0') % 8);
    }
}

bool nine ()
{
    return !(SUM % 3);
}

bool ten()
{
    if (word [0] == '0')
        return true;
    else
        return false;
}

bool eleven()
{
    int parno = 0, neparno = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 == 0)
            parno += (word [i] - '0');
        else
            neparno += (word [i] - '0');
    }

    if ((neparno - parno) % 11 == 0)
        return true;
    else
        return false;
}

bool twelve()
{
    return (three() && four());
}

bool thirteen()
{
    int tens = 1, number = 0;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        number = (word [i] - '0') * tens;
        tens *= 10;
    }

    if (number % 13 == 0)
        return true;
    else
        return false;
}

bool fourteen()
{
    return (two() && seven());
}

bool fifteen()
{
    return (three() && five());
}

bool sixteen()
{
    if (SIZE > 4)
    {
        int tens = 1, number = 0;
        for (int i = SIZE - 1; i >= 0; i--)
        {
            number = (word [i] - '0') * tens;
            tens *= 10;
        }

        if (number % 16 == 0)
            return true;
        else
            return false;
    }
    else
    {
        int k = (word [SIZE - 1] - '0') + (word [SIZE - 2] - '0') * 10 + (word [SIZE - 3] - '0') * 100 + (word [SIZE - 4] - '0') * 1000;

        if (k % 16 == 0)
            return true;
        else
            return false;
    }
}

int main ()
{

    scanf ("%d", &n);
    factorise (n);

    for (int k = 0; k < 10; k++)
    {
        SUM = -1;
        scanf ("%s", &word);
        strcpy (for_seven, word);
        strcpy (kopija, word);
        SIZE = strlen (word);

        bool nasao = false;

        if (n == 2 && !two())
        {
            nasao = true;
        }
        else if (n == 3 && !three())
        {
            nasao = true;
        }
        else if (n == 4 && !four())
        {
            nasao = true;
        }
        else if (n == 5 && !five())
        {
            nasao = true;
        }
        else if (n == 6 && !six())
        {
            nasao = true;
        }
        else if (n == 7 && !seven())
        {
            nasao = true;
        }
        else if (n == 8 && !eight())
        {
            nasao = true;
        }
        else if (n == 9 && !nine())
        {
            nasao = true;
        }
        else if (n == 10 && !ten())
        {
            nasao = true;
        }
        else if (n == 11 && !eleven())
        {
            nasao = true;
        }
        else if (n == 12 && !twelve())
        {
            nasao = true;
        }
        else if (n == 13 && !thirteen())
        {
            nasao = true;
        }
        else if (n == 14 && !fourteen())
        {
            nasao = true;
        }
        else if (n == 15 && !fifteen())
        {
            nasao = true;
        }
        else if (n == 16 && !sixteen())
        {
            nasao = true;
        }

        if (nasao == true)
            printf ("NE\n");
        else
            printf ("DA\n");
    }

    return 0;
}
//6049344
