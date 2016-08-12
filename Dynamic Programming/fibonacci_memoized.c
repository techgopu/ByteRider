#include<stdio.h>
#define NIL -1
#define MAX 100

int lookup[MAX];


// Function to initialize NIL values in the lookup table
void _initialize()
{
    int i;
    for(i=0; i<MAX; i++)
        lookup[i] = NIL;
}

// Function for nth fibonacci number
int fib(int n)
{
    if(lookup[n] == NIL)
    {
        if(n <= 1)
            lookup[n] = n;
        else
            lookup[n] = fib(n-1) + fib(n-2);
    }
    return lookup[n];
}

int main()
{
    int i;
    int n = 40;
    _initialize();
    printf("%d\n",fib(n));
    for(i=0; i<n; i++)
        printf("%d ",lookup[i]);
    return 0;
}
