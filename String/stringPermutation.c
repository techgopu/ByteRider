// program to print all permutations with duplicates allowed
#include<stdio.h>
#include<string.h>

/* function to print permutation of the string, this function takes three arguments
    1) String
    2) starting index of the string
    3) ending index of the string
*/

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void permute(char *str, int l, int r)
{
    int i;
    if(l==r)
        printf("%s \n",str);
    else
    {
        for(i =l; i<=r; i++)
        {
            swap((str+l),(str+i));
            permute(str,l+1,r);
            swap((str+l),(str+i));  //backtrack

        }
    }
}
int main()
{
    char str[] = "ABCD";
    int len = sizeof(str)/sizeof(str[0]);
    printf("%d\n",len);

    permute(str,0,strlen(str)-1);
    return 0;

}
