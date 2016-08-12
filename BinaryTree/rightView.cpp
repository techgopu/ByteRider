/*
Print Right View of a given Binary Tree: Right View contains all the nodes that are last in their level

Algo:
        1)  We can use level order traversal and print last node in every level.

        2)  The problem can also be solved by using a simple recursive traversal. We can track level of a node
            by passing a parameter to all recursive calls. The idea is to keep maximum level also and traverse
            the tree in a manner that right subtree is visited before left subtree. Whenever we see a node whose
            level is more than the maximum level so far, we print that node because this is the last node in
            it's level.
*/


#include<iostream>
using namespace std;
struct node
{
    int key;
    struct node *left, *right;
};


node *newNode(int k)
{
    node *temp = new node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
// Utility function to print right view
void rightViewUtil(struct node *root, int level, int *max_level)
{
    // base case
    if(root==NULL)
        return;
    if(*max_level < level)
    {
        cout<<root->key<<" ";
        *max_level = level;
    }
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);

}

// A warper over rightViewUtil
void printRightView(struct node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}


int main()
{
        node *root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(6);
        root->right->right = newNode(7);
        root->right->right->right = newNode(8);
        printRightView(root);
        return 0;
}










