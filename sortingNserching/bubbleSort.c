#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[] = {3,4,1,0,-4,-5,67,8,90,2};
    int i;
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,size);

    for(i=0;i<size;i++)
        printf("%d ",arr[i]);

    return 0;

}
/* bubble sort work by iterating the input array from the first element to last element. Compare each
pair of elements and swap them if needed. It takes O(n^2) even in best case.*/

void bubbleSort(int arr[], int size)
{
    int pass,j, temp;

    for(pass = size-1; pass>=0 ; pass--)
    {
        for(j=0; j < pass; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
