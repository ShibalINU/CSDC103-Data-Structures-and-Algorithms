#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main()
{
    Node* head = NULL;
    
    //first Node
    Node* newPtr = new Node;
    newPtr->data = 20;
    newPtr->next = NULL;
    head = newPtr;
    
    //add 13 at the beginning
    newPtr = new Node;
    newPtr-> data = 13;
    newPtr->next = head;
    head = newPtr;
    
    cout << "data: " << head->data << endl;
    cout << "data: " << head->next->data << endl;

    return 0;
}
