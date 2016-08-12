/*
    Given an array of n elements which contains elements from 0 to n-1 with any of these elements repeating any
    no of times. Find these repeating elements. Expected time complexity is O(n) and auxiliary space is O(1).
*/

#include<stdlib.h>
#include<stdio.h>

void printRepeating(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[abs(arr[i])] >=0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            printf("%d", abs(arr[i]));

    }
}

int main()
{
    int arr[] = {1,1,2,4,5,6,4,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    printRepeating(arr,size);
    return 0;
}


