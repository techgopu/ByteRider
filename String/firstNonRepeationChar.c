/* we can improve the previous solution. The idea is to augment the count array by storing not just count but
    also the index of first time you encountered the character e.g., (3,26) for 'a' meaning that a is encountered
    three times and the first time it was seen at the position 26. So when it comes to find the first non repeating
    character, we need to scan the count array instead of string.
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define NO_OF_CHARS 256

// Structure to store the count of characters and the index of first occurrence the character in the input string

struct countIndex
{
    int count;
    int index;
};

struct countIndex* getCountArray(char *str)
{
        struct countIndex *count = (struct countIndex*)calloc(sizeof(struct countIndex),NO_OF_CHARS);
        int i;
        for(i = 0;*(str+i); i++)
        {
            (count[*(str+i)].count)++;
            //if it is first occurrence then store the index
            if(count[*(str+i)].count == 1)
                count[*(str+i)].index =i;
        }
        return count;
}

// find first non repeating
int firstNonRepeatingChar(char *str)
{
    struct countIndex *count = getCountArray(str);
    int res = INT_MAX, i;
    for(i=0;i<NO_OF_CHARS; i++)
    {
        if(count[i].count == 1 && res > count[i].index )
            res = count[i].index;

    }
    free(count);
    return res;
}

// Driver Program to check above functions
int main()
{
    char *str = "main hoon naa";
    int index = firstNonRepeatingChar(str);
    if(index==INT_MAX)
        printf("\n Either all characters are repeating or no character is repeating!");
    else
        printf("\n First Non Repeating Character is: %c", str[index]);
    return 0;
}
