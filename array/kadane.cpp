/*
    Kadane's Algorithm is used to find longest sum continuous sub array.

    Initialize max_so_far = 0;
    max_ending_here = 0;
    loop for each element of the array
        a> max_ending_here = max_ending_here+arr[i]
        b> if max_ending_here < 0
            max_ending_here = 0
        c> if max_so_far < max_ending_here
            max_so_far = max_ending_here
    return max_so_far
*/
#include<iostream>
using namespace std;
int kadane(int arr[],int n)
{
        int maxEndingHere = 0;
        int maxSoFar = 0;
        for(int i=0; i<n; i++)
        {
            maxEndingHere += arr[i];
            if(maxEndingHere <0 )
                maxEndingHere=0;
            else if(maxSoFar<maxEndingHere) // we can also check if(maxSoFar<maxEndingHere)but in order to make
                maxSoFar=maxEndingHere;     // it more optimized we checked else if(maxSoFar<maxEndingHere) 							//i.e.,
        }                                   // compare only when maxEndingHere is greater than 0
        return maxSoFar;
}

int main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<kadane(arr,n);
    return 0;
}