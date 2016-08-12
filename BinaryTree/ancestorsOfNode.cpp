/*
    Given a node of a binary tree and a key, print it's ancestors.

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
bool printAncestors(node *root, int key)
{
    if(root==NULL)
        return false;
    if(root->data == key)
        return true;
    if(printAncestors(root->left,key) || printAncestors(root->right,key))
    {
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->left->left = newNode(4);
    root->left->left->left = newNode(7);
    printAncestors(root,7);
    return 0;
}




