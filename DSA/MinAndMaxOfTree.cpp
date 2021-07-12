#include <iostream>
#include <queue>

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
int getSum(BinaryTreeNode<int>* root) {
    if(root==NULL) return 0;

    int lsum = getSum(root->left);
    int rsum = getSum(root->right);

    return root->data+lsum+rsum;
}
int height(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1+max(lh,rh);
}

bool isBalanced(BinaryTreeNode<int> *root) {
    if (root==NULL) return false;
    int lh = height(root->left);
    int rh = height(root->right);
    
    int diff = abs(lh-rh);

    if (diff>1) return false;
    
    bool isRBal = isBalanced(root->right);
    bool isLBal = isBalanced(root->left);

    return isRBal&&isLBal;
}
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	if(root==NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    // pair : ( max , min )
    pair<int,int> lAns = getMinAndMax(root->left);
    pair<int,int> rAns = getMinAndMax(root->right);
    int lmax = lAns.first;
    int lmin = lAns.second;
    int rmax  = rAns.first;
    int rmin = rAns.second;
    pair <int,int > returningVal;
    int ma =  max(max(lmax,rmax),root->data);
    int mi = min(min(rmin,lmin),root->data);

    returningVal.first = ma;
    returningVal.second = mi;

    return returningVal;

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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}