#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* Nodeptr;

int main()
{
    Node* p; //Nodept p
    p = new Node;
    
    p->data = 20;
    p->next = NULL;
    
    cout << "Data : " << p->data << endl;
    
    return 0;
}
