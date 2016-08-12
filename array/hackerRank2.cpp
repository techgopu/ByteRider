#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct A
{
    int x;
    bool y;
};
bool acompare(A lhs, A rhs)
{
      return lhs.x < rhs.x;
}
bool bcompare(A lhs, A rhs)
{
    return lhs.y > rhs.y;
}
int main()
{
    int n,k,count=0,sum=0;
    cin>>n;
    cin>>k;
    A arr[n];
    for(int i=0; i<n; i++)
    {
            cin>>arr[i].x;
            cin>>arr[i].y;
    }

    //sort(arr,arr+n, [](arr a, arr b){ return a.x < b.x};);
    sort(arr, arr+n,acompare);
    for(int i=0; i<n; i++)
    {
       if(arr[i].y == 1)
           count++;
    }
    sort(arr, arr+n, bcompare);
    for(int i = count-k; i<n; i++)
        sum += arr[i].x;
    for(int i=0; i<count-k; k++)
        sum -= arr[i].x;
    cout<<sum;
}
