/*
    Given an array of three integers. Find three elements such that A[i] < A[j] < A[k] and i<j<k i.e.,
    find sorted sequence of three in linear time.
*/
#include<bits/stdc++.h>

void find3Numbers(int arr[], int n)
{
    int max = n-1;
    int min = 0;
    int i;
    /* create an array that store index of a smaller element on left side. if there is no smaller element on
        left side then smaller[i] will be -1.
    */
    int *smaller = new int[n];
    smaller[0] = -1; // first entry will always be negative
    for(i=1; i<n; i++)
    {
        if(arr[i]<=arr[min])
        {
            min = i;
            smaller[i] = -1;
        }
        else
            smaller[i] = min;
    }

    /*  create another array greater[0...n-1] that store index of greater element on right side. if there is no
        such element on right side then greater[i] will be -1.
    */
    int *greater = new int[n];
    greater[n-1] = -1;
    for(i=n-2; i>=0; i--)
    {
        if(arr[i] >= arr[max])
        {
            max = i;
            greater[i] = -1;
        }
        else
            greater[i] = max;
    }

    /* Now find a number which has both greater number in right side and smaller number in left side */

    for(i=0; i< n; i++)
    {
        if(smaller[i]!=-1 && greater[i]!=-1)
            printf("%d %d %d", arr[smaller[i]],arr[i],arr[greater[i]);
        else
            printf("\n No such numbers exits!!");
    }
    delete[] greater; delete[] smaller;

}


int main()
{
    int arr[] = {11,12,10,5,6,2,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    find3Numbers(arr,n);
    return 0;
}
