// program that returns true if there is a pythagorean triplet in a given array
#include<iostream>
#include<algorithm>
using namespace std;
bool isTriplet(int arr[], int n)
{
    // square array elements
    for(int i=0; i<n; i++)
        arr[i] = arr[i] * arr[i];
    sort(arr, arr+n);
    // now fix one element one bye one and find the other two elements
    for(int i=n-1; i>=2; i--)
    {
        int l = 0;
        int r = i-1;
        while(l<r)
        {
            // a triplet found
            if(arr[l] + arr[r] == arr[i])
                return true;
            //else either move l or r
            (arr[l]+ arr[r] < arr[i])? l++ : r--;
        }
    }
    // if reached here no triplet found
    return false;
}
int main()
{
    int arr[] = {2,3,4,6,7};
    int n = sizeof(arr)/ sizeof(arr[0]);
    (isTriplet(arr, n))? cout<< "Yes" : cout<< "No";
    return 0;
}
