// remove duplicate characters from a string. The characters in the string will be in same order as original
// after removal
#include<bits/stdc++.h>
#define ASCIICHARS 256
using namespace std;

// a solution using hashing

char *removeDupChars(char *str)
{
    bool binHash[ASCIICHARS] = {false};
    int ipIndex =0,resIndex=0;
    char temp;

    while(*(str+ipIndex))
    {
        temp = *(str+ipIndex);
        if(!binHash[temp])
        {
             binHash[temp] = true;
            *(str+resIndex) = *(str+ipIndex);
            resIndex++;
        }
        ipIndex++;
    }
    *(str+resIndex) = '\0';
    return str;
}
int main()
{
    char str[] = "thisisthedemostring";
    cout<<removeDupChars(str);
    return 0;
}
