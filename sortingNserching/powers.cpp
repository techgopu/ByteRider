#include<bits/stdc++.h>
using namespace std;
int power(int x, unsigned int y)
{
    int res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;

        // n must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}

int maxSum(int x)
{
    int c1=0;
    int i =0;
    int rem;
    while(x>0)
    {
       rem = x%10;
       if(rem == 5)
        c1 = c1 + power(10,i);
       i++;
       x = x/10;
    }
    return c1;
}

int minSum(int x)
{
    int c1=0;
    int i =0;
    int rem;
    while(x>0)
    {
       rem = x%10;
       if(rem == 6)
        c1 = c1 + power(10,i);
       i++;
       x = x/10;
    }
    return c1;
}

int main()
{
    int x, y,max1,max2,min1,min2;

    cin>>x>>y;
    max1 = maxSum(x);
    max2 = maxSum(y);
    min1 = minSum(x);
    min2 = minSum(y);
    cout<<max1+max2+x+y;
    cout<<" "<<x+y -min1-min2;
    return 0;
}
