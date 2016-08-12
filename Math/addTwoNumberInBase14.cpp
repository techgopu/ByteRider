/*
Just add the numbers in base 14 in same way we add in base 10. Add numerals of both numbers one by one
from right to left. If there is a carry while adding two numerals, consider the carry for adding next
numerals.

Let us consider the presentation of base 14 numbers same as hexadecimal numbers

   A --> 10
   B --> 11
   C --> 12
   D --> 13
Example:
   num1 =       1  2  A
   num2 =       C  D  3

   1. Add A and 3, we get 13(D). Since 13 is smaller than
14, carry becomes 0 and resultant numeral becomes D

  2. Add 2, D and carry(0). we get 15. Since 15 is greater
than 13, carry becomes 1 and resultant numeral is 15 - 14 = 1

  3. Add 1, C and carry(1). we get 14. Since 14 is greater
than 13, carry becomes 1 and resultant numeral is 14 - 14 = 0

Finally, there is a carry, so 1 is added as leftmost numeral and the result becomes
101D
*/
#include<bits/stdc++.h>
using namespace std;
/*
Function to get value of a numeral
for example it returns 10 for input 'A' and 1 for '1'
*/

int getNumber(char num)
{
    if(num >= '0' && num <= '9')
        return(num - '0');
    if(num >= 'A' && num <= 'D')
        return(num - 'A' + 10);
    assert(0);
}
/*
Function to get numeral for a given value
For example it return 'A' for 10 and '1' for 1
*/
char getNumeral(int num)
{
    if(num>=0 && num<=9)
        return( num + '0');
    if(num>=10 && num <=14)
        return (num + 'A' -10);
    assert(0);
}

char *add(char *num1, char *num2)
{
        int l1 = strlen(num1);
        int l2 = strlen(num2);
        if(l1!=l2)
        {
            cout<<"Function doesn't support for different length numbers";
            cout<<".If you want to add, prefix the smaller number with";
            cout<<" required no of zeros.";
            assert(0);
        }
        char *res;
        int nml1, nml2, res_nml;
        int carry = 0;

        res = new char[l1+1];
        for(int i = l1-1;i>=0; i--)
        {
                nml1 = getNumber(num1[i]);
                nml2 = getNumber(num2[i]);

                res_nml = carry + nml1 + nml2;
                if(res_nml >=14)
                {
                    carry = 1;
                    res_nml -= 14;
                }
                else
                {
                    carry = 0;
                }
                res[i+1] = getNumeral(res_nml);
        }
        if(carry==0)
            return res+1;
        res[0] = '1';
        return res;
}
int main()
{
    char num1[] = "ACD";
    char num2[] = "ACD";
    cout<<add(num1,num2);
    return 0;
}





