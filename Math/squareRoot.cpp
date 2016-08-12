/*program to find out square of a given number:
1 Start with an arbitrary positive start value x (the closer to the
   root, the better).
2 Initialize y = 1.
3 Do following until desired approximation is achieved.
  a) Get the next approximation for root using average of x and y
  b) Set y = n/x
*/
#include<iostream>
using namespace std;

float sqareRoot(float num)
{
    float x = num;
    float y = 1;
    float e = 0.000001;
    while(x-y>e)
    {
        x = (x+y)/2;
        y = num/x;
    }
    return x;
}

int main()
{
    int num;
    cin>>num;
    cout<<"square root of "<<num<<" is"<<sqareRoot(num);
    return 0;
}
