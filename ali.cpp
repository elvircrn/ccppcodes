#include <iostream>


using namespace std;

struct node{
    int value;
    node *next;
    node *back;
};

node *root=NULL;

void add(int value){
    node *current=root;
    if(current==NULL){
        root=new node();
        root->value=value;
        root->next=NULL;
        root->back=NULL;
        return;
    }
    while(true){
        if(current->next==NULL) break;
        current=current->next;
    }
    current->next=new node();
    current->next->next=NULL;
    current->next->value=value;
    current->next->back=current;
}

void remove(int vrijednost){
    cout<<"remove"<<endl;
    node *current=new node;
    current=root;
    while(true){
        cout<<current->value<<endl;
        if(current->next==NULL) break;
        if(current->value==vrijednost){
            node *temp=current->back;
            cout<<"afasdf"<<endl;
            temp->next=current->next;
            temp=current->next;
            temp->back=current->back;

            break;
        }
        current=current->next;
    }
}

int main(){
    for (int i = 0; i < 5; i++)
        add (i);

    remove (4);
    remove (3);
    remove (2);

    return 0;
}
