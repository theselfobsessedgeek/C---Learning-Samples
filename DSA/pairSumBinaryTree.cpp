#include<bits/stdc++.h>

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


void flattenBT(BinaryTreeNode<int>* root,vector<int>* v){
    if(root==NULL) return;
    v->push_back(root->data);
    flattenBT(root->left,v);
    flattenBT(root->right,v);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> *v = new vector<int>();
    flattenBT(root,v);
    sort(v->begin(),v->end());
    // for(int i = 0;i<v->size();i++) cout<<v->at(i)<<endl;
    int i = 0;
    int j = v->size()-1;
    
    while (i<j)
    {
        int currSum = v->at(i)+v->at(j);
        if(currSum==sum) {
            cout<<v->at(i)<<" "<<v->at(j)<<endl;
            i++;
            j--;
            continue;
        }
        else if(currSum>sum){
            j--;
            continue;
        }
        else if(currSum<sum){
            i++;
            continue;
        }
        
    }
    
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}