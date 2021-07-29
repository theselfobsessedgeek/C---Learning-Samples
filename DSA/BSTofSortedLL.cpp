#include<bits/stdc++.h>
template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
pair<Node<int>*,Node<int>*> constructLinkedListHelper(BinaryTreeNode<int>* root){

    pair<Node<int>*,Node<int>*> p;
    p.first = NULL,p.second=NULL;
    if(root==NULL) return p;

    pair<Node<int>*,Node<int>*> lpair = constructLinkedListHelper(root->left);
    pair<Node<int>*,Node<int>*> rpair = constructLinkedListHelper(root->right);
    Node<int>* middle = new Node<int>(root->data);
    
    if(root->left!=NULL){
        lpair.second->next = middle;
    }else{
        lpair.first = middle;
    }
    if(root->right!=NULL){
        middle->next=rpair.first;
    }
    else rpair.second = middle;

    p.first = lpair.first;
    p.second = rpair.second;

    return p;

}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return constructLinkedListHelper(root).first;
}


BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}