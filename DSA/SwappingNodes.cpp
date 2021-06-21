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
Node *swapNodes(Node *head, int i, int j){
    if (i>j){
        int temp = j;
        j = i;
        i = temp; 
    }
    Node *ci = head, *pi=head, *cj = head,*pj=head;
    
    if(i==0||j==0){
        if(i-j == 1){
            cj = cj->next;
            Node *temp  = cj->next;
            cj->next = ci;
            ci->next = temp;
            head = cj;
            
        }else{
        	
        	for(int m = 0; m<j-1 ;m++) pj= pj->next;
            cj = pj->next;
            pj->next = ci;
            Node *temp  = ci->next;
            ci->next = cj ->next;
            cj ->next = temp;
            head = cj;
        	  
        }
    }else{
        for(int m = 0; m<j-1 ;m++) pj= pj->next;
        for(int n = 0; n<i-1 ;n++) pi= pi->next;
        ci = pi->next;
        cj = pj->next;
        pj->next = ci;
        pi->next = cj;
        Node *temp  = ci->next;
        ci->next = cj ->next;
        cj ->next = temp;
    }
    return head;
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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}