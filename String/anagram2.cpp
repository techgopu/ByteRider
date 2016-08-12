// program to check the given strings are anagram or not
#include<bits/stdc++.h>
using namespace std;

// using sorting

bool isAnagram(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    if(m!=n)
        return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    for(int i=0;i<n;i++)
    {
        if(str1[i]!=str2[i])
            return false;
    }
    return true;
}
int main()
{
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    if(isAnagram(str1,str2))
        cout<<"anagram";
    else
        cout<<"not anagram";
    return 0;
}

