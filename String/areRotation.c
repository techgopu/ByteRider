// program to check if the two strings are rotation of each other or not

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
    // create a temporary array with length equal to size1+size2

    temp = (char *) malloc(sizeof(char)*(size1*2 +1));
    temp[0] = '\0';
    strcat(temp,str1);
    strcat(temp,str2);

    // Now check str2 is the subarray of temp array or not

    ptr = strstr(temp,str2);
    free(temp);
    if(ptr!=NULL)
        return 1;
    return 0;
}

// Driver function to check above functions
int main()
{
    char *str1 = "ABCD";
    char *str2 = "CDBA";
    if(areRotation(str1,str2))
        printf("\n Rotation Possible");
    else
        printf("\n Rotation is not possible");
    return 0;
}
