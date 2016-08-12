/* A naive solution for the keypad problem:
    Given a no N find out the number of possible numbers of given length.
    for e.g., N=1, the output should be 10(0,1,2,3... ,9)

*/

#include<bits/stdc++.h>
using namespace std;
//left, up, right, down from the current position
int row[] = {0,0,-1,0,1};
int col[] = {0,-1,0,1,0};

// return count of numbers of length n starting form key position(i,j) in a numeric keypad

int getCountUtil(char keypad[][3], int i, int j, int n)
{
    if(keypad==NULL || n<=0)
        return 0;
    // from a given key only one number is possible of length 1
    if(n==1)
        return 1;
    int k=0,move=0,ro=0,co=0,totalCount=0;


    // move left,up,right and down from current position and if location is valid then get the number of count
    // of length n-1 from that new position and add in the count obtained so far

    for(move = 0; move<5; move++)
    {
        ro = i + row[move];
        co = j + col[move];
        if(ro>=0 && ro<=3 && co>=0 && co<=2 && keypad[ro][co]!='*' && keypad[ro][co]!='#')
        {
            totalCount+=getCountUtil(keypad,ro,co,n-1);
        }
    }
    return totalCount;
}

// return count of all possible numbers of length n in a given numeric keypad

int getCount(char keypad[][3], int n)
{
    //base case
    if(keypad==NULL || n<=0)
        return 0;
    if(n==1)
        return 10;

    int i=0,j=0, totalCount=0;
    for(i=0; i<4; i++)      //for keypad row
    {
        for(j=0; j<3; j++)  //for keypad col
        {

            //process 0 to 9 digits
            if(keypad[i][j]!='*' && keypad[i][j]!='#')
            {
                // get the count when number is starting from key position (i,j) and add it in count obtained so far
                totalCount+= getCountUtil(keypad,i,j,n);
            }
        }
    }

    return totalCount;
}


// main method
int main()
{
    char keypad[][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}
                        };

    cout<<"count for numbers of length 1:"<<getCount(keypad,1)<<endl;
    cout<<"count for numbers of length 2:"<<getCount(keypad,2)<<endl;
    cout<<"count for numbers of length 3:"<<getCount(keypad,3)<<endl;
    cout<<"count for numbers of length 4:"<<getCount(keypad,4)<<endl;
    cout<<"count for numbers of length 5:"<<getCount(keypad,5)<<endl;
    return 0;
}






