#include<stdio.h>
int main()
{
    int arr[] = {1,-2,0,5,-5};
    int i;
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,size);
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);

    return 0;


}
/*  1. Find the minimum value in the list
    2. Swap it with the value in current position.
    3. Repeat this process for all the elements until the entries is sorted.
*/

void selectionSort(int arr[], int size)
{
        int i, j, temp,min;
        for(i=0;i<size-1;i++)
        {
            min = i;
            for(j = i+1;j<size; j++)
            {
                if(arr[j] < arr[min])
                    min = j;
            }
            // swap
            temp = arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
}
