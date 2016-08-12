#include<bits/stdc++.h>
using namespace std;

// Function to count all elements present in array[0.... n-1] the array elements must be in the range 1 to n

void printFrequencies(int arr[], int n)
{
    // subtract 1 from each element so that the range becomes 0 to n-1
    for(int i = 0; i<n; i++)
        arr[i] = arr[i]-1;

    /* Use every element arr[i] as index and add n to elements present at arr[i]%n to keep track of
        count of occurrence of arr[i]
    */

    for(int i=0; i<n; i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;

    /* to prints count simply print the number of times n elements was added at index
        corresponding to every element.
    */

    for(int i=0; i<n; i++)
        cout<< i+1 <<"->" << arr[i]/n <<endl;

}

int main()
{
    int arr[] = {2,1,3,1,2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printFrequencies(arr,n);
    return 0;
}

