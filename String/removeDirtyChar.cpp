// Remove the characters from the first string which are present in the second string.

#include<bits/stdc++.h>
#include<iostream>
#define NO_OF_CHARS 256
using namespace std;

// This function returns an array of size 256 containing count of characters in the passed char array

int *getCountArray(char *str)
{
    int *countArray = (int *)calloc(sizeof(int),NO_OF_CHARS);
    int i;
    for(i=0;*(str+i);i++)
        countArray[str[i]]++;
    return countArray;
}

/* removeDirtyChars takes two strings as arguments: First string is the one from where function removes dirty
    characters. Second string is the string which contains all the dirty characters which need to remove from
    first string.
*/

char *removeDirtyChars(char *str, char *maskStr)
{
    int *countArray = getCountArray(maskStr);
    int ipInd=0, resInd=0;
    while(*(str+ipInd))
    {
        char temp = *(str+ipInd);
        if(countArray[temp] == 0)
        {
            *(str+resInd) = *(str+ipInd);
            resInd++;
        }
        ipInd++;
    }
    *(str+resInd) = '\0';
    return str;
}

// Driver function to check the above function
int main()
{
    char  str[] = "geeksforgeeks";
    char  maskStr[] = "for";
    cout<<removeDirtyChars(str,maskStr);
    return 0;
}
