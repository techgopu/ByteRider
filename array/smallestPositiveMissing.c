/*  Finding smallest positive number missing from an unsorted array:
    You have given an unsorted array with both positive and negative number. You have to find the smallest
    positive number missing. Expected time O(n) and auxiliary time is O(1).

    Ex: input arr[] = {2,3,7,6,8,-1,-10,15}
        output : 1
*/
// Algorithm : Following are two step algorithm
/*  1) Segregate positive numbers from others i.e., move all non positive numbers to the left side
        Segregate() will do this work.
    2) Now we ignore the negative numbers and consider only that part of array which contains positive numbers.
        We traverse the array which contains all positive numbers and to mark presence of an element x, we change
        the sign of value at index x to negative. We traverse the array again and print the first index which has
        positive number.
*/


#include<stdio.h>

// utility function to swap two integers

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* utility function that puts all non positive numbers on the left side of the arr[] and return count of
    such numbers. */

int segregate(int arr[], int n)
{
    int j=0,i;
    for(i=0; i<n; i++)
    {
        if(arr[i] <= 0)
        {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
    return j;
}

/* Find the smallest positive number in an array that contains all positive integers. */

int findMissingPositive(int arr[], int n)
{
    int i;
    /* mark arr[i] as visited by making arr[arr[i] - 1] negative. Note that 1 is subtracted because index
        started from 0 and positive numbers starts from 1.
    */
    for(i=0; i<n; i++)
    {
        if(abs( arr[i]-1 ) < n && arr[ abs(arr[i]) - 1] > 0)
            arr[ abs(arr[i]) -1 ] = - arr[ abs(arr[i]) -1];
    }

    //return the first index at which arr[] has positive value.
    for(i=0; i<n; i++)
    {
        if(arr[i]>0)
            return i+1; // 1 is added because index started from 0.
    }
    return n+1;
}

// Finding smallest positive number in an array thats contains both positive and negative numbers.

int findMissing(int arr[], int n)
{
    // First segregate the positive and negative numbers.
    int shift = segregate(arr, n);
    // Shift the array and findMissingPositive for positive part.
    return(findMissingPositive(arr+shift, n-shift));
}

// Driver function to check above functions
int main()
{
    int arr[]={23,4,5,-4,-5,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("\n Missing Smallest positive integer is: %d", findMissing(arr, size));
    return 0;
}















