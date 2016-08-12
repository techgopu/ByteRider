/*
Program to level by level traversal using two queues.
*/
void levelByLevelTraversal(Node *root)
{
    if(root==NULL)
        return;
    queue<struct Node*> q1;
    queue<struct Node*> q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty())
    {
        while(!q1.empty())
        {
            root = q1.top();
            q1.pop();
            cout<<root->data;
            if(root->left!=NULL)
                q2.push(root->left);
            if(root->right!=NULL)
                q2.push(root->right);
        }
        cout<<end;
        while(!q2.empty())
        {
            root = q2.top();
            q2.pop();
            cout<<root->data;
            if(!root->left)
                q1.push(root->left);
            if(!root->right)
                q1.push(root->right);
        }
        cout<<endl;
    }

}

