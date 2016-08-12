
// Program to generate fibonacci searies
#include<iostream>
using namespace std;
int *fibo(int n)
{
    int *f = new int[n+1];
    f[0] = 0;
    f[1] = 1;
    for(int i=2;i<n;i++)
        f[i] = f[i-2] + f[i-1];
    return f;
}
int main()
{
    int n;
    cin>>n;
    int *ptr = fibo(n);
    for(int i=0; i<n; i++)
        cout<<ptr[i]<<" ";
    delete ptr;
    return 0;
}
