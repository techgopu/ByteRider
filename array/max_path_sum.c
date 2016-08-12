#include<stdio.h>

int max(int x, int y)
{
    return x>y ? x : y;
}

int maxPathSum(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    int result = 0, sum1 = 0, sum2 = 0;
    while(i<m & j<n)
    {
        // add elements of arr1 to sum1
        if(arr1[i] < arr2[j])
            sum1 = arr1[i++] + sum1;
        // add elements of arr2 to sum2
        else if(arr1[i] > arr2[j])
            sum2 = arr2[j++] + sum2;
        // else we reached at common point
        else
        {
            result += max(sum1, sum2);
            sum1 = 0, sum2 = 0;
            while(i < m && j < n && arr1[i] == arr2[j])
            {
                result += arr1[i++];
                j++;
            }

        }
    }
    while(i<m)
        sum1 += arr1[i++];
    while(j<n)
        sum2 += arr2[j++];
    result+= max(sum1, sum2);
    return result;
}


int main()
{
    int arr1[] = {1,2,4,64,73,504,3334};
    int arr2[] = {22,34,73,6500};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    printf("\n Max path sum is: %d",maxPathSum(arr1,arr2,m,n));
    return 0;
}
