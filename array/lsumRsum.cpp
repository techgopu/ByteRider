#include<iostream>
using namespace std;

bool checkLsumRsum(int arr[], int n)
{
    int rSum=0,lSum=0;
    bool flag = false;
    for(int i=0; i<n; i++)
        rSum += arr[i];
    for(int i=1; i<n; i++)
    {
        lSum +=arr[i-1];
        if(lSum == rSum-lSum-arr[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {4,2,3,7,3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(checkLsumRsum(arr,n))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;

}
