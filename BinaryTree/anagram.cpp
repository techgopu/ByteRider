#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256
#define MAX 100000
using namespace std;



/* function to check whether two strings are anagram of
   each other */
int areAnagram(char *str1, char *str2, int len)
{
    // Create 2 count arrays and initialize all values as 0
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};
    int count=0;

    // For each character in input strings, increment count in
    // the corresponding count array
    for (int i = 0; i<len;  i++)
    {
        count1[str1[i]]++;              xaxbbbxx
        count2[str2[i]]++;
    }
    for (int i = 0; i<len;  i++)
    {
        if(count1[str1[i]] != count1[str2[i]] && count2[str1[i]] != count2[str2[i]])
            count++;

    }
    // Compare count arrays
    /*for (int i = 0; i < NO_OF_CHARS; i++)
        {
            if(count1[i]!=count2[i])
            {
                count++;
            }

        }*/
     return count;
}


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,res=-1;
    char str[MAX];
    cin>>T;
    while(T >= 1 && T <=100)
    {
        //fgets(str,MAX,stdin);
        cin>>str;
        int len = strlen(str);
        if(len%2 != 0)
            printf("%d\n",res);
        else
        {
            cout<<areAnagram(str, str+len/2, len/2)<<endl;
        }
        T--;
    }
    return 0;
}
