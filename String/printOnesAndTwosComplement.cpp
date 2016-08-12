#include<bits/stdc++.h>
using namespace std;

// return 0 for one and 1 for 0

char flip(char c)
{
    return (c =='0')? '1':'0';
}

// print 1's and 2's complement of a binary number represented by bin
void printOnesAndTwosComplement(string bin)
{
    string ones,twos;
    int i;
    int n = bin.length();
    ones = twos = "";
    for(i = 0; i<n; i++)
    {
        ones += flip(bin[i]);
    }

    // for 2's complement go from right to left in 1's complement and if we get 1 we make them 0 and
    // keep going left until we find first 0. if find the first 0 make it 1 and go out of the loop

   /* twos = ones;
    for(i = n-1; i >= 0; i--)
    {
        if(ones[i]=='1')
            twos[i]='0';
        else
        {
            twos[i]='1';
            break;
        }
    }

    // if no break, i.e., all 1 as 111 or 1111 in the 1's complement. Here in this case we have to add one
    // extra one at the beginning of the twos
    if(i == -1)
        twos = '1' + twos;

    cout<<ones<<'\n';
    cout<<twos<<'\n';

    */

    // for 2's complement we can also iterate in bin from right side until we get first 1. when we get the first
    // one break the loop and flip all the remaining bits.


        twos = bin;
        for(i=n-1; i>=0; i--)
        {
            if(bin[i] == '1')
                break;

        }
        // if bin contains only 0s like 000 00000 etc
        if(i==-1)
            twos = '1' + bin;
        else
        {
            for(int j=0; j<i; j++)
            {
                twos[j] = flip(bin[j]);
            }
        }

        cout<<ones<<'\n';
        cout<<twos<<'\n';

}

int main()
{
    string bin = "0000";
    printOnesAndTwosComplement(bin);
    return 0;

}









