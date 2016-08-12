// swap string using pointers

#include<stdio.h>

// This method will work only when char pointer is used to store the string.
// This method cannot be applied if strings are stored using character arrays.
void swap(char **str1_ptr, char **str2_ptr)
{
    char *temp = *str1_ptr;
    *str1_ptr = *str2_ptr;
    *str2_ptr = temp;
}

int main()
{
    char *str1 = "Gopal";
    char *str2 = "Jha";
    printf("%s %s\n", str1 , str2);
    swap(&str1, &str2);
    printf("%s %s", str1 , str2);
    return 0;
}
