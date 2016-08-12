/* Length of the longest valid substring

    Given a string consisting of opening and closed parenthesis. find the length of longest valid parenthesize
    substring.

    e.g., Input: (((), output: 2, ()    Input: )()()), output: 4, ()()
 //solution:

        Idea is to store the indexes of the previous stating parenthesis in the stack. The first element of the
        stack is a special element that provide index before beginning of valid substring.
*/


#include<bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
    int n = str.length();
    //create a stack and push -1 as initial index to it
    stack<int>stk;
    stk.push(-1);
    //initialize result as zero
    int res = 0;
    //traverse all characters of the given string
    for(int i=0; i<n; i++)
    {
        //if opening parenthesis, push index of it
        if(str[i] == '(')
            stk.push(i);
        else // if closing parenthesis
        {
            //pop the previous opening parenthesis
            stk.pop();
            //check if the length formed with base of current valid substring is more than the max so far
            if(!stk.empty())
                res = max(res, i-stk.top());
            // if stack is empty, push current index as base for the next valid substring
            else
                stk.push(i);
        }
    }
    return res;
}

//Driver
int main()
{
    string str = ")()()((()))(((";
    cout<<findMaxLen(str);
    return 0;
}
