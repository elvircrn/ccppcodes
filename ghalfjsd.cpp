#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//#define DEBUG

int n, k;
vector <string> words;
int contains [30] [30], beginning [30] [30];

int get_contains (int container, int candidate, int offset)
{
    if (words [container].length() < words [candidate].length())
        return 0;

    int ret = 0;

    for (int i = offset; i < words [container].length(); i++)
    {
        bool found = true;

        for (int j = 0; j < words [candidate].length(); j++)
        {
            if (i + j >= words [container].length() || words [container] [i + j] != words [candidate] [j])
            {
                found = false;
                break;
            }
        }

        ret += found;
    }

    return ret;
}

int get_beginning(int left, int right)
{
    bool found = true;
    for (int i = max (0, (int)words[left].length() - (int)words [right].length() + 1); i < words [left].length(); i++)
    {
        if (left == right && i == 0)
            continue;
        found = true;
        for (int j = 0; j < words [right].length(); j++)
        {
            if (i + j >= words [left].length())
                break;

            if (words [left] [i + j] != words [right] [j])
            {
                found = false;
                break;
            }
        }
        if (found)
            return i;
    }

    return words[left].length();
}

int dp [30] [5001];

int solve(int prev_word, int current_index)
{
    #ifdef DEBUG
    cout<<"prev_word: "<<prev_word<<" current_index: "<<current_index<<endl;
    #endif
    if (current_index >= k)
        return 0;

    if (dp [prev_word] [current_index] != -1)
        return dp [prev_word] [current_index];

    int diff, l;

    dp [prev_word] [current_index] = 0;

    for (int i = 0; i < n; i++)
    {
        diff = words [prev_word].length() - beginning [prev_word] [i];
        l = words[i].length() - diff;

        if (current_index + l >= k)
            continue;

        #ifdef DEBUG
        cout<<"addition: "<<contains [i] [0] - contains [i] [beginning [prev_word] [i]]<<endl;
        #endif

        dp [prev_word] [current_index] = max (solve (i, current_index + l) + contains [i] [0] - contains [i] [beginning [prev_word] [i]], dp [prev_word] [current_index]);
    }

    return dp [prev_word] [current_index];
}

int main()
{
    ios_base::sync_with_stdio(false);
    string w;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>w;
        words.push_back(w);
    }

    sort(words.begin(), words.end(), [] (const string &a, const string &b) -> bool { return a.length() < b.length(); });

    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 5000; j++)
            dp [i] [j] = -1;

    //contains
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < words [i].length(); k++)
                contains [i] [k] += get_contains(i, j, k);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            beginning [i] [j] = get_beginning(i, j);

    #ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<words [i]<<' '<<words [j]<<" beginning: "<<beginning [i] [j]<<endl;
        }
    }


    for (int i = 0; i < 3; i++)
        cout<<"contains "<<contains [2] [i]<<endl;

    #endif


    int solution = 0;

    for (int i = 0; i < n; i++)
        solution = max (solution, solve (i, words [i].length() - 1) + contains [i] [0]);

    printf ("%d\n", solution);

    return 0;
}
/*
1 20
A

1 10
AAA

AAAAAAAAAA

1 7
ABACB

3 7
CB
ABA
ABACB

ABACBCB
A B A C B C B
*/


















