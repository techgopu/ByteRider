// program to check whether a string is the rotation of another string or not
#include<stdio.h>
#include<string.h>


//left rotation of string
void rotateLeftOnce(char *str)
{
    char ch = str[0];
    int i, n = strlen(str);
    for(i=0; i<n-1 ; i++)
        str[i] = str[i+1];
    str[i] = ch;
}

//right rotation of string
void rotateRightOnce(char *str)
{
    int len = strlen(str);
    char ch = str[len-1];
    int i;
    for(i= len-1; i>0; i--)
        str[i] = str[i-1];
    str[i] = ch;

}


void printArray(char* str)
{
    int len = strlen(str);
    char ch = str[len-1];
    int i;
    for(i=0;i<len;i++)
        printf(" %c ",str[i]);
    printf("\n");
}

void rotateLeft(char *str, int n)
{
    int i;
    for(i = 0; i< n; i++)
        rotateLeftOnce(str);
    printArray(str);

}

void rotateRight(char *str, int n)
{
    int i;
    for(i=0; i<n ; i++)
        rotateRightOnce(str);
    printArray(str);

}
/*
// Given two sting, check if one string is the rotation of other string or not.
int areRotation(char *str1, char *str2)
{
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    char *temp;
    void *ptr;

    // check if the length of the given strings are equal or not
    if(size1!=size2)
    {
        printf("\n Size of the strings are must be equal to check the rotation");
        return 0;
    }
}
*/

int main()
{
    char arr2[] = "WXYZ";
    char arr1[] = "ABCD";
    rotateLeft(arr1,2);
    rotateRight(arr2,2);
    return 0;
}
