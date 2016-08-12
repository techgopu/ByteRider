/*  Transform one string to another using minimum no of operations.
    Input: A = "abd", B = "bad"; output: 1
    explanation: pick b and insert at the front

//solution:
    First we have to check that both the string must be of same size.

    Now how we find minimum no of operations when we sure that we can transform from A to B?
    The idea is to matching from last character of both the string.

    Alog:
        1> Find if A can be transformed to B or not by first creating a count array for all characters of A,
            then checking with B if B has same count for every character.
        2> Initialize result as 0.
        3> Start traversing from end of both the string.
            a>  if current character of A and B match i.e, A[i]=B[j] then do i=i-1 and j = j-1
            b>  if current characters don't match, the search B[j] in the remaining A, while searching keep
                incrementing result as these characters must be moved ahead for A to B transformation.
*/

#include<bits/stdc++.h>
using namespace std;

int minOperation(string &A, string &B)
{
    int m = A.length(), n = B.length();
    if(m!=n)
        return -1;
    int count[256];
    memset(count,0,sizeof(count));
    for(int i=0;i<n;i++)
        count[A[i]]++;
    for(int i=0;i<n;i++)
        count[B[i]]--;
    for(int i=0;i<256;i++)
    {
            if(count[i])
                return -1;
    }
    // this part required to check no of operations required to transformation
    int res=0;
    for(int i=n-1,j=n-1;i>=0;)
    {
        // if there is a mismatch, then keep incrementing result 'res' until match found in A[...]
        while(A[i]!=B[j] && i>=0)
        {
            i--;
            res++;
        }
        if(i>=0)
        {
            i--;
            j--;
        }

    }
    return res;
}

int main()
{
    string A = "dcbae";
    string B = "eabcd";
    int res = minOperation(A,B);
    cout<<res;
    return 0;

}
