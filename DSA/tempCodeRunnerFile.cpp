bool searchInBST(BinaryTreeNode<int> *root , int k) {
	if (root==NULL) return false;
    if(root->data==k) return true;
    BinaryTreeNode<int> *nextNode;
    if (k<root->data)
    {
        nextNode = root->left;
    }else{
        nextNode = root->right;
    }
    
    bool find = searchInBST(nextNode,k);
    return find;
    
}