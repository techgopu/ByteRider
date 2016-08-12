/*
    program to find maximum continuous circular sum.
    We need to handle two cases:
    case#1
        The element that contribute to the maximum sum are arranged such that no wrapping is there.
        Example: {-10,2,-1,5}, {-2,4,-1,4,-1}. In this case kadane's algo will produce the result
    case#2
        The element that contribute to the maximum sum are arranged such that wrapping is there.
        Example: {12,-5,4,-8,11}, {10,-12,11}. In this case we change wrapping to non wrapping.
        Let's see how wrapping of contributing elements implies non wrapping of non contributing elements.

        ->So find out the sum of non contributing elements and subtract this from total sum.

        To find out the sum of non contributing elements invert the sign of each elements and then run kadane's algo.
        Our array is like a ring and we have to eliminate maximum continuous negative that implies maximum
        continuous positive in the inverted array.

        Finally compare the sum obtained by both the cases and return the maximum of two sum.
*/

#include<iostream>
using namespace std;

// standard Kadane's

int stdKadane(int arr[], int n)
{
    int maxSoFar=0, maxEndingHere=0;
    for(int i=0; i<n; i++)
    {
        maxEndingHere += arr[i]; // arr[] = {10,-12,11}  Output: 21, arr[]={12,-5,4,-8,11} Output://
        if(maxEndingHere<0)      //                                  stdKadane=14, arrsum = 14, -14
            maxEndingHere=0;
        else if(maxSoFar<maxEndingHere)
            maxSoFar=maxEndingHere;
    }
    return maxSoFar;
}

// find maximum continuous circular sum
int maxCircularSum(int arr[],int n)
{
    //case#1 get maximum sum using standard Kadane's
    int maxKadane = stdKadane(arr, n);
    //case#2 now find sum that include corner elements
    int maxWrap = 0;
    for(int i=0; i<n; i++)
    {
        maxWrap += arr[i];//calculate array sum
        arr[i] -= -1;
    }
    maxWrap = maxWrap + stdKadane(arr,n);
    return (maxWrap>maxKadane? maxWrap:maxKadane);
}

int main()
{
    int arr[] = {12,-5,4,-8,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxCircularSum(arr,n);
    return 0;
}
