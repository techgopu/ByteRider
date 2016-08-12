// program to right rotate array, rotate array from right to left

#include<stdio.h>
// an utility function which rotate array by one
void rotateByOne(int arr[], int n)
{
    int i, temp;
    temp  = arr[n-1];
    for(i = n-1; i>0; i--)
        arr[i] = arr[i-1];
    arr[i] = temp;

}
// main function to rotate array
void rotateRight(int arr[], int n, int d)
{
    int i;
    for(i = 0; i<d; i++)
        rotateByOne(arr, n);
}

// utility function to print array
void printArray(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
}

// Driver program to check above functions
int main()
{
    int arr[] = {4,5,6,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr,n);
    printf("\nAfter right rotation:");
    rotateRight(arr,n,3);
    printArray(arr,n);
    return 0;

}
