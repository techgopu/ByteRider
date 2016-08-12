// program to find max min difference such that index of min is less than index of max

#include<iostream>
using namespace std;
int maxMinDiff(int arr[],int n)
{
    int minIndex=0,maxIndex=0,maxx=arr[0],minn=arr[0],res=INT_MIN,diff;
    for(int i=1;i<n; i++)
    {
        if(minn>arr[i])
        {
            minn = arr[i];
            minIndex = i;
        }
        if(maxx<arr[i])
        {
            maxx = arr[i];
            maxIndex = i;
        }
        if(maxIndex>minIndex)
        {
            diff=maxx - minn;
            if(res<diff)
                res=diff;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1,2,0,3,10,-12,6,8,9,4,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxMinDiff(arr,n);
    return 0;
}
