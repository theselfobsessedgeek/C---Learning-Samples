#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* right;
    BinaryTreeNode<T>* left;
    BinaryTreeNode(T data){
        
        this->data = data;
        this->left=NULL;
        this->right = NULL;

    }
};

class BST{
    public:
    int height;
    int min; 
    int max;
    bool isBST;
    
};

BST largestBST(BinaryTreeNode<int>* root,int max=INT_MAX,int min=INT_MIN) {
    
    if(root==NULL){
        BST p;
        p.height = 0;
        p.isBST = true;
        return p;
    }
    
    BST lBST = largestBST(root->left,);
    BST rBST = largestBST(root->right,);
    
    if(lBST.isBST){
        if
    }
    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    BST tree;
    tree = largestBST(root);
    return tree.height;
}

int main(){
    
    
    return 0;

}