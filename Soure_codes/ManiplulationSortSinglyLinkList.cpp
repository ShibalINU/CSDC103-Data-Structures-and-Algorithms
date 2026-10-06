//MANIPULATION OF SORTED SINGLY LINKED LIST
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// INSERT
void insertNode(Node*& head, int item) {

    Node* newPtr = new Node;
    newPtr->data = item;

    Node* prev = NULL;
    Node* cur = head;

    // Find correct position
    while (cur != NULL && item > cur->data) {
        prev = cur;
        cur = cur->next;
    }

    // Insert at head
    if (prev == NULL) {
        newPtr->next = head;
        head = newPtr;
    }

    // Insert elsewhere
    else {
        newPtr->next = cur;
        prev->next = newPtr;
    }
}

// DELETE
void deleteNode(Node*& head, int item) {

    Node* prev = NULL;
    Node* cur = head;

    while (cur != NULL && cur->data != item) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Item not found." << endl;
        return;
    }

    if (prev == NULL)
        head = cur->next;
    else
        prev->next = cur->next;

    delete cur;
}

// DISPLAY
void displayList(Node* head) {

    Node* cur = head;

    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

int main() {

    Node* head = NULL;

    // Insert
    insertNode(head, 40);
    insertNode(head, 20);
    insertNode(head, 60);
    insertNode(head, 50);
    insertNode(head, 10);

    cout << "Sorted list: ";
    displayList(head);

    // Delete
    deleteNode(head, 40);

    cout << "After deleting 40: ";
    displayList(head);

    // Insert again
    insertNode(head, 30);

    cout << "After inserting 30: ";
    displayList(head);

    return 0;
}
