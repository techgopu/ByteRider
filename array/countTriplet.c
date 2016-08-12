// count triplet with sum smaller than given value
/* input: arr[] = {-2,0,1,3}
    sum = 2
    output: 2
    explanation :({-2,0,1}, {-2,0,3})
*/

#include<stdio.h>
#include<stdlib.h>

// time complexity of this function would be O(n^3)
int countTriplet(int arr[], int n, int sum)
{
    int ans = 0,i,j,k;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1; j< n-1; j++)
        {
            for(k=j+1; k<n; k++)
                if(arr[i] + arr[j] + arr[k] < sum)
                    ans++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {5,1,3,4,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 12;
    printf("\ncount of the triplets with sum less than %d is: %d",sum,countTriplet(arr,size,sum));
    return 0;
}
