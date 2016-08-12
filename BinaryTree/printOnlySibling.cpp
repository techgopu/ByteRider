/*
Print all nodes that don't have sibling:

Algorithm:
We start from root and check if the root have one child, if yes then print the only child of that node. If node
have both the children then recur for both the children

*/
#include<iostream>
using namespace std;

struct node
{
        struct node *left, *right;
        int key;
};

node *newNode(int k)
{
    node *temp = new node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to print the nodes that don't have any sibling

void printSingle(struct node *root)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    else if(root->left != NULL && root->right != NULL)
    {
        printSingle(root->left);
        printSingle(root->right);
    }
    // if right child is NULL and left child isn't NULL, print left child
    else if(root->left!=NULL)
    {
        cout<<root->left->key<<" ";
        printSingle(root->left);
    }
    // if left child is null and right child isn't null, print right child
    else if(root->right != NULL)
    {
        cout<<root->right->key<<" ";
        printSingle(root->right);
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->right = newNode(5);
    root->right->left = newNode(6);
    printSingle(root);
    return 0;
}









