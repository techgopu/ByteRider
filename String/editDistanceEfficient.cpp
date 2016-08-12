// An efficient solution to check if edit distance between two string is one

/* Algorithm:
                Let the input string be s1 and s2 and length  of input string be m and n respectively
                1) if the distance between string is more than 1, return false
                2) initialize count of edit as 0
                3) start traversing both the strings from first character
                    a) if current character don't match
                        i   ->  increment count of edit
                        ii  ->  if count become more than 1, return false
                        iii ->  if the length of one string is more than one then only possibility is to
                                to remove a character. Therefore move one index ahead in larger string.
                        iv  ->  if length is same, them only possible edit is to change a character. Therefor, move
                                a index ahead in both the strings.
                    b) else, move ahead in both the strings.

*/


#include<bits/stdc++.h>
using namespace std;


bool isEditDistanceOne(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    if(abs(m-n)>1)
        return false;
    int count = 0;
    int i=0, j=0;

    while(i<m && j<n)
    {
        if(s1[i] != s2[j])
        {
            if(count==1)
                return false;
            if(m>n)
                i++;
            else if(m<n)
                j++;
            else
            {
                i++;
                j++;
            }
            count++;

        }
        else
        {
            i++;
            j++;
        }
    }
    // if last character is exist in any of the string
    if(i<m || j<n)
        count++;
    return count == 1;

}



int main()
{
    string s1 = "Geeks";
    string s2 = "Geks";
    isEditDistanceOne(s1,s2) ? cout<<"yes" : cout<<"No";
    return 0;
}
