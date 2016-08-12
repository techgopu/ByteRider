/*
    Width of the binary tree is maximum width of all level.
    it can be solve by two methods:
    1) using level order traversal.
    2) using pre order traversal.
        Using pre order traversal:
            using this method we create a temporary array count[] of size equal to the height of the tree.
            Initialize all value of count as 0. Traverse array in pre order and fill the entries in count
            so that the count array contains count of nodes at each level in the binary tree.
*/
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node *newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}



int height(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        return (lHeight > rHeight ? lHeight+1 : rHeight+1);
    }
}
int getMax(int arr[],int n)
{
    int maxElement = arr[0];
    for(int i =1; i<n; i++)
    {
        if(maxElement<arr[i])
            maxElement = arr[i];
    }
    return maxElement;
}
void getMaxWidthUtil(node *root, int countArray[],int level)
{
    if(root)
    {
        countArray[level]++;
        getMaxWidthUtil(root->left,countArray,level+1);
        getMaxWidthUtil(root->right,countArray,level+1);
    }
}
int  getMaxWidth(node *root)
{
    int h = height(root);
    int *countArray = new int[h];
    int level = 0;
    getMaxWidthUtil(root,countArray,level);
    return getMax(countArray,h);
}
int main()
{
    node *root = newNode(10);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(9);
    root->right->right = newNode(8);
    cout<<getMaxWidth(root);
    return 0;
}
