/* program to return the count of words in a string. The words are separated by the following characters
    ('\n'),(' ') and ('\t')
*/

#include<stdio.h>
#define IN 1
#define OUT 0

int countWords(char *str)
{
    unsigned count = 0;
    int state = OUT;
    while(*str)
    {
        if(*str=='\t' || *str == '\n' || *str==' ')
            state = OUT;
        else if(state == OUT)
        {
            count++;
            state = IN;
        }
        str++;
    }
    return count;
}
int main()
{
    char str[] = "      This program give the     count of words in       string";
    printf("%d",countWords(str));
    return 0;
}
