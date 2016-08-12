/*Find the maximum depth of nested parenthesis in a string:
    we are given a string having parenthesis like given below
    "(((x))(((y))))" you need to find the maximum depth of balanced parenthesis, like 4 in the above
    example since y is balanced by the 4 balanced parenthesis.
    if parenthesis is unbalanced then return -1.

    We can solve this problem using two methods:
    M1) using stack time O(n) space O(n)
    M2) without using stack and in constant auxiliary space
        Algo:
        1) Take a variable max and current max, initialize both of them as 0.
        2) Traverse the string and do the following for every character.
            a) if the current character is '(', increase the current max and update max value if required.
            b) if character is ')', check the current max is positive or not( this condition ensures that
                parenthesis is balanced), if positive that means we previously had a '(' character so decrement
                current max without worry. if not positive then parenthesis is not balanced, return -1.
            c) if current max is not zero, then return -1 to ensure that parenthesis is not balanced. else return max
*/

#include<bits/stdc++.h>
using namespace std;

int maxDepth(string str)
{
    int currentMax = 0, max = 0, n=str.length();
    for(int i=0; i<n; i++)
    {
        if(str[i] == '(')
        {
            currentMax++;
            if(currentMax >= max);
                max = currentMax;
        }
        if(str[i]==')')
        {
            if(currentMax<0)
                return -1;
            currentMax--;
        }
    }
    if(currentMax==0)
        return max;
    return -1;
}

int main()
{
    string str = "(((a))(((b))))";
    int i = maxDepth(str);
    (i==-1)? cout<<"Not balanced" : cout<<i;
    return 0;
}




