/* program to print the permutation with repetition of the characters.
    input: AB , output: AA AB BA BB
    The idea is to fix the first character at first index and recursively call for other subsequent characters.
    Once all permutation started with first index is printed, fix the second character at first index. Continues
    these process till the last character.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//compare function for qsort()
int compare(const void *a, const void *b);

void allLexicographicRecur(char *str, char *data, int last, int index)
{
    int i, len = strlen(str);
    for(i = 0; i<len; i++)
    {
        data[index] = str[i];       //fix the first character
        if(index==last)
            printf("%s ",data);
        else //recur for the higher indexs
            allLexicographicRecur(str,data,last,index+1);
    }
}

void allLexicographic(char *str)
{
    int len = strlen(str);
    char *data = (char *) malloc(sizeof(char)*(len+1));
    data[len]= '\0';
    //sort the input string so that we get all output string in lexicographic order.
    qsort(str,len,sizeof(char),compare);
    allLexicographicRecur(str,data,len-1,0);
    free(data);
}
// needed for library qsort()
int compare(const void *a, const void *b)
{
    return (*(char*)a - *(char *)b);
}
int main()
{
    char str[] = "ABC";
    allLexicographic(str);
    return 0;
}
