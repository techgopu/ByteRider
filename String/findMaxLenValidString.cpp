/* Length of longest valid substring:

    input: )()())
    output: 4
    input : ((()
    output: 2

    Algo:
    1) Create an empty stack and push -1 to it. This first element of stack is used to provide base for
        next valid string .
    2) initialize result as 0.
    3) if character is '(' i.e., str[i] = '(', push index 'i' to stack.
    4) else
            if character is ')'
                a) pop an item form stack.
                b) if stack isn't empty, then find the length of the current valid substring by taking difference
                    between current index and top of the stack. If the current result is greater than the calculated
                    result, update the result.
                c) if stack is empty push the current index as the base for valid substring.
    5) return result.

*/
#include<bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
    stack<int> stk;
    int n = str.length();
    stk.push(-1);
    int res = 0;


    // traverse all the characters

    for(int i=0; i<n; i++)
    {
        if(str[i]=='(')
            stk.push(i);
        else if(str[i]==')')
        {
            stk.pop();
            if(!stk.empty())
                res = max(res, i - stk.top());
            else
                stk.push(i);
        }
        else
        {
            cout<<endl<< "invalid characters in the string!";
            return 0;
        }
    }
    return res;
}

int main()
{
    string str = "((())))))";
    cout<<endl<<"Length of valid parenthesis:: "<< findMaxLen(str);

    return 0;
}






