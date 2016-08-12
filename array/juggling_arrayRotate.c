#include<stdio.h>

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

void leftRotate(int arr[], int d, int n)
{
    int i,j,k,temp;
    for(i=0;i<gcd(d,n);i++)
    {
        temp = arr[i];
        j = i;
        while(1)
        {
            k = j+d;
            if(k>=n)
                k = k-n;
            if(k==i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;

    }
}

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nOriginal Array:");
    printArray(arr, n);
    leftRotate(arr,3,n);
    printf("\nAfter Rotation:");
    printArray(arr,n);
    return 0;
}
