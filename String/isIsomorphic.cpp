/* Check if two given strings are isomorphic to each other :
    Two strings s1 and s2 are called isomorphic if there is a one to one mapping possible for every character
    of s1 to every character of s2. And all occurrence of every character in s1 map to same character in s2.
    example: aab, ssy are isomorphic to each other.

  Algo:
        The idea is to create an array to store mapping of processed characters
        1) if length of s1 and s2 isn't same return false
        2) do the following for every character in s1 and s2
            a) if this character is seen first time in s1, then current of s2 must have not appear before
                i. if current character of s2 is seen, return false
                    mark current character of s2 as visited.
                ii. store mapping of current character.
            b) else check if previous occurrence of s1[i] mapped to same character.

*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 256

bool areIsomorphic(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    if(m!=n)
        return false;
    bool marked[MAX] = {false};
    int map[MAX];
    memset(map, -1, sizeof(map));

    for(int i=0; i<n; i++)
    {
        if(map[s1[i]]==-1)
        {
            if(marked[s2[i]]== true)
                return false;
            marked[s2[i]] = true;   //mark current character of s2 as visited

            map[s1[i]] = s2[i];     // store mapping of current character
        }
        // if it is not first appearance of current character in s1, then check if previous appearance mapped
        // to same character of s2
        else if(map[s1[i]]!=s2[i])
            return false;
    }
    return true;

}

int main()
{
    string s1 = "aabcc";
    string s2 = "xxyzz";
    areIsomorphic(s1,s2)?cout<<"Yes!! Give strings are isomorphic":cout<< "No, not isomorphic";
    return 0;
}





