#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* NodePtr;

void addHead (NodePtr& head, int newdata){
    NodePtr newPtr = new Node;
    
    newPtr->data = newdata;
    newPtr->next = head;
    
    head = newPtr;
}

void displayList(NodePtr head){
    NodePtr p = head;
    while (p != NULL){
        cout << p->data << " ";
        p = p-> next;
    }
    cout << endl;
}


int main()
{
    Node* head = NULL;
    
    addHead(head, 20);
    addHead(head, 13);
    
    cout << "List: ";
    displayList(head);
    
    addHead(head, 50);
    cout << "After adding 50 at the head: ";
    displayList(head);

    return 0;
}
