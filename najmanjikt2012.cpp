#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

bool name = true, value, bigger = false, valid_number;
vector <char> biggest_name;
vector <char> current_name;
vector <char> biggest_number;
vector <char> current_number;
char a, word [5];

int current_number_index;

bool niz1 [16777211], niz2 [16777211], niz3 [16777211];

int main ()
{

    /*a = getchar();

    while (a != ';')
    {
        if (a == '=')
        {
            swap (name, value);
        }
        else if (!isdigit (a))
        {
            biggest_name.push_back (a);
        }
        else
        {
            biggest_number.push_back (a);
        }
        a = getchar();
    }

    while (a != '\n')
    {
        if (a == ';')
        {
            name = true;
            value = false;

            if (bigger)
            {
                biggest_name = current_name;
                biggest_number = current_number;
                current_name.clear();
            }
            bigger = false;

        }
        else if (a == '=')
        {
            swap (name, value);
            current_number_index = 0;
        }
        else if (name)
        {
            current_name.push_back (a);
        }
        else if (value)
        {
            current_number.push_back (a);
            current_number_index++;
            if (current_number_index > biggest_number.size())
                biggest = true;

        }

        a = gethcar();
    }*/

    return 0;
}
