/*  Given an array of integer and a number x, find the smallest subarray with sum greater
    than the given x.

    For example,
    Input: arr[] = {1,4,45,6,0,19}, x = 51
    output : 3 minimum length subarray is {4,45,6}
*/
#include<stdio.h>
int smallestSubWithSum(int arr[], int n, int x)
{
    int curr_sum = 0, min_len = n+1;
    int start = 0, end = 0;

    while(end<n)
    {
        while(curr_sum <= x && end < n)
            curr_sum += arr[end++];
            while(curr_sum > x && start < end)
            {
                // update min_len if needed
                if(end - start < min_len)
                    min_len = end - start;
                // remove starting element
                 curr_sum -= arr[start++];
            }
    }
    return min_len;
}

int main()
{
    int arr[] = {1,4,5,45,6,0,19};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printf("\n Minimum length :%d", smallestSubWithSum(arr,n,51));
    return 0;
}
