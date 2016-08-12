/*
    Print nodes at K distance form root.
    Given root of a tree and an integer k, print nodes which are at k distance from root.
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

void printAtKDistace(node *root, int k)
{
    if(root==NULL)
        return;
    if(k==0 && root!=NULL)
        cout<<root->data<<" ";
    printAtKDistace(root->left,k-1);
    printAtKDistace(root->right,k-1);
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->left->left = newNode(4);
    root->left->left->left = newNode(7);
    printAtKDistace(root,2);
    return 0;
}
