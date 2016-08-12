#include<stdio.h>
// Function for tabulated version of fibonacci
int fib(int n)
{
    int f[n+1];
    int i;
    f[0] = 1; f[1] = 1;
    for(i=2; i<=n; i++)
        f[i] = fib(n-1) + fib(n-2);
    return f[n];
}

int main()
{
    int n = 9;
    printf("Fibonacci Number is:%d",fib(n));
    return 0;
}
