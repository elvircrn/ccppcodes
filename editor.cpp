#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

int cursor_location, string_size;

template <class T>
class linked_list
{
public:

    class Node
    {
    public:
        Node *next;
        T value;

        Node () { next = NULL; }
        Node (T _value) { value = _value; next = NULL; }
    };

    Node *root;

    linked_list () { root = NULL; }

    void Add (T value)
    {
        Node *current = root;
        if (current == NULL)
            root = new Node (value);
        else
        {
            while (current->next != NULL) { current = current->next; }

            current->next = new Node (value);
        }
    }

    void AddAt (int index, T value)
    {
        Node *current = root, *helper;

        if (!index)
        {
            helper = new Node (value);
            helper->next = root;
            swap (helper, root);
            return;
        }

        for (int i = 1; (i < index) && (current->next != NULL); i++, current = current->next);

        helper = new Node (value);
        helper->next = current->next;
        current->next = helper;

        string_size++;
    }

    void GetString()
    {
        char c;
        Node *current = root;
        c = getchar();
        root = new Node (c);
        current = root;
        string_size = 1;
        while (isalpha (c = getchar()))
        {
            current->next = new Node (c);
            current = current->next;
            string_size++;
        }
    }

    void Print ()
    {
        Node *current = root;

        while (current)
        {
            cout<<current->value;
            current = current->next;
        }
    }

    void DeleteAt (int index)
    {
        Node *current = root;

        if (index == 0)
            root = root->next;
        else
        {
            for (int i = 1; i < index; i++)
                current = current->next;

            current->next = current->next->next;
        }

        string_size--;
    }
};

linked_list <char> word;

int main ()
{

    int t;
    char q [10], qq [10];
    word.GetString();

    cursor_location = string_size;

    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%s", &q);
        if (q [0] == 'L')
        {
            cursor_location--;
            if (cursor_location < 0)
                cursor_location = 0;
        }
        else if (q [0] == 'R')
        {
            cursor_location++;
            if (cursor_location > string_size)
                cursor_location = string_size;
        }
        else if (q [0] == 'B')
        {
            if (cursor_location)
                word.DeleteAt (cursor_location);
        }
        else if (q [0] == 'P')
        {
            scanf ("%s", &qq);
            word.AddAt (cursor_location, qq [0]);
            cursor_location++;
        }
    }

    word.Print();

    return 0;
}
