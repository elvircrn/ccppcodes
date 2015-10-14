#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define line contacts [contact_index]

struct node
{
    node *next [11];
    int val;

    node()
    {
        val = -1;
    }
};


int main()
{
    node *ptr;// = new node();
    //if (ptr->val == -1)
    //    cout<<"dfdfdfg"<<endl;
    cout<<ptr->val<<endl;
    return 0;
}

/*
4 5
099/123-456 Imenko Prezimenko
098/000-001 Mujo Suljic
097/000-001 Stjepan Ivic
096/000-001 Nenad Neno Dragic
*/


















