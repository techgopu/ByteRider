/* Reverse a string without affecting special character.


    input: "a,b$c" output: "c,b$a"

*/

#include<bits/stdc++.h>
using namespace std;

void swap(char *ch1, char *ch2)
{
    char *ch = ch1;
    ch1 = ch2;
    ch2 = ch;
}

bool isAlphabet(char ch)
{
    if((ch>='a' || ch >='A') && (ch<='z' || ch<= 'Z'))
       return true;
}

void reverse(char *str)
{
    int l = 0;
    int r = strlen(str) -1;

    while(l<r)
    {
        if(!isAlphabet(str[l]))
            l++;
        else if(!isAlphabet(str[r]))
            r--;
        else
        {
            swap(str[l], str[r]);
            l++; r--;
        }
    }
}


int main()
{
    char str[] = "a,bcd,c$de!p";
    reverse(str);
    cout<< str;
    return 0;
}

