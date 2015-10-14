#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class bit_mask
{
public:
    int bits;

    bit_mask() { bits = 0; }

    void turn_on(int index)
    {
        if (!(bits & (1<<index)))
            bits += 1<<index;
    }

    void turn_off(int index)
    {
        if (bits & (1<<index))
            bits -= 1<<index;
    }

    bool get_bit(int index)
    {
        return (bits & (1<<index));
    }

    bool operator< (const bit_mask &B) const
    {
        return bits < B.bits;
    }
};

int len, world_loc[27];
map <bit_mask, bool> visited;
char word[100100];

struct cluster
{
    char letter;
    int value;

    bool operator< (const cluster &B) const
    {
        return value < B.value;
    }
};

class jingle
{
public:
    vector <char> letters;
    vector <int>  values;

    jingle() { values.resize(27); }

    void order()
    {
        sort(letters.begin(), letters.end(), [=](char a, char b) { return values[a - 'a'] < values[b - 'a']; });
    }

    void print()
    {
        for (int i = 0; i < letters.size(); i++)
        {
            printf ("   %c: %d\n", letters[i], values[letters[i] - 'a']);
        }
    }
};

jingle jingles[100100];

int main()
{
    int word_loc[27],   t;
    vector <char> letters;

    jingle current;

    scanf ("%d", &t);

    while(t--)
    {
        scanf ("%s", &word);
        len = strlen(word);

        for (int i = 0; i < 27; i++)
            current.values[i] = 200000;

        for (int i = len - 1; i > -1; i--)
        {
            if (current.values[word[i] - 'a'] == 200000)
                current.letters.push_back(word[i]);

            current.values[word [i] - 'a'] = i;

            current.order();

            jingles[i] = current;
        }

        for (int i = 0; i < len; i++)
        {
            printf ("i: %d\n", i);
            jingles[i].print();
        }

        for (int i = 0; i < len; i++)
        {
            bit_mask mask;
            for (int j = 0; j < jingles[i].letters.size(); j++)
            {
                mask.turn_on(jingles[i].letters[j] - 'a']);


                if (visited[mask.bits])
                {

                }
            }
        }


    }

    return 0;
}












































