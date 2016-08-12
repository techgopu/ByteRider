/*
Program to print reverse level by level order traversal.
We can solve this using one stack and one queue.
Time and space complexity is O(n)
Algo:
    1)add root of the tree to the queue
    2)loop until queue is not empty
        2.1)root = queue.top()
        2.2)if root->right!=NULL then push it on the queue
        2.3)if root->left!=NULL then push it on the queue
        push root to the stack
    3)loop until stack is not empty
        pop stack
*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

};

void reverseLevelByLevel(Node *root)
{
    if(root==NULL)
        return;
    stack < struct Node *> s;
    queue < struct Node *> q;
    q.push(root);
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        if(root->right)
            q.push(root->right);
        if(root->left)
            q.push(root->left);
        s.push(root);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    return 0;
}
