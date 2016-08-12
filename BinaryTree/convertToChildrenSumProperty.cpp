/*
    Convert an arbitrary binary tree to a tree that holds children sum property:
    Algo:
    Traverse the given tree in post order.
    diff = node's children sum - node's data
    if diff = 0 then nothing to be done
    if diff > 0 (node's data is smaller than children sum) then increment nodes data by diff
    if diff < 0 (node's data is greater than the children sum) then increment the one child data.
        we have to chose to increment either left child or right child if they both aren't null. Let us always
        increment the left child. Incrementing the child changes the subtree children sum property so we need to
        increment left subtree also. If left child is empty then we recursively call increment for right child.

*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void increment(node *,int);
node *newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void convertChildrenSum(node *root)
{
    if(root==NULL || (root->left==NULL && root->right == NULL))
        return;
    else
    {
    int leftData = 0, rightData = 0, diff;
    convertChildrenSum(root->left);
    convertChildrenSum(root->right);
    if(root->left)
        leftData = root->left->data;
    if(root->right)
        rightData = root->right->data;

    diff = leftData + rightData - root->data;
    if(diff>0)
        root->data = root->data+diff;
    if(diff<0);
        increment(root,-diff); // here -diff used to make diff positive
    }
}

void inorderTraverse(node *root)
{
    if(root==NULL)
        return;
    inorderTraverse(root->left);
    cout<<root->data<<" ";
    inorderTraverse(root->right);
}

void increment(node *root,int diff)
{
    if(root->left)
    {
        root->left->data += diff;
        increment(root->left,diff);
    }
    else if(root->right)
    {
        root->right->data += diff;
        increment(root->right,diff);
    }
}
int main()
{
    node *root = newNode(50);
    root->left = newNode(7);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right = newNode(2);
    root->right->left = newNode(1);
    root->right->right = newNode(30);
    convertChildrenSum(root);
    inorderTraverse(root);
    return 0;
}
