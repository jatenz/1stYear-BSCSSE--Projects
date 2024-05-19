#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *a = NULL;
Node *b = NULL;
Node *c = NULL;

int main(){
    a = new Node;
    a -> data = 2;
    a -> next = NULL;

    b = new Node;
    b -> data = 23;
    b -> next = NULL;

    c = new Node;
    c -> data = 2024;
    c -> next = NULL;

    a -> next = b;
    b -> next = c;
    c -> next = NULL;

    cout << a -> data << endl;
    cout << b -> data << endl;    
    cout << c -> data << endl;

    return 0;
}