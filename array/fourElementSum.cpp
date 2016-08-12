/*
    program to find four elements that sum to a given value
    arr[] = {10,2,3,4,5,9,7,8} and x = 23 then out function should print 3 5 7 8
*/

#include<iostream>
using namespace std;

// A naive solution O(n^4)
void findFourElement(int arr[], int n, int x)
{
    for(int i=0; i<n-3; i++)
    {
        for(int j = i+1; j<n-2; j++)
        {
            for(int k = j+1; k<n-1; k++)
            {
                for(int l = k+1; l<n; l++)
                {
                    if(arr[i]+arr[j]+arr[k]+arr[l]==x)
                    {
                        cout<<arr[i]<<arr[j]<<arr[k]<<arr[l];
                        cout<<endl;
                    }
                }
            }
        }
    }
}



int main()
{
    int arr[]={10,2,3,4,5,9,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 23;
    findFourElement(arr,n,x);
    return 0;
}
