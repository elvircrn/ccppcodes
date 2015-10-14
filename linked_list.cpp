#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

template <class T>
class linked_list
{
public:

    int SIZE;

    class node
    {
    public:

        node *next;
        T data;

        node() { }
        node(T DATA)
        {
            data = DATA;
            next = NULL;
        }

        bool operator == (const node &B) const
        {
            return data == B.data;
        }
    };


    node *root, *current;

    linked_list()
    {
        SIZE = 0;
        root = NULL;
    }

    void Add (T DATA)
    {
        if (root == NULL)
        {
            root = new node(DATA);
            current = root;
        }
        else
        {
            current = root;
            while (current->next)
                current = current->next;
            current->next = new node (DATA);
        }
        SIZE++;
    }

    bool Delete (T DATA)
    {
        node *previous = NULL;

        if (root->data == DATA)
        {
            root = root->next;
            SIZE--;
            return true;
        }

        for (node *iterator = root; iterator; iterator = iterator->next)
        {
            if (iterator->data == DATA)
            {
                previous->next = iterator->next;
                SIZE--;
                return true;
            }

            previous = iterator;
        }

        return false;
    }

    T &operator[] (int index)
    {
        node *now = root;

        for (int i = 0; i < index; i++)
            now = now->next;

        return now->data;
    }

    void Iterate()
    {
        for (node *iterator = root; iterator; iterator = iterator->next)
        {
            cout<<iterator->data<<endl;
        }
    }
};

linked_list <int> List;

int main ()
{

    return 0;
}












