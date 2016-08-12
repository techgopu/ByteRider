//program to find whether a given number is lucky number or not
#include<stdio.h>
/*
process of finding a lucky number:
    suppose we have a sequence of integers 1,2,3,4,5,6,7,8,9......
    we delete every second number the sequence becomes 1,3,5,7,9,11,13,15,17,19,21........
    again we delete every third number, the sequence becomes 1,3,7,9,13,15,19,21...
    again we delete every fourth number, the sequence becomes 1,3,7,13,15,19.......
    this process goes infinitely and all the remaining numbers which are not deleted known as lucky numbers.

*/
// Recursive solution
int isLucky(int n)
{
    static int count = 2;       // because we delete numbers starting from second positions
    int next_position = n;
    if(count>n)
        return 1;
    if(n%count==0)
        return 0;
    next_position -= next_position/count;
    count++;
    return isLucky(next_position);
}

int main()
{
    int num = 19;
    if(isLucky(num))
        printf("%d is lucky number",num);
    else
        printf("%d is not lucky number",num);
    return 0;
}
