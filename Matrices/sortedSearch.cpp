// Given a square, in which rows and columns are sorted in non decreasing order, and a number. Find the index of the
// number in the square

#include<bits/stdc++.h>
#define R 4
#define C 4
using namespace std;

int sortedSquareSearch(int mat[R][C], int x)
{
    int i=0;
    int j=C-1;

    while(j<C && i <R)
    {
            if(mat[i][j]==x)
            {
                cout<<mat[i][j];
                return 1;
            }

            else if(mat[i][j]>x)
                j--;
            else
                i++;
    }
    return 0;

}

int main()
{
    int mat[R][C] = {
                        {10,11,12,13},
                        {20,21,22,23},
                        {30,31,32,33},
                        {40,41,42,43}
                    };
    int i = sortedSquareSearch(mat,49);
    if(i==0)
        cout<<"Not Found"<<endl;
    return 0;
}






