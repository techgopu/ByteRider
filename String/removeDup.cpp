// remove the duplicate characters form a string
// Method 2: Hashing

#include<bits/stdc++.h>
#define NO_OF_CHARS 256
using namespace std;

char *removeDups(char *str)
{
    bool bin_hash[NO_OF_CHARS] = {false};
    int ip_ind=0, res_ind=0;
    char temp;
    // inplace removal of duplicates characters
    while(*(str+ip_ind))
    {
        temp = *(str+ip_ind);
        if(bin_hash[temp] == false)
        {
            bin_hash[temp] = true;
            *(str+res_ind) = *(str+ip_ind);
            res_ind++;
        }
        ip_ind++;
    }
    *(str+res_ind) = '\0';
    return str;
}

// Driver method to check above functions
int main()
{
    char str[] = "geeksforgeeks is the best side for coding";
    cout<<removeDups(str);
    return 0;
}
