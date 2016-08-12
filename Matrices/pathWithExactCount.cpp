/*
    Number of paths with exactly k coins:
    Given a matrix where every cell has some no of coins. Find no of ways to reach from top left to bottom right
    with exactly k coins.
    We can move to (i+1,j) and (i,j+1) from a cell (i,j)
*/

#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
#define MAX_K 100

int dp[R][C][MAX_K];

/*

//*********** Recursive solution *******************************
int countPathsRec(int mat[][C], int m, int n, int k)
{
    //base condition
    if(m<0 || n<0)
        return 0;
    if(m==0 && n==0)
        return(mat[m][n]==k);
    return countPathsRec(mat, m-1,n, k-mat[m][n]) + countPathsRec(mat, m, n-1, k-mat[m][n]);
}

int countPaths(int mat[][C],int k)
{
    return countPathsRec(mat, R-1, C-1, k);
}
*/


//************************DP Solution ***********************************
// here we use a lookup table of three dimension dp[m][n][k] where m is the no of row, n is the no of columns
// and k is the value of coins
int countPathRecDp(int mat[][C], int m, int n, int k)
{
    //base condition
    if(m<0 || n<0)
        return 0;
    if(m==0 && n==0)
        return(k==mat[m][n]);
    // if this subproblem is already solved
    if(dp[m][n][k] != -1)
        return dp[m][n][k];

    dp[m][n][k] = countPathRecDp(mat, m-1,n, k-mat[m][n]) + countPathRecDp(mat, m, n-1, k-mat[m][n]);
    return dp[m][n][k];
}
int countPathsDp(int mat[][C], int k)
{
    // use a lookup matrix and initially initialize all of its members as -1
    memset(dp,-1,sizeof(dp));
    return countPathRecDp(mat,R-1,C-1,k);

}



int main()
{
    int mat[][C] =  {
                    {1,2,3},
                    {4,6,5},
                    {3,2,1}
                    };
    int k = 12;

//    cout<<countPaths(mat,k)<<endl;
    cout<<countPathsDp(mat,k)<<endl;
    return 0;
}
