#include<bits/stdc++.h> 

using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> * left;
    BinaryTreeNode<T> * right;
    
    BinaryTreeNode(T data){
    this->data= data;
    left = NULL;
    right = NULL;
    }
};


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Problem 20 : Level Wise Traversal
void printLevelWise(BinaryTreeNode<int> *root) {
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        if(q.front()==NULL){
            q.pop();
            if(q.empty()) break;
            q.push(NULL);
            cout<<endl;
            continue;
        }
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL) {
            q.push(front->right);
        }
        cout<<q.front()->data<<" ";
        q.pop(); 
        
        
    }
}
// Problem 19 :  Mirror Image Of Binary Tree
BinaryTreeNode<int>* mirrorImage(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return NULL;
    }
    root->left =  mirrorImage(root->left);
    root-> right  = mirrorImage(root->right);
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right  = temp;
    
    return root;
}

int main(){

    BinaryTreeNode<int> *root = takeInput();
    
    printLevelWise(root);


    BinaryTreeNode<int> *mirror = mirrorImage(root);
    
    printLevelWise(mirror);
    return 0;
}