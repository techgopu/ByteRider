/* Given a string, write a program that returns run length encoded string.
    For example, if the input string is: "wwwwaaadexxxxxx" then the program should return "w4a3ex6".

    Algo:
        1) pick the first character from the first string.
        2) append the source character to the destination string.
        3) count the no of subsequent occurrences of picked character and append the count to destination string.
        4) pick the next character and repeat steps 2) 3) and 4) until the end of character is not reached.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

char *runLenEncoded(char *str)
{
    int rlen;
    int len = strlen(str);
    char count[MAX];
    char *dest = (char *)malloc(sizeof(char)*(len*2+1));
    int i,j=0,k;
    for(i=0; i<len; i++)
    {
        //copy the first occurrence of new character
        dest[j++] = str[i];
        // count the no of occurrence of new character
        rlen = 1;
        while(i+1<len && str[i]==str[i+1])
        {
            rlen++;
            i++;
        }
        //store rlen in character array
        sprintf(count,"%d",rlen);
        //copy count to the destination
        for(k=0; *(count+k);k++)
            dest[j++] = count[k];
    }
    //terminate the destination string
    dest[j]='\0';
    return dest;
}
int main()
{
    char str[] = "aaaabbbewwxxxxxx";
    printf("%s",runLenEncoded(str));
    return 0;
}
