/* Find concatenation of zig-zag string in n rows:

    input: abcdefgh, n=2
    output: acfgbdfh

    Idea is to traverse the input string. Every character has go to one of the rows. one by one add all
    characters to different rows.
    Algo:
    1) create an array of n strings
    2) initialize direction as down and row as 0. the direction indicates whether we need to move up or down in rows
    3) Traverse the input string, do the following for the very character:
        a) append current character to string of current row.
        b) if row number is n-1, then change direction to up.
        c) if row number is 0, then change direction to down.
        d) if direction is down then do row++, else row--;
    4) one bye one print all the string of arrays.
*/

#include<bits/stdc++.h>
using namespace std;

void printZigZagConcat(string str, int n)
{
    // corner case if n=1, simply print the string
    if(n==1)
    {
        cout<<endl<<str;
        return;
    }
    int len = str.length();
    string arr[n];
    int row = 0;
    bool down; // default true

    for(int i =0; i<len; i++)
    {
        arr[row].push_back(str[i]);
        if(row == n-1)
            down = false;
        else if(row==0)
            down = true;
        (down)? (row++) : (row--);
    }
    // print concatenations of all rows
    for(int i=0; i<n; i++)
        cout<<arr[i];
}
int main()
{
    string str = "abcdefgh";
    int n = 2;
    printZigZagConcat(str,n);
    return 0;
}
