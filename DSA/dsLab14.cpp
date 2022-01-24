#include <iostream>
using namespace std;
class Node
{
    public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *insertData()
{
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cout << "Enter the data in the LL (enter -1 to end)" << endl;
    cin >> data;
        while (data != -1)
        {
            Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
Node *reverseLL(Node *head)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    return head;
}
void splitLL(Node *head)
{
    Node *temp = head;
    int length = 0;
    Node *head2 = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    temp = head;
    if (length % 2 == 0)
    {
        for (int i = 1; i < length / 2; i++){
            temp = temp->next;
            head2 = head2->next;
        }
        head2 = head2->next;
        temp->next = NULL;
    }
    else
    {
        for (int i = 0; i < length / 2; i++)
        {
            temp = temp->next;
            head2 = head2->next;
        }
        head2 = head2->next;
        temp->next = NULL;
    }
    head2 = reverseLL(head2);
    temp = head;
    cout << "First part of the LL is " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = head2;
    cout << "Second part of the LL is " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    Node *head = insertData();
    splitLL(head);
    return 0;

}