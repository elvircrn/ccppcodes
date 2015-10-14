#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

char word [2000001];
int SIZE, c, cnt = 1, solution;
bool vowel [2000001];

int main ()
{
    scanf ("%s", &word);
    SIZE = strlen (word);
    for (int i = 0; i < SIZE; i++)
    {
        c = word [i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowel [i] = true;
    }

    bool previous = vowel [0];
    int starting_index_solution = 0, ending_index_solution = 0, starting_index = 0, ending_index = 0;

    bool promjena = true;

    for (int i = 0; i < SIZE; i++)
    {
        if (vowel [i] == previous)
        {
            starting_index = i;
            ending_index = i;
            cnt = 1;
        }
        else
        {
            cnt++;
            ending_index = i;
            if (solution < cnt && cnt <= SIZE)
            {
                starting_index_solution = starting_index;
                ending_index_solution = ending_index;
                solution = cnt;
            }
        }
        previous = vowel [i];
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (vowel [i] == previous)
        {
            starting_index = i;
            ending_index = i;
            cnt = 1;
        }
        else
        {
            cnt++;
            ending_index = i;
            if (solution < cnt && cnt <= SIZE)
            {
                starting_index_solution = starting_index;
                ending_index_solution = ending_index;
                solution = cnt;
            }
        }
        previous = vowel [i];
    }

    if (starting_index_solution > ending_index_solution)
    {
        for (int i = starting_index_solution; i < SIZE; i++)
           putchar (word [i]);
        for (int i = 0; i <= ending_index_solution; i++)
            putchar (word [i]);
    }
    else
    {
        for (int i = starting_index_solution; i <= ending_index_solution; i++)
            putchar (word [i]);
    }

    printf ("\n");

    return 0;
}
//AB






