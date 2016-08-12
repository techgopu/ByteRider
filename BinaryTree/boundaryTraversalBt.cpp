/*
Given a binary tree, print the boundary traversal of it.
Algo:
    Break the problem into three parts:
        1) print the left boundary in top down manner
        2) print all the leave from left to right which again can be divided into two sub parts
            2.1) print all leaf of left sub tree from left to right.
            2.2) print all leaf of right sub tree from left to right.
        3) print the right boundary in bottom up manner

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
// Auxiliary function to print leave

void printLeave(node *root)
{
    if(root)
    {
        printLeave(root->left);
        if(!(root->left) && !(root->right))
            cout<<root->data<<" ";
        printLeave(root->right);
    }
}

// Print left boundary in top down manner
void printLeftBoundary(node *root)
{
    if(root)
    {
        if(root->left)
        {
            cout<<root->data<<" ";  // print first to ensure top down
            printLeftBoundary(root->left);
        }
        else if(root->right)
        {
            cout<<root->data<<" ";
            printLeftBoundary(root->right);
        }
    }
}

// print right boundary in bottom up manner
void printRightBoundary(node *root)
{
    if(root)
    {
        if(root->right)
        {
            printRightBoundary(root->right); // first recurse to right to ensure bottom up
            cout<<root->data<<" ";
        }
        else if(root->left)
        {
            printRightBoundary(root->left);
            cout<<root->data<<" ";
        }
    }
}

// main function to print boundary
void printBoundary(node *root)
{
    if(root)
    {
        //print root
        cout<<root->data<<" ";
        // print left boundary
        printLeftBoundary(root->left);
        //print left sub tree leave
        printLeave(root->left);
        //print right sub tree leave
        printLeave(root->right);
        //print right boundary
        printRightBoundary(root->right);
    }
}
int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right->right = newNode(25);
    printBoundary(root);
    return 0;
}
