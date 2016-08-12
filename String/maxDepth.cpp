/* program to find maximum depth of nested parenthesis in a string
    For e.g., if the given string is (((x))(((y)))), you need tho find the maximum depth of balanced parenthesis
    like 4 in th above example since y is balanced by 4 balanced parenthesis.


        Method1: Using stack
                    Time complexity: O(n)
                    space complexity: O(n)

        Method2: Without using stack
                    Time complexity O(n)
                    Auxiliary space O(1)

*/

#include<bits/stdc++.h>
using namespace std;

int maxDepth(string str)
{
    int curMax=0, max=0, n = str.length();
    for(int i=0; i<n; i++)
    {
        if(str[i] == '(')
        {
            curMax++;
            if(max<curMax)
                max=curMax;
        }
        else if(str[i] == ')')
        {
            if(curMax > 0)
                curMax--;
            else
                return -1;
        }
    }
    if(curMax != 0)
        return -1;
    return max;
}
int main()
{
    string str = "(((a))(((b))))";
    cout<<maxDepth(str);
    return 0;
}
