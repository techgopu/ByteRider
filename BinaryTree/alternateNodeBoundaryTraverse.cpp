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
int static pathlen = 0;
int path[1000];
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

void printLeave(node *root, int path[],int pathlen)
{
    if(root)
    {
        printLeave(root->left,path,pathlen);
        if(!(root->left) && !(root->right))
        {
            path[pathlen] = root->data;
            pathlen++;
            //cout<<root->data<<" ";
        }
        printLeave(root->right,path,pathlen);
    }
}

// Print left boundary in top down manner
void printLeftBoundary(node *root, int path[], int pathlen)
{
    if(root)
    {
        if(root->left)
        {
            //cout<<root->data<<" ";  // print first to ensure top down
            path[pathlen] = root->data;
            pathlen++;
            printLeftBoundary(root->left,path, pathlen);
        }
        else if(root->right)
        {
            //cout<<root->data<<" ";
            path[pathlen] = root->data;
            pathlen++;
            printLeftBoundary(root->right,path, pathlen);
        }
    }
}

// print right boundary in bottom up manner
void printRightBoundary(node *root,int path[],int pathlen)
{
    if(root)
    {
        if(root->right)
        {
            printRightBoundary(root->right,path, pathlen); // first recurse to right to ensure bottom up
            //cout<<root->data<<" ";
            path[pathlen] = root->data;
            pathlen++;
        }
        else if(root->left)
        {
            printRightBoundary(root->left,path, pathlen);
            //cout<<root->data<<" ";
            path[pathlen] = root->data;
            pathlen++;
        }
    }
}

// utility function to print boundary
void printBoundaryUtill(node *root, int path[], int pathlen)
{
    if(root)
    {
        //print root
        //cout<<root->data<<" ";
        path[pathlen] = root->data;
        pathlen++;
        // print left boundary
        printLeftBoundary(root->left,path,pathlen);
        //print left sub tree leave
        printLeave(root->left,path,pathlen);
        //print right sub tree leave
        printLeave(root->right,path,pathlen);
        //print right boundary
        printRightBoundary(root->right,path,pathlen);
    }
}
void printArray(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
}

// main function to print boundary traversal
void printBoundary(node *root)
{
    //int path[1000];
    printBoundaryUtill(root,path,pathlen);
    printArray(path,pathlen);
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
    cout<<path[0]<<" "<<path[1]<<" "<<path[2];
    cout<<pathlen;
    for(int i=0; i<10; i++)
        cout<<path[i];

    return 0;
}
