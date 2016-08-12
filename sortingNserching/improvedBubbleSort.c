#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[] = {1,2,3,0,-5,-2};
    int i;
    int size = sizeof(arr)/sizeof(arr[0]);
    improvedBubbleSort(arr,size);
    printf("\n Result of improved bubble sort is:");
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/* We can improve bubble sort by using one extra flag. No more swaps indicate the completion of
sorting. If the list is already sorted, we can use this flag to skip the remaining passes.*/

void improvedBubbleSort(int arr[], int size)
{
    int pass, i, temp, swapped = 1;
    for(pass = size-1; pass>=0 && swapped; pass--)
    {
        swapped = 0;
        for(i=0; i<pass; i++)
        {
            if(arr[i]> arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }
    }
}
