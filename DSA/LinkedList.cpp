#include<iostream> 
#include"Node.cpp"
using namespace std;
Node *appendLastNToFirst(Node *head, int n)
{   
    if (head!=NULL&&n>0){
        int len=1;
        Node*hCount= head;
        while(hCount->next!=NULL){
            hCount=hCount->next;
            len++;
        }
        if (n<len){
            Node*tailNode=head;
        	for (int i = 0;i<(len-n-1);i++){
        	    tailNode = tailNode->next;
        	}
        	Node* newHead = tailNode->next;
        	tailNode->next=NULL;
        	hCount->next=head;
        	return newHead;
        }
    }else{
        return head;
    }
}
Node *removeDuplicates(Node *head)
{   
    Node*currNode=head;
    while(currNode->next!=NULL){
        if(currNode->data==currNode->next->data){
            currNode->next=currNode->next->next;
        }
        currNode = currNode->next;
    }
    return head;
}
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

// Recursively inserting funciton
Node * insertNode(Node *head,Node* nextNode, int i, int data,Node*tail=NULL){
    if(nextNode==NULL&&i!=0) return head;
    else if(nextNode!=NULL&&i==0){
        Node *newNode = new Node(data);
        if(tail == NULL){
            newNode->next = head;
            head = newNode;
        }
        else{
            newNode->next = tail->next;
            tail->next = newNode;
        }
        return head;
    }else{
        return insertNode(head,nextNode->next,i-1,data,nextNode);
    }
}

// recursively deleting funv
Node *delNodeRec(Node *head,Node*nextNode, int i,Node*tail=NULL) {
    if(nextNode==NULL&&i!=0) return head;
    else if(nextNode!=NULL&&i==0){
        if(tail == NULL){ 
            head = head->next;
        }
        else{
            tail->next = nextNode->next;
        }
        return head;
    }else{
        return delNodeRec(head,nextNode->next,i-1,nextNode);
    }
	//Write your code here
}


Node *InsertNode(int data,int pos,Node*head){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 0;
    if(pos == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    while(temp!=NULL && count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        newNode ->next = temp->next;
        temp->next = newNode;
    }                                                                               
    return head;

}
Node* delNode(Node* head,int pos){
    int count = 0;
    Node*temp=head;
    if (pos ==0){
        head = temp -> next;
        return head;
    }
    while(count<pos -1){
        temp= temp->next;
        count++;
    }
    
    if(temp!=NULL){
        Node *a = temp->next;
        temp ->next = a->next;
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
Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    /* reverse the rest list and put
      the first element at the end */
    Node* rest = reverse(head->next);
    head->next->next = head;

    /* tricky step -- see the diagram */
    head->next = NULL;

    /* fix the head pointer */
    return rest;
}
int main(){

    Node* head = InputNode();
    print(head);
    head = reverse(head);
    print(head);

    return 0;
}