// program to check whether the given two string is anagram or not.
#include<bits/stdc++.h>
#define MAX 256
using namespace std;

// solution using hashing

bool isAnagram(string str1, string str2)
{
    int m = str1.length();
    int n= str2.length();
    if(m!=n)
        return false;
    int binMap[MAX] = {0};
    for(int i=0; i<n; i++)
    {
        binMap[str1[i]]++;

    }
    for(int i=0; i<n; i++)
    {
        binMap[str2[i]]--;
    }
    for(int i=0; i<MAX; i++)
    {
        if(binMap[i]==1)
            return false;
    }
    return true;
}
int main()
{
    if(isAnagram("ramap","naram"))
        cout<<"anagram";
    else
        cout<<"not anagram";

    return 0;
}
