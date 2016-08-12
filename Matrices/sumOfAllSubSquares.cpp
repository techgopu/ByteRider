// Given a n*n square matrix. Find out the sun of all sub square matrices of order k*k.


#include<bits/stdc++.h>
#define N 5

using namespace std;
// simple approach with time 0(n*n K*K)
void sumOfSquares(int mat[][N], int k)
{
    if(k>N)
        return;
    for(int i=0; i < N-k+1; i++)
    {
        for(int j =0; j< N-k+1; j++)
        {
            int sum=0;
            for(int n = i; n<k+i ;n++)
                for(int m = j; m<k+j; m++)
                     sum += mat[n][m];
                cout<<sum<<" ";
        }
        cout<<endl;

    }
}





int main()
{
    int mat[][N]=   {
                        {1,1,1,1,1},
                        {2,2,2,2,2},
                        {3,3,3,3,3},
                        {4,4,4,4,4},
                        {5,5,5,5,5}
                    };
    sumOfSquares(mat,3);
    return 0;
}
