/*
Application of Union:
In a binary search tree, suppose every internal nodes have only pointers to his their left and right nodes and
all the leaf nodes contains data only. In such a case, we can use union in the following way:
*/
#include<stdio.h>

struct Node
{
    int isLeaf;
    union
    {
        struct
        {
            struct Node *left;
            struct Node *right;
        }internal;
        double data;
    }info;
};
int main()
{
        struct Node in;
        in.info.internal.left=NULL;
        in.info.internal.right=NULL;
        struct Node leaf;
        leaf.info.data = 4.555;

        printf("%p",in.info.internal.left);
        printf("%p",in.info.internal.right);
        printf("%f",leaf.info.data);
        return 0;

}





