// check the given two string is isomorphic of each other

#include<bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;


bool isIsomorphic(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    if(m!=n)
        return false;
    bool marked[MAX_CHAR] = {false};
    int mapped[MAX_CHAR];
    memset(mapped,-1,sizeof(mapped));

    for(int i=0;i<n;i++)
    {
        if(mapped[str1[i]]==-1) //str1[i] is seen at first time
        {
            if(marked[str2[i]]==true) // if str2[i] is already available return false
                return false;
            marked[str2[i]] == true;  //mark current character of str2 as visited
            mapped[str1[i]] = str2[i];
        }
        else if(mapped[str1[i]]!=str2[i])
            return false;
    }
    return true;
}
int main()
{
    string str1 = "xxyyzzabc";
    string str2 = "aabbccxyz";
    if(isIsomorphic(str1,str2))
        cout<<"Isomorphic";
    else
        cout<<"Not Isomorphic";
    return 0;
}
