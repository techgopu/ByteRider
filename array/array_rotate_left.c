#include<stdio.h>


void rotateByOne(int arr[], int n)
{
    int i, temp;
    temp = arr[0];
    for(i=0;i < n-1; i++)
        arr[i] = arr[i+1];
    arr[i] = temp;
}

void leftRotate(int arr[],int n, int d)
{
    int i;
    for(i=0; i<d ;i++)
        rotateByOne(arr,n);
}
void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
int main()
{
    int arr[] = {4,5,6,1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    leftRotate(arr, size, 3);
    printf("\nAfter left rotation:");

    printArray(arr,size);
    return 0;
}
