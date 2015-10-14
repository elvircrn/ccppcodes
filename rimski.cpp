#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

string romans [13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
int integers [13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

string toRoman (int number)
{
    string ret = "";
    while (number)
    {
        for (int i = 0; i < 13; i++)
            if (integers [i] <= number)
            {
                ret += romans [i];
                number -= integers [i];
                break;
            }
    }
    return ret;
}

string input;
int Count [1000], current [1000];

bool check (int number)
{
    memset (current, 0, sizeof current);
    string roman = toRoman (number);
    for (int i = 0; i < roman.length(); i++)
        current [roman [i]]++;

    for (int i = 0; i < 500; i++)
        if (current [i] != Count [i])
            return false;
    return true;
}


int main ()
{
    cin>>input;
    for (int i = 0; i < input.length(); i++)
        Count [input [i]]++;

    for (int i = 1; i < 3000; i++)
        if (check (i))
        {
            cout<<toRoman(i)<<endl;
            break;
        }

    return 0;
}
