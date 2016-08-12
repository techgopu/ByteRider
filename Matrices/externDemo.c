#include<stdio.h>
int main()
{
    extern int x;
    int y;
    printf("size of int y is %d and size of extern int x is %d", sizeof(x), sizeof(y));
    printf("value of extern int x is :%d and value of int y is %d", x, y);
    return 0;
}
