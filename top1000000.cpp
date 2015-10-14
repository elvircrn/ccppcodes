#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int lens [210000], visited [200010], dot_count [200010], q_len, m, RA [200010], SA [200010], pos [200010], n, power, len, global = 1;
char words [20100] [1000], Q [200010], S [200010];

vector <int> SOLUTION;

bool cmp (int A, int B)
{
    if (pos [A] != pos [B])
        return pos [A] < pos [B];
    else if (A + power >= len || B + power >= len)
        return A > B;
    else
        return pos [A + power] < pos [B + power];
}

bool compare(int A, int B)
{
    if (lens [A] != lens [B])
        return lens [A] < lens [B];

    int asd = strcmp (words [A], words [B]);

    if (!asd)
        return A < B;
    else
        return asd < 0;
}

int main()
{
    freopen ("in.txt", "r", stdin);

    char c;
    scanf ("%d", &n);
    while (!isalpha (c = getchar()));
    S [0] = c;
    pos [0] = c;
    dot_count [0] = 1;
    lens [1] = 1;

    int word_index = 1;

    words [1] [0] = c;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            lens [i + 1] = 1;
        while (isalpha (c = getchar()))
        {
            S [global]   = c;
            SA [global]  = global;
            pos [global] = c;
            lens [i + 1]++;
            words [i + 1] [word_index] = c;
            dot_count [global] = i + 1;
            global++;

            word_index++;
        }

        words [i + 1] [word_index] = '\0';
        word_index = 0;

        S [global] = '.';
        pos [global] = '.';
        dot_count [global] = i + 1;
        SA [global] = global;
        global++;
    }

    len = global;

    for (power = 1; power <= len; power *= 2)
    {
        sort (SA, SA + len, cmp);

        for (int i = 0; i < len - 1; i++)
            RA [i + 1] = RA [i] + cmp (SA [i], SA [i + 1]);
        for (int i = 0; i < len; i++)
            pos [SA [i]] = RA [i];
    }

    int left_start = 0;

    //for (int i = 0; i < len; i++)
    //    printf ("%s\n", S + SA [i]);

    scanf ("%d", &m); getchar();

    int test_id = 1;

    //for (int i = 1; i <= n; i++)
    //    printf ("%s\n", words [i]);

    while (m--)
    {
        SOLUTION.clear();

        scanf ("%s", &Q);
        q_len = strlen (Q);

        int pivot, left = n - 1, top_index = -1, bottom_index = -1, right = len - 1;

        while (left <= right)
        {
            pivot = (left + right) / 2;

            int comp = strncmp (Q, S + SA [pivot], q_len);

            if (comp <= 0)
                right = pivot - 1;
            else
                left = pivot + 1;

            if (comp == 0)
                top_index = pivot;
        }

        left = n - 1;
        right = len - 1;

        while (left <= right)
        {
            pivot = (left + right) / 2;

            int comp = strncmp (Q, S + SA [pivot], q_len);

            if (comp >= 0)
                left = pivot + 1;
            else
                right = pivot - 1;

            if (comp == 0)
                bottom_index = pivot;
        }

        if (top_index == -1 || bottom_index == -1)
        {
            printf ("-1\n");
            continue;
        }

        int test_count = 0;

        for (int i = top_index; i <= bottom_index; i++)
        {
            int dc = dot_count [SA [i]];

            if (visited [dc] != test_id)
            {
                visited [dc] = test_id;
                SOLUTION.push_back (dot_count [SA [i]]);
            }
        }

        sort (SOLUTION.begin(), SOLUTION.end(), compare);

        for (int i = 0; i < SOLUTION.size() && i < 10; i++)
            printf ("%d ",  SOLUTION [i]); printf ("\n");

        test_id++;
    }

    return 0;
}
/*
17
acm
icpc
regional
asia
jakarta
two
thousand
and
nine
arranged
by
universitas
bina
nusantara
especially
for
you
5
a
an
win
b
z


*/


