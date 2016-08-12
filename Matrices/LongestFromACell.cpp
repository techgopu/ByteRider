/*
    Find longest form a matrix with the given constraints:
        Given a n*n matrix where all elements are distinct and distributed in the range of 1 to n*n.
        Find the maximum length (starting from any cell) such that all the cells along the path are in
        increasing order with a difference of 1.

        We can move in any of one of the four direction from a given cell(i,j)
            (i+1,j) or (i-1, j) or (i,j+1) or (i,j-1) with the condition that adjacent.
*/

// A Dynamic problem solution

#include<bits/stdc++.h>
using namespace std;
#define n 3

int findLonFromACell(int i, int j, int mat[n][n], int dp[n][n])
{
    //base case
    if(i<0 || j<0 || j>=n || i>= n)
        return 0;
    //if this subproblem is already solved
    if(dp[i][j]!= -1)
        return dp[i][j];
    // since numbers are distinct and in range 1 to n*n, there is at most one possible direction from any cell
    if(j<n-1 && ((mat[i][j]+1) == mat[i][j+1]))
        return dp[i][j] = findLonFromACell(i,j+1,mat,dp);
    if(j>0 && ((mat[i][j] +1) == mat[i][j-1]))
        return dp[i][j] = findLonFromACell(i,j-1,mat,dp);
    if(i<n-1 && ((mat[i][j] + 1) == mat[i+1][j]))
        return dp[i][j] = findLonFromACell(i+1,j,mat,dp);
    if(i>0 && ((mat[i][j]+1) == mat[i-1][j]))
        return dp[i][j] = findLonFromACell(i-1,j,mat,dp);

    // if none of the adjacent 4 is 1 greater then
    return dp[i][j] = 1;

}

// Returns the longest length path beginning with any cell
int longestOverAll(int mat[n][n])
{
    int result =1;
    // create a lookup table and initialize all of it members as -1
    int dp[n][n];
    memset(dp,-1,sizeof(dp));

    //compute the longest path beginning from any cell
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            //if the current cell is not computed yet
            if(dp[i][j] == -1)
                findLonFromACell(i,j,mat,dp);
            //update the result
            result = max(result,dp[i][j]);
        }
    }

   return result;
}
int main()
{
    int mat[n][n] ={{1, 2, 9},
                    {5, 3, 8},
                    {4, 6, 7}};
    cout<<longestOverAll(mat)<<endl;
    return 0;
}



