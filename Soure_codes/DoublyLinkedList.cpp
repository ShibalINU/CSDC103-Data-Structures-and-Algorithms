#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

typedef Node* NodePtr;


// Create an empty doubly linked list
void createHead(NodePtr& Head) {
    Head = new Node;

    // Dummy head points to itself
    Head->next = Head;
    Head->prev = Head;
}


// Insert a new node before Cur
void insertNode(NodePtr Cur, int item) {
    NodePtr New = new Node;

    New->data = item;

    // Connect New to Cur
    New->next = Cur;
    New->prev = Cur->prev;

    // Connect Cur to New
    Cur->prev = New;
    (New->prev)->next = New;
}


// Delete a node
void deleteNode(NodePtr Cur) {
    // Connect the previous node to the next node
    (Cur->prev)->next = Cur->next;

    // Connect the next node to the previous node
    (Cur->next)->prev = Cur->prev;

    delete Cur;
}


// Display the list
void print(NodePtr Head) {
    NodePtr Cur = Head->next;

    while (Cur != Head) {
        cout << Cur->data << " ";
        Cur = Cur->next;
    }

    cout << endl;
}


int main() {

    NodePtr Head;

    // Create empty doubly linked list
    createHead(Head);

    // Insert nodes
    insertNode(Head, 10);
    insertNode(Head, 20);
    insertNode(Head, 30);
    insertNode(Head, 40);

    cout << "Original list: ";
    print(Head);

    // Delete a node
    NodePtr Cur = Head->next->next;  // points to 20
    deleteNode(Cur);

    cout << "After deleting 20: ";
    print(Head);

    return 0;
}
