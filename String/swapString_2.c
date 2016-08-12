// This method is applicable when character array is used to store the string.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *str1, char *str2)
{
    char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    free(temp);
}

int main()
{
    char str1[] = "Gopal";
    char str2[] = "Jha";
    swap(str1, str2);
    printf("%s %s", str1, str2);
    return 0;
}
