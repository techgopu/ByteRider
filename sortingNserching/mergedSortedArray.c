#include<stdio.h>
#include<stdlib.h>
int *mergeSortedArray(int[], int[], int, int);


int main()
{
    int arr1[] = {-1,1,3,5,8};
    int arr2[] = {0,2,4,6,7,9};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    int *p = mergeSortedArray(arr1,arr2,n1,n2);
    int i;
    for(i=0;i<n1+n2;i++)
        printf("%d ",p[i]);

    return 0;

}

int *mergeSortedArray(int arr1[], int arr2[], int n1, int n2)
{
    int *result = (int*)malloc(sizeof(int)*(n1+n2));
    int i, j, k;
    j=0,k=0;
    for(i=0;i<n1+n2;)
    {
        if(j<n1 && k<n2)
        {
            if(arr1[j]<arr2[k])
            {
                result[i] = arr1[j];
                j++;
            }
            else
            {
                result[i] = arr2[k];
                k++;
            }
            i++;
        }
        else if(j == n1)
        {
            while(k < n2)
            {
                result[i] = arr2[k];
                k++;
                i++;
            }
        }
        else
        {
            while(j<n1)
            {
                result[i] = arr1[j];
                j++;
                i++;
            }
        }
    }
    return result;
}
