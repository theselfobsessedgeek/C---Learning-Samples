#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
	// Define the data members
    Node*head;
    int size;

   public:
    Stack() {
        head = NULL;
        size= 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
        // Implement the getSize() function
    }

    bool isEmpty() {
        return head==NULL;
        // Implement the isEmpty() function
    }

    void push(int element) {
        Node *elem = new Node(element);
        elem->next=head;
        this->head = elem;
        size++;
        // Implement the push() function
    }

    int pop() {
        if(isEmpty()) return 0;
        int val = head->data;
        size--;
        head = head->next;
        return val;
    }

    int top() {
        return head->data;
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}