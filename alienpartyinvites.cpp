#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int n, m;

struct node
{
    node *next[28];
    int word;

    node()
    {
        word = -1;
        memset (next, NULL, sizeof next);
    }
    void AddLetter (char letter)
    {
        next [letter - 'a'] = new node();
    }
};


node *root;
vector <int> array;
bool found;
int visited [50000], solution = 2000000, COUNT = 0, sub_size;

int find_first (int start_index)
{
    for (int i = start_index; i < n; i++)
    {
        if (array [i] == -1)
            continue;

        if (!visited [array [i]])
            COUNT++;

        visited [array [i]]++;

        if (COUNT == sub_size)
            return i;
    }

    return -1;
}

int cut(int start_index, int end_index)
{
    for (int i = start_index; i <= end_index; i++)
    {
        if (array [i] == -1)
            continue;

        visited [array [i]]--;
        if (!visited [array [i]])
        {
            COUNT--;
            return i;
        }
    }

    return -1;
}

int main()
{
    char c;
    root = new node();

    scanf ("%d", &n); getchar_unlocked();
    for (int i = 0; i < n; i++)
    {
        node *current_node = root;
        while (!isalpha (c = getchar_unlocked()));

        if (current_node->next [c - 'a'] == NULL)
            current_node->AddLetter(c);

        current_node = current_node->next [c - 'a'];

        while (isalpha (c = getchar_unlocked()))
        {
            if (current_node->next [c - 'a'] == NULL)
                current_node->AddLetter(c);
            current_node = current_node->next [c - 'a'];
        }

        current_node->word = i;
    }

    scanf ("%d", &m);

    for (int i = 0; i < m; i++)
    {
        node *current_node = root;
        found = false;

        while (!isalpha (c = getchar_unlocked()));

        if (current_node->next [c - 'a'] == NULL)
            found = true;
        else
            current_node = current_node->next [c - 'a'];

        while (isalpha (c = getchar_unlocked()))
        {
            if (current_node->next [c - 'a'] == NULL)
                found = true;

            if (found)
                continue;

            current_node = current_node->next [c - 'a'];
        }

        array.push_back (current_node->word);
    }

    sub_size = n;

    int START = 0, END, current_index = 0;

    n = array.size();

    while (array [current_index] == -1)
        current_index++;

    while (true)
    {
        if (current_index >= n)
            break;
        int index = find_first(current_index);

        if (index == -1)
            break;
        else if (array [index] == -1)
        {
            while (array [index] == -1 && index < n)
                index++;
            if (index >= n)
                break;
            START = index;
        }
        else
        {
            int now = cut (START, n);
            solution = min (solution, (index - now) + 1);
            current_index = index + 1;
            START = now + 1;
        }
    }

    printf ("%d\n", solution);

    return 0;
}


/*
admin
moderator
hacker
programmer
user
coder
moderator
admin
*/


