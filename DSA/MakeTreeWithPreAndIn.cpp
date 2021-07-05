#include<iostream> 

using namespace std;
template <typename T>
class BinaryTreeNode {
	public : 
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
	BinaryTreeNode(T data) {
    	this -> data = data;
    	left = NULL;
    	right = NULL;
	}
};

BinaryTreeNode<int>* returnTree(int *pre,int *in){

}
int main(){

    

    return 0;
}