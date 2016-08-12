/*
program to find whether a given no is multiple of 3 of not;\

Algorithm: isMutlipleOf3(n)
1) Make n positive if n is negative.
2) If number is 0 then return 1
3) If number is 1 then return 0
4) Initialize: odd_count = 0, even_count = 0
5) Loop while n != 0
    a) If rightmost bit is set then increment odd count.
    b) Right-shift n by 1 bit
    c) If rightmost bit is set then increment even count.
    d) Right-shift n by 1 bit
6) return isMutlipleOf3(odd_count - even_count)
*/
#include<stdio.h>
#include<math.h>
int isMultipleOf3(int num)
{
    int evenCount=0, oddCount=0;
    if(num<0)
        num = -num;
    if(num==0)
        return 1;
    if(num==1)
        return 0;

    while(num!=0)
    {
        if(num & 1)
            oddCount++;
        num = num>>1;
        if(num & 1)
            evenCount++;
        num = num>>1;
    }
    return (abs(oddCount-evenCount));
}
int main()
{
    int num;
    scanf("%d",&num);
    printf("%d",isMultipleOf3(num));
    return 0;
}





