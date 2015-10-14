#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

class bit_set
{
public:
    int bits, n;

    bit_set()
    {
        bits = 0;
        n = 0;
    }

    void turn_on(int index)
    {
        if (!(bits & (1<<index)))
        {
            bits += 1<<index;
            n++;
        }
    }

    void turn_off(int index)
    {
        if (bits & (1<<index))
        {
            bits -= 1<<index;
            n--;
        }
    }

    bool get(int index)
    {
        return bits & (1<<index);
    }

    bool operator< (const bit_set &B) const
    {
        return bits < B.bits;
    }

    void print() const
    {
        int b = bits;
        vector<int> pr;

        while(b)
        {
            pr.push_back(b % 2);
            b /= 2;
        }

        for (int i = 0; i < pr.size(); i++)
            if(pr[i])
                printf("%c ", 'a' + i); printf("\n");
    }
};

char word[100100];
int len;

class jingle
{
public:
    vector<char> letters;
    int values[27];

    jingle()
    {
        letters.clear();
        for (int i = 0; i < 27; i++)
            values[i] = 200000;
    }

    void order()
    {
        sort(letters.begin(), letters.end(), [=](char a, char b)
        {
            return values[a - 'a'] < values[b - 'a'];
        });
    }

    void print()
    {
        for(int i = 0; i < letters.size(); i++)
            printf("    %c %d\n", letters[i], values[letters [i] - 'a']);
    }
};

map<bit_set, int> visited;

jingle jingles[200000];

int main()
{
    int t;
    scanf("%d", &t); getchar();
    while(t--)
    {
        for (len = 0; ; len++)
        {
            if (!isalpha(word[len] = getchar()))
                break;
            for(int j = 0; j < 27; j++)
                jingles[len].values[j] = 200000;
        }
        word[len] = '\0';

        jingle current;


        visited.clear();

        for (int i = len - 1; i > -1; i--)
        {
            if (current.values[word[i] - 'a'] == 200000)
                current.letters.push_back(word[i]);

            current.values[word[i] - 'a'] = i;

            current.order();
            jingles [i] = current;
        }

        for(int i = 0; i < len; i++)
        {
            bit_set bit;
            //printf("i: %d\n", i);
            for (int j = 0; j < jingles[i].letters.size(); j++)
            {
                bit.turn_on(jingles[i].letters[j] - 'a');

                //printf("    %c %d\n", jingles[i].letters[j], jingles[i].values[jingles[i].letters[j] - 'a']);

                if (j != jingles[i].letters.size() - 1)
                    visited[bit] = max(visited[bit], jingles[i].values[jingles[i].letters[j + 1] - 'a'] - i);
                else
                    visited[bit] = max(visited[bit], len - i);
            }
        }

        int solution = 0, counter(0);

        for(auto it = visited.begin(); it != visited.end(); it++)
        {
            counter++;
            //printf("| "); printf("first.n: %d size: %d ", it->first.n, it->second); (it->first).print();
            solution += it->first.n * it->second;
        }

        printf("%d %d\n", counter, solution);
    }


    return 0;
}

/*
2
abbcccdddd
abacaba


*/
