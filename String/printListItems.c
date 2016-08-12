/* print list items that containing all characters of a given word
    Algo:

    1) Initialize a binary map
    2) set the values in map
    3) Store the length of the word
    4) Pick words one by one from the list
        a) set count to 0
        b) for each character of the picked word
                if(map[ch]) is set
                    increment count and unset map[ch]
        c) if count becomes equal to length
                print the currently picked word
        d) set the values in map[] for next word

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NO_OF_CHARS 256

void printListItems(char *list[], char *word, int listSize)
{
    int *map = (int *)calloc(sizeof(int), NO_OF_CHARS);
    int i, j, count, wordSize;
    // set values in map
    for(i=0; *(word+i); i++)
        map[*(word+i)]=1;
    wordSize = strlen(word);

    //check each item of the given list has all characters of given word
    for(i=0; i<listSize; i++)
    {
        for(j=0, count=0; *(list[i]+j); j++)
        {
            if(map[*(list[i]+j)])
                count++;
            // unset the bit so that string like sss not printed
        }
        if(count == wordSize)
            printf("%s\n",list[i]);

        //set the values in map for next item
        for(j =0; *(word+j); j++)
            map[*(word+j)] = 1;
    }

}
int main()
{
    char str[] = "sun";
    char *list[] = {"sunday","monday","surrender","surrounding","underscore"};

    printListItems(list,str,5);
    return 0;
}

