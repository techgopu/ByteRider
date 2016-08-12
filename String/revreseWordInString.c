/* program to reverse all the words in a given string
    Ex: I am Gopal Kumar, output should be Kumar Gopal am I

    Algo:
        1) Reverse the individual words in the string.
        2) Reverse the whole string.

*/
#include<stdio.h>
void revString(char *begin, char *end);

// this function does not handle the begining spaces
void revWord(char *str)
{
    char *temp = str;
    char *begin = str;
    while(*temp)
    {
        temp++;
        if(*temp == '\0')
            revString(begin, temp-1);
        if(*temp==' ')
        {
            revString(begin, temp-1);
            begin = temp+1;
        }
    }
    revString(str,temp-1);
}
// this function handle the beginning spaces

void reverseWord(char *str)
{
    char *temp = str, *begin = "NULL";
    while(*temp)
    {
        if(begin==NULL && *temp!=' ')
        {
            begin = temp;
        }
        if(begin && (*(temp+1)== ' ') || (*(temp+1)=='\0'))
        {
               revString(begin, temp);
               begin = NULL;
        }
        temp++;
    }
    revString(str,temp-1);
}

void revString(char *begin, char *end)
{
    char temp;
    while(begin<end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

int main()
{
    char str1[] = "I Like Programming Very Much";
    char str2[] = "             This string has spaces at the beginning";

    revWord(str1);
    printf("%s\n",str1);
    reverseWord(str2);
    printf("%s\n",str2);


    return 0;
}
