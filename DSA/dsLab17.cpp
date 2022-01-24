#include <iostream>
using namespace std;
int search(int *array, int x, int n)
{
    for (int i = 0; i < n; i++)
    if (array[i] == x)
        return i;
    return -1;
}
void printPostOrder(int *inOrder, int *preOrder, int n)
{
    int root = search(inOrder, preOrder[0], n);
    if (root != 0)
        printPostOrder(inOrder, preOrder + 1, root);
    if (root != n - 1)
        printPostOrder(inOrder + root + 1, preOrder + root + 1, n - root -1);
    cout << preOrder[0] << " ";
}
int main()
{
    int inorder[] = { 7, 2, 10, 1, 17, 6 };
    int preorder[] = { 1, 2, 7, 10, 17, 6 };
    int n = sizeof(inorder) / sizeof(inorder[0]);
    cout << "Postorder traversal " << endl;
    printPostOrder(inorder, preorder, n);
    return 0;
}