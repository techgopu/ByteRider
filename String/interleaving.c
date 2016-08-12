/* Print all interleaving of the given two strings
    Here assumption is both the string contains different characters.
    Input: str1 = AB, str2 = CD
    output: ABCD
            ACBD
            ACDB
            CABD
            CADB
    An interleaving string of given two strings preserves the order of characters in individual string. For example
    in all the interleaving of above example A comes before B and C comes before D.

sol:
    Let the length of str1 be m and length of str2 be n. Let us assume that all characters in str1 and str2 are
    different. Let count(m,n) be the count of all interleaved string in such strings. The value of count(m,n) can
    be written as following:

    count(m,n) = count(m-1,n) + count(m,n-1)
    count(1,0) = 1 and count(0,1) = 1

    To print all the interleaving. We fix the first character of str1[0...m-1] in the output string and recursively calls
    for str1[1...m-1] and str2[0....n-1] and then we can fix the first character of str2[0...n-1] in the output
    string and recursively calls for str1[0....m-1] and str2[1....n-1]
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printIlsRecur(char *str1, char *str2, char *iStr, int m, int n, int i)
{
    //base case : if all characters of str1 and str2 have been included in output string, then print the output
    //string.

    if(m==0 && n==0)
        printf("%s ",iStr);
    //if some element are left to be included, then include first character from the remaining and recur for the rest
    if(m!=0)
    {
        iStr[i] = str1[0];
        printIlsRecur(str1+1,str2,iStr,m-1,n,i+1);
    }
    if(n!=0)
    {
        iStr[i] = str2[0];
        printIlsRecur(str1, str2+1,iStr,m,n-1,i+1);
    }

}

void printIls(char *str1, char *str2, int m, int n)
{
    //allocate memory for the output string
    char *iStr = (char *)malloc(sizeof(char)*(m+n+1));
    iStr[m+n]='\0';
    //print all interleaving using printIlsRecur()
    printIlsRecur(str1,str2,iStr,m,n,0);
    free(iStr);
}

int main()
{
    char str1[] = "AB";
    char str2[] = "CD";
    printIls(str1,str2,strlen(str1),strlen(str2));
    return 0;
}
