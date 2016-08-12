/*
    Given root of the tree and a value of a node in the tree. write a function to return level of the given node.
    Assuming that level of the root node is 1.
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
int getLevelUtil(node *root, int key, int level)
{
    if(root==NULL)
        return 0;
    if(root->data==key)
        return level;
    int downLevel = getLevelUtil(root->left,key,level+1);
    if(downLevel!=0)
        return downLevel;
    downLevel = getLevelUtil(root->right,key,level+1);
        return downLevel;


}
int getLevel(node *root, int key)
{
    return getLevelUtil(root,key,1);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->left->left = newNode(4);
    root->left->left->left = newNode(7);
    cout<<getLevel(root,7);
    return 0;
}
