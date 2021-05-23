#include<iostream> 
#include"Node.cpp"
using namespace std;
Node *InputNode(){
    int data;
    Node* head=NULL;
    Node* tail;
    cin >> data;
    while (data != -1){
        Node *NewNode = new Node(data);
        if(head==NULL){
            head = NewNode;
            tail = NewNode;
        }else{
            tail -> next = NewNode;
            tail = NewNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head ){
    cout<<"I print stuff"<<endl;
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next;
    }

}
int main(){

    Node* head = InputNode();
    print(head);

    return 0;
}