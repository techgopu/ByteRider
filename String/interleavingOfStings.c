// program to check the given string is interleaving of two string
#include<stdio.h>
#include<stdlib.h>

int isInterleaved(char *A, char *B, char *C)
{
    while(*C)
    {
        //match first character of C with first character of A, if matches then move A to next
        if(*C==*A)
            A++;
        //match the first character of C with first character of B, if matches then move B to next
        else if(*C==*B)
            B++;
        else
            return 0;
        C++;

    }
    // if A or B still has some characters then length of C is smaller than sum of length of A and B, so
    // return -1
    if(*A || *B)
        return 0;
    return 1;
}

int main()
{
    char str1[] = "AB";
    char str2[] = "CD";
    char str3[] = "ACBD";
    if(isInterleaved(str1,str2,str3))
        printf("%s is interleaved of %s and %s",str3, str1, str2);
    else
        printf("%s is not interleaved of %s and %s",str3, str1, str2);
    return 0;
}
