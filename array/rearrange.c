// program to rearrange the array in alternating positive negative and positive items in O(1) extra space
/* input: arr[] = {1,2,3,-4,-2,4}
    output: arr[] = {-4,1,-2,2,3,4}

    The idea is to process the array from left to right. While processing, find out the first out-of-place
    element in the remaining unprocessed array. An element is out-of-place if it is negative and at odd
    index of it is positive and at even index. Once we find out-of-place we find the first element after
    it with positive sign. We right rotate the array between these two elements(including these two).
*/


#include<stdio.h>
#include<stdlib.h>
void rightRotate(int arr[], int n, int outofplace, int curr)
{
    int temp = arr[curr];
    int i;
    for(i=curr; i > outofplace; i--)
        arr[i] = arr[i-1];
    arr[outofplace] = temp;
}

void rearrange(int arr[], int n)
{
    int outofplace = -1;
    int index;

    for(index = 0; index < n; index++)
    {
        if(outofplace >= 0)
        {
            /* find the item which must be moved into outofplace entry if outofplace entry is
                positive and current entry is negative or outofplace entry is positive and
                current entry is positive.
            */

            if((arr[index] >= 0 && (arr[outofplace]<0)) || ((arr[index]<0) && (arr[outofplace] >=0)))
            {
                rightRotate(arr,n,outofplace,index);
                // the next outofplace entry is now 2 steps ahead
                if(index - outofplace > 2)
                    outofplace = outofplace+2;
                else
                    outofplace = -1;
            }
        }
        if(outofplace == -1)
        {
            // check if current entry is out of place
            if(((arr[index] >= 0) && (!(index & 0x01))) || ((arr[index]<0)&&(index & 0x01)))
                outofplace = index;
        }
    }
}

printArray(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
}


int main()
{
    int arr[] =  {1,2,3,-4,-2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    printf("\nAfter rearrange\n");
    rearrange(arr,n);
    printArray(arr,n);
    return 0;
}
