/*
    For a given tree, check the tree follows the children sum property
    Algo:
        Traverse the given tree for each node, if the node and both the children follows the children sum property,
        if so then return true else return false

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

bool isSumProperty(node *root)
{
    int leftData = 0,rightData = 0;
    //if node is null of it is a leaf node, then return true
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    else
    {
        // if left or right child is missing then 0 is used as data;
        if(root->left!=NULL)
            leftData = root->left->data;
        if(root->right!=NULL)
            rightData = root->right->data;
        if(root->data==(leftData+rightData)&& isSumProperty(root->left) && isSumProperty(root->right))
            return true;
        else
            return false;
    }
}
int main()
{
    node *root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(5);
    if(isSumProperty(root))
        cout<<"Yes";
    else
        cout<<"NO";
    return 0;

}
