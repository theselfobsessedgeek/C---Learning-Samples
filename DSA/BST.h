#include<iostream>
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

class BST
{
    BinaryTreeNode<int>* root;

    public:
    BST(){
        root = NULL;
    }
    
    private:
    BinaryTreeNode<int>* getMin(BinaryTreeNode<int>* node){
        if(node->left!=NULL){
            return node;
        }
        return getMin(node->left);
    }

    BinaryTreeNode<int>* delNode(BinaryTreeNode<int>*node,int data){
        if (node==NULL)
        {
            return node;
        }
        
        if(node->data>data) {
            node->left = delNode(node->left,data);
            return node ;
        }
        else if(node->data<data){
            node->right = delNode(node->right,data);
            return node;
        }
        else if (node->data==data){
            if (node->left==NULL&&node->right==NULL)
            {
                return nullptr;
            }else if(node->left==NULL&&node->right!=NULL){
                return node->right;
            }else if(node->left!=NULL&&node->right==NULL){
                return  node->left;
            }else {
                BinaryTreeNode<int>* minNode = getMin(node->right);
                int LMin = minNode->data;
                node->data = LMin;
                node->right = delNode(node->right,LMin);
                return node;
            }
            
        }else {
            return NULL;
        }
        
    }

    bool hasData(int data, BinaryTreeNode<int>* node){
        if(node==NULL) return false;
        if (node->data==data) return true;
        if(node->data>data) return hasData(data,node->left);
        else return hasData(data,node->right);
    }
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data>node->data){
            node->right = insert(data,node->right);
            return node;
        }else if(data<node->data){
            node->left = insert(data,node->left);
            return node;
        }else{
            return node;
        }

    }
    public:
    bool hasData(int data){
        return hasData(data,root);
    }
    void deleteData(int data){
        if(delNode(root,data)) root = delNode(root,data);
    }
    void insert(int data){
        root = insert(data,root);
    }
    private:
     void printTree(BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != nullptr)
        {
            cout << "L:" << node->left->data << ",";
        }
        if (node->right != nullptr)
        {
            cout << "R:" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }

    public:
    void print(){
        printTree(root)
    }

};

