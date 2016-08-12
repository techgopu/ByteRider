#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[] = {2,1,0,-4,5,4,-5};
    int i;
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size);
    for(i = 0;i<size; i++)
        printf("%d ",arr[i]);
    return 0;

}

/* Every repetition of insertion sort removes an element from the input data, insert it into
the correct position in the already sorted list until no input elements remain. sorting is typically
done in-place. The resulting array after k iterations has the property where the first k+1
entries are sorted. Time Complexity : O(n*n)*/

void insertionSort(int arr[], int size)
{
    int i,j,v;
    for(i = 1; i <= size-1; i++)
    {
        v = arr[i];
        j=i;
        while(arr[j-1] > v && j>=1)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
    }
}
