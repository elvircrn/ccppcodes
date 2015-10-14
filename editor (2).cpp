#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

struct Node
{
    Node *next, *prev;
    char value;

    Node() { }
    Node(int _value) { prev = NULL; next = NULL; value = _value; }
};

Node *root, *pointer;
int t;
char q [2];
bool first, last;

void move_left()
{
    if (pointer != NULL && pointer->prev != NULL)
        pointer = pointer->prev;
    else
        first = true;
}

void move_right()
{
    if (first && pointer->next != NULL)
    {
        first = false;
        return;
    }
    if (pointer != NULL && pointer->next != NULL)
    {
        first = false;
        pointer = pointer->next;
    }
}

void delete_element()
{
    if (pointer == NULL || first)
        return;

    if (pointer->prev == NULL && pointer->next == NULL)
    {
        pointer = NULL;
        first = true;
        return;
    }
    else if (pointer->next == NULL)
    {
        pointer->prev->next = NULL;
        pointer = pointer->prev;
    }
    else if (pointer->prev == NULL)
    {
        pointer->next->prev = NULL;
        pointer = pointer->next;
        first = true;
    }
    else
    {
        Node *tmp = pointer;
        pointer->prev->next = tmp->next;
        pointer->next->prev = tmp->prev;
        pointer = pointer->prev;
    }
}

void add_element(char value)
{
    if (pointer == NULL)
    {
        pointer = new Node(value);
    }
    else if (first)
    {
        pointer->prev = new Node();
        pointer->prev->value = value;
        pointer->prev->prev = NULL;
        pointer->prev->next = pointer;
        pointer = pointer->prev;
    }
    else
    {
        Node *tmp = pointer->next;
        pointer->next = new Node(value);
        pointer->next->prev = pointer;
        pointer->next->next = tmp;
        pointer = pointer->next;
    }
    first = false;
}

int main()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    char c;
    root = new Node();


    Node *node = root;

    node->prev = NULL;

    while (isalpha (c = getchar()))
    {
        node->next = new Node();

        node->value = c;
        node->next->prev = node;
        node = node->next;
    }

    pointer = node->prev;
    pointer->next = NULL;

    first = false;

    /*move_left();
    delete_element();
    move_right();
    delete_element();
    move_left();*/

    char asd [2];

    scanf ("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf ("%s", &q);
        if (q [0] == 'L')
            move_left();
        else if (q [0] == 'D')
            move_right();
        else if (q [0] == 'B')
            delete_element();
        else if (q [0] == 'P')
        {
            scanf ("%s", &asd);
            add_element (asd [0]);
        }

        //printf ("value: %c\n", pointer->value);
    }

    while (pointer->prev != NULL)
        pointer = pointer->prev;

    while (pointer != NULL)
    {
        printf ("%c", pointer->value);
        pointer = pointer->next;
    } printf ("\n");

    return 0;
}











