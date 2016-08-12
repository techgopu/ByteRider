// program to find first non repeating character in a string
#include<stdio.h>
#include<stdlib.h>
#define NO_OF_CHARS 256

int *getCountArray(char *str)
{
    int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for(i=0; *(str+i); i++)
        count[*(str + i)]++;
    return count;
}

// this function return index of the first non repeating character. if all characters are repeating then return -1
int firstNonRepeating(char *str)
{
    int *count = getCountArray(str);
    int index = -1;
    int i;
    for(i=0;*(str+i);i++)
    {
        if(count[*(str+i)] == 1)
        {
            index = i;
            break;
        }
    }
    free(count);
    return index;
}

// Driver function to check above function
 int main()
 {
     char *str = "geeksforgeeks";
     int index = firstNonRepeating(str);
     if(index == -1)
        printf("\n All the characters are repeated");
     else
        printf("\n First Repeating character is: %c", str[index]);
     return 0;
 }
