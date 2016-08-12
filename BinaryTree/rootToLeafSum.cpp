/* Program to find whether a given number is the sum of root to leaf in binary tree.
int rootToLeafSum(Node *root, int sum, vector<int> result)
{
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data==sum)
        {
            result.push_back(root->data);
            return true;
        }
        else
            return false;
    }
    if(rootToLeafSum(root->left,sum-root->data,result)
    {
        result.push_back(root->data);
        return true;
    }
    if(rootToLeftSum(root->right,sum-root->data,result)
    {
        result.push_back(root->data);
        return true;
    }
    return false;

}

*/


