#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
};

Node* head=NULL;

Node* insertBeginning(int data) {
    Node* newNode = new Node(); newNode->data=data;
    if(head==NULL) {
        head=newNode;
    }
    else if(head!=NULL) {
        newNode->next=head;
        head=newNode;
    }
    return head;
}

Node* insertNode(int pos,int data) {
    Node* newNode = new Node(); newNode->data=data;
    if(head==NULL) {
        head=newNode;
    }
    else {
        Node* ptr=head;
        for(int i=1;i<pos;i++) {
            ptr=ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next=newNode;

    }
    return head;
}

void print(Node* n) {
    while (n != NULL) {
        cout << n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}
int main() {
    
    insertBeginning(20);
    insertBeginning(16);
    insertBeginning(40);
    insertBeginning(92);
    insertNode(1,80);
    print(head);

    return 0;
}