#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next; 
};

typedef Node* NodePtr;

// Add at the beginning
void addHead(NodePtr& head, int newdata) {
	NodePtr newPtr = new Node;
	
	newPtr->data = newdata;
	newPtr->next = head;
	
	head = newPtr;
}

// Deleting head
void deleteHead(NodePtr& head) {
	if (head != NULL) {
		NodePtr p = head; // keep track of node that wil be deleted
		head = head->next; // secode node will become the new head
		delete p; // delete the first node from memory
	}
}

void displayList(NodePtr head) {
	NodePtr p = head;
	
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;	
}

int main() {
    NodePtr head = NULL;

    char c;
    int n;
    
    while(cin >> c >> n){
        if(c == 'i'){
            addHead(head, n);
        }else if(c == 'd'){
            if(head == NULL){
                cout << "THE LIST IS ALREADY EMPTY" << endl;
            }else{
                deleteHead(head);
                displayList(head);    
            }
        }else{
            cout << "INVALID COMMAND" << endl;
        }
    } 
    return 0;
}  
