#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int Q, n;

struct Word
{
    char letters [200010];
    bool reversed;

    Word () { reversed = false; }

    int GetIndex (int index)
    {
        if (reversed)
            return (n - (index + 1));
        else
            return index;
    }
};

Word word, reverse_word;
bool REVERSED = false;

int main ()
{
    int t, i;
    char x;
    scanf ("%d %d", &n, &Q);
    scanf ("%s", &word.letters);

    strcpy (reverse_word.letters, word.letters);

    char *first = &reverse_word.letters [0];
    char *last  = &reverse_word.letters [n - 1];

    if (n > 1)
    {
        while (first < last)
        {
            swap (*first, *last);
            first++;
            last--;
        }
    }

    while (Q--)
    {
        scanf ("%d", &t);
        if (t == 1)
        {
            scanf ("%d %c", &i, &x); i--;
            if (!REVERSED)
            {
                word.letters [i] = x;
                reverse_word.letters [n - (i + 1)] = x;
            }
            else
            {
                word.letters [n - (i + 1)] = x;
                reverse_word.letters [i] = x;
            }
        }
        else
            REVERSED = !REVERSED;
    }

    if (!REVERSED)
        printf ("%s\n", word.letters);
    else
        printf ("%s\n", reverse_word.letters);

    return 0;
}
