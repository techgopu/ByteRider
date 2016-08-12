/*
    program to spiral print of a binary tree.
    We can print a binary tree in spiral order using three techniques. All techniques takes time complexity
    O(n) and space complexity also O(n).
    1)using two stacks.
    2)using dequeue and delimiter
    3)using dequeue and counter
*/
// using two stacks
#include<iostream>
#include<stack>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
}

void spiralTraversal(Node *root)
{
    if(root==NULL)
        return;
    stack < struct Node* > s1;
    stack < struct Node* > s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            root = s1.top();
            s1.pop();
            cout<<root->data<<" ";
            if(root->left)
                s2.push(root->left);
            if(root->right)
                s2.push(root->right);
        }
        while(!s2.empty())
        {
            root = s2.top();
            s2.pop();
            cout<<root->data<<" ";
            if(root->right)
                s1.push(root->right);
            if(root->left)
                s1.push(root->left);
        }
    }
}
int main()
{
    Node *root = newNode(76);
    root->left = newNode(33);
    root->left->left = newNode(43);
    root->left->right = newNode(63);
    root->right = newNode(54);
    root->right->right = newNode(65);
    root->right->left = newNode(68);
    spiralTraversal(root);

    return 0;
}












