/*
    program to permute a string

*/
#include<iostream>
#include<string.h>
using namespace std;
void swap(char *a, char *b)
{
    char temp;
    temp  = *a;
    *a = *b;
    *b = temp;
}

/*
This function takes three arguments:
    string,starting index, ending index
*/
void permuteString(char *str, int l, int r)
{
    if(l==r)
        cout<<str<<endl;
    else
    {
        for(int i = l; i<=r; i++)
        {
            swap((str+l),(str+i));
            permuteString(str, l+1,r);
            swap((str+l),(str+i)); //back track;
        }
    }
}


int main()
{
    char str[] = "ABC";
    permuteString(str,0,strlen(str)-1);
    return 0;
}
