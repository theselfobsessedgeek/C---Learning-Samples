#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node *reverseLL(Node* head){
    if(head==NULL||head->next==NULL) return head;
    Node *smallAns = reverseLL(head->next);
    Node *tail = head->next;
    tail->next  = head;
    head ->next  = NULL;
    return smallAns;
}
Node *kReverse(Node *head, int k)
{
	if(head==NULL||head->next==NULL) return head;
    Node *h1 = head;
    Node *t1 = head;
    for(int i = 0;i<k&&t1!=NULL;i++){
        t1 = t1->next;
    }
    Node *h2 = NULL;
    if(t1 !=NULL) {
        h2 = t1->next;
        t1 -> next = NULL;
    }
    h2 = kReverse(h2,k);
    h1 = reverseLL(h1);
    t1 = h1;
    for(int i = 0;i<k&&t1->next!=NULL;i++){
        t1 = t1->next;
    }
    t1 ->next  = h2;

    return h2 ; 
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}