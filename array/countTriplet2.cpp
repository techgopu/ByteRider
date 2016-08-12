#include<bits/stdc++.h>
using namespace std;

// an efficient function to count number of triplet with sum smaller than a given value in O(n^2)
 int countTriplet(int arr[], int n, int sum)
 {
     // sort the input array
     sort(arr, arr+n);
     // initialize result as 0
     int ans = 0;
     // every iteration of loop counts triplet with first element as arr[i]

     for(int i=0; i<n-2; i++)
     {
         // initialize other two elements as corner elements of subarray arr[j+1... k]
         int j = i+1, k = n-1;

         // use met in the middle concept
         while(j<k)
         {
             // if sum of current triplet is more or equal move right corner to look for the smallar values

             if((arr[i] + arr[j] + arr[k]) >= sum)
                k--;
             else
             {
                 // this is important for current i and j, there can be total k-j elements
                 ans += (k-j);
                 j++;
             }
         }
     }
     return ans;
 }

int main()
{
    int arr[] = {5,1,3,4,7};
    int n = sizeof (arr) / sizeof (arr[0]);
    int sum = 12;
    cout<< countTriplet(arr,n,sum) <<endl;
    return 0;
}
