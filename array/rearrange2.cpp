
/*
    program to rearrange the array. Array contains both positive and negative numbers. Rearrange the array so that
    it contains alternate positive and negative numbers. If more positive or negative numbers are there then
    it will come at the end of the array.
*/
#include<iostream>
using namespace std;
void swapValues(int *, int *);
int rearrange(int arr[], int n)
{
    //rearrange the negative and positive values, negative values come first and the positive values
    int i=-1;
    for(int j=0; j<n; j++)
    {
        if(arr[j]<0)
        {
            i++;
            swapValues(&arr[i],&arr[j]);
        }
    }

    // i+1 hold the first positive value and all the negative values come to the left side of array, the
    // first negative value will be at 0th index.

    int pos = i+1;
    int neg = 0;

    while(neg<pos && pos<n && arr[neg]<0)
    {
        swapValues(&arr[pos], &arr[neg]);
        // increment neg by 2 and pos by 1
        pos = pos+1;
        neg = neg+2;
    }

}

void swapValues(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {-1,3,4,-5,-4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr,n);
    printArray(arr,n);
    return 0;
}
