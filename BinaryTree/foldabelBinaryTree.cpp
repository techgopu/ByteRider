/*
    A binary tree can be forded if left and right subtree of the tree is structure wise mirror of each other.
    A empty tree is considered as foldable.
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
bool isFoldableUtil(node *n1, node *n2)
{
    //if both of the subtrees are unavailable then return true
    if(n1==NULL && n2==NULL)
        return true;
    //if either of the subtree is unavailable then return false
    if(n1==NULL || n2==NULL)
        return false;
    //check if left subtree and right subtree are mirror of each other
    return(isFoldableUtil(n1->left,n2->right)&&isFoldableUtil(n1->right,n2->left));
}
bool isFoldable(node *root)
{
    if(root==NULL)
        return true;
    else
        isFoldableUtil(root->left,root->right);
}

int main()
{
    node *root = newNode(10);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(9);
    root->right->right = newNode(8);
    if(isFoldable(root))
        cout<<"YES! Given tree is foldable!";
    else
        cout<<"NO! Given tree is not foldable!";
    return 0;
}
