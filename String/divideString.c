
// program to divide an string into n equal parts
#include<stdio.h>
#include<string.h>

void divideString(char *str, int n)
{
    int str_size = strlen(str);
    int i;
    int part_size;
    /* check if string can be divide in equal parts */
    if(str_size % n != 0)
    {
        printf(" String cant be divided into equal parts!");
        return ;
    }

    part_size = str_size/n;
    for(i =0; i<str_size; i++)
    {
        if(i % part_size == 0)
            printf("\n");
        printf("%c", str[i]);

    }
}

int main()
{
    char *str = "a_simple_divide_string_quest";
    divideString(str,4);
    return 0;
}



