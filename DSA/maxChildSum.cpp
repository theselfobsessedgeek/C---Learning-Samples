#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

int getSum(TreeNode<int> *node){
    int sum =0;
    for(int i = 0;i<node->children.size();i++){
        sum += node->children[i]->data;
    }
    return sum;
}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root == NULL) return NULL;
    TreeNode<int> *result = root;
    int maxSum = getSum(root);
    
    for(int i = 0;i<root->children.size();i++){
        
        TreeNode<int> * temp = maxSumNode(root->children[i]);
        int sum = getSum(temp);
        if(sum>maxSum){
            result =temp;
            maxSum = sum;
        }
    }

    return result;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}