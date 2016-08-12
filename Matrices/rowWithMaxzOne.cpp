// Given a boolean matrix, each row contains 0's followed by 1's. Find the row with maximum no of 1s.

#include<bits/stdc++.h>
#define R 4
#define C 4

using namespace std;


// Function to fine the index of first one in the boolean array. since rows are sorted we can use binary search
// to find the first 1 in the row.

int findFirstOne(bool arr[], int low, int high)
{
    int mid;
    if(low <= high)
    {
        mid = low + (high-low)/2;

        if((mid==0 || arr[mid-1]==0) && arr[mid]==1)
            return mid;
        else if(arr[mid]==0)
             return findFirstOne(arr,mid+1,high);
        else
            return findFirstOne(arr,low,mid-1);
    }
    return -1;
}

// main function to find max 1s in a row
int rowWithMaxOne(bool mat[R][C])
{
    int maxRowIndex = 0;
    int max = -1;
    int index;

    for(int i = 0; i<R; i++)
    {
        index = findFirstOne(mat[i],0,C-1);
        if(index!=-1 && (C-index)>max)
        {
            max = C-index;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}


int main()
{
    bool mat[R][C]= {
                        {0,0,0,1},
                        {0,0,0,0},
                        {0,1,1,1},
                        {1,1,1,1}
                    };
    cout<<"The row containing max 1s is:"<<rowWithMaxOne(mat);
    return 0;
}

