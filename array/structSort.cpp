#include<iostream>
#include<bits/stdc++.h>
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
    int n;
    cin>>n;
    A arr[n];
    for(int i=0; i<n; i++)
    {
            if(i<4)
            {
                arr[i].x=n-i+10;
            }
            else
                arr[i].x = i+3;
            if(i>3)
            {
                arr[i].y=0;
            }
            else
                arr[i].y = 1;

    }

    //sort(arr,arr+n, [](arr a, arr b){ return a.x < b.x};);
    sort(arr, arr+n,acompare);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].x<<" "<<arr[i].y<<endl;
    }
    cout<<endl<<endl;
    sort(arr, arr+n,bcompare);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].x<<" "<<arr[i].y<<endl;
    }
}
/*std::sort(array, array+1000, [](A a, A b){ return a.x < b.x; });
std::sort(array, array+1000, [](A a, A b){ return a.y < b.y; });
*/
