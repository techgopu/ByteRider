// check if the edit distance between two string is one
#include<bits/stdc++.h>
using namespace std;

// simple recursive solution

//int distanceBetweenStrings(char *str1, char *str2, int m, int n)
int distanceBetweenStrings(string str1, string str2, int m, int n)
{
    /*int m=str1.length();
    int n=str2.length(); */

    // base case
    if(m==0 || n==0)
        return 0;
    if(str1[m-1]!=str2[n-1])
        return 1+ distanceBetweenStrings(str1, str2, m-1,n-1);
    return distanceBetweenStrings(str1,str2,m-1,n-1);

}

int main()
{
    char str1[] ="gevks";
    char str2[] ="geems";
    string str11 = "geeks";
    string str22 = "geeps";
    int i = distanceBetweenStrings(str11, str22,5,5);
    if(i==1)
        cout<<"Yes!! String can be match by edit one character!!";
    else
        cout<<endl<<"You have to edit more than one character!!";
    return 0;
}
