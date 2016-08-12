/*
    Given a binary tree print out all the root to leaf path one per line
    Algo:
    Initialize pathlen = 0, path[100]
    printPathRecurse traverse the nodes of tree in preOrder
    printPathRecurse(tree, path[],pathlen)
        1) if node is not null then
            a) push data to path array
                path[pathlen] = node->data;
            b) increment pathlen
                pathlen++;
        2) if node is leaf, print the path array
        3) else
            a) call printPathRecurse for left sub tree
                printPathRecurse(node->left,path, pathlen)
            b) call printPathRecurse for right sub tree
                printPathRecurse(node->right,path,patlen)
*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;

};
// Function prototyping
void printArray(int arr[],int len);
void printPathRecurse(node *,int path[],int pathlen);
node *newNode(int);
void printPath(node *);

// Function to create new Node
node *newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//Function to print paths
void printPath(node *root)
{
    int path[1000];
    printPathRecurse(root,path,0);
}

// Utility function to print paths from root to leaf one per linear_congruential
void printPathRecurse(node *root, int path[], int pathlen)
{
    if(root)
    {
        //append root's data to the path array
        path[pathlen++] = root->data;
        //if it is a leaf node, print the array
        if(root->left==NULL && root->right==NULL)
            printArray(path, pathlen);
        else
        {
            //try both the sub trees
            printPathRecurse(root->left,path,pathlen);
            printPathRecurse(root->right,path,pathlen);
        }
    }

}
// Function to print array
void printArray(int arr[],int len)
{
    for(int i=0; i<len; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
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
    printPath(root);
    return 0;
}







