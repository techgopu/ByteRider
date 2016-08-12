// Removing duplicates from a given string
/* Method 1:
    1) Sort the elements
    2) Now, in a loop remove all duplicate by comparing the current character with previous character
*/

#include<bits/stdc++.h>
using namespace std;

// this function does not keep the original order of the string, as it works on sorted string.
char *removeDupSorted(char *str)
{
    int res_ind = 1, ip_ind = 1;
    // inplace remove duplicate characters

    while(*(str+ip_ind))
    {
        if(*(str+ip_ind) != *(str+ip_ind-1))
        {
            *(str+res_ind) = *(str+ip_ind);
            res_ind++;
        }
        ip_ind++;
    }
    *(str+res_ind) = '\0';
    return str;
}

// Remove duplicate character from string. This function work inplace and fills null character in the extra space
char *removeDups(char *str)
{
    int n = strlen(str);
    // sort the character array
    sort(str, str+n);
    // remove duplicates from sorted string
    return (removeDupSorted(str));
}
/* Time complexity is O(nlogn) if we use quick sort for sort the string */

int main()
{
    char str[] = "eeeefggkkosss";
    cout<< removeDupSorted(str);
    return 0;
}
