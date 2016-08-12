#include<bits/stdc++.h>
#define R 4
#define C 3
using namespace std;

void boolModifiedMat(bool mat[][C])
{
    bool row[R];
    bool col[C];
    int i, j;
    for(i=0; i<R; i++)
    {
        row[i]=0;
    }
    for(i=0; i<C; i++)
    {
        col[i]=0;
    }

    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(mat[i][j]==1)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            if(row[i]==1 || col[j]==1)
                mat[i][j]=1;
        }
    }
    for(i=0;i<R;i++)
    {
        for(j=0; j<C; j++)
        {
            cout<<mat[i][j]<< " ";
        }
        cout<<endl;
    }
}
//optimized space
void boolModified(bool mat[][C])
{
    int rowFlag=0,colFlag=0;
    int i,j;

    for(i=0;i<C;i++)
    {
        if(mat[0][i]==1)
            rowFlag=1;
    }
    for(i=0;i<R;i++)
    {
        if(mat[i][0]==1)
            colFlag=1;
    }

    for(i=1; i<R; i++)
    {
        for(j=1; j<C; j++)
        {
            if(mat[0][j] ==1 || mat[i][0]==1)
                mat[i][j]=1;
        }
    }
    if(rowFlag==1)
    {
        for(i=0; i<C; i++)
            mat[0][i] = 1;
    }
    if(colFlag==1)
    {
        for(i=0; i<R; i++)
            mat[i][0] = 1;
    }

    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            cout<<mat[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    bool mat[][C] = {   {1,0,0},
                        {0,0,0},
                        {0,1,0},
                        {0,0,0}
                                    };
    //boolModifiedMat(mat);
    boolModified(mat);
    return 0;
}
