/*
    Find the maximum value of sum(i* arr[i]) with only rotation on given array allowed.
    Ex.
    arr[] = {1,20,2,10};
    output 72
    we can obtained 72 by rotating array twice.
    {2,10,1,20}
    2*0+10*1+1*2+3*20 = 72

    the idea is to obtain next rotation value from the previous rotation using a formula given below
    R(j) - R(j-1) = arrSum - n* arr[n-J]
*/

#include<stdio.h>
int maxSumRotation(int arr[], int n)
{
    // Find array sum and i*arr[i] with no rotation
    int arrSum = 0, currVal = 0,maxValue;
    int i,j;
    for(i=0;i<n;i++)
    {
        arrSum = arrSum+arr[i];
        currVal = currVal + (i*arr[i]);
    }
    // initialize result as 0 rotation sum
    maxValue = currVal;
    // try all rotation one by one and find maximum rotation sum
    for(j=1;j<n;j++)
    {
        currVal = currVal + arrSum - (n*arr[n-j]);
        if(currVal>maxValue)
            maxValue = currVal;
    }
    return maxValue;
}

int main()
{
    int arr[] = {1,20,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\n The Maximum sum with rotation is:%d",maxSumRotation(arr,n));
    return 0;
}

