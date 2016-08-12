/* Check a given sequence of moves for a robot is circular or not:
    A sequence of moves is circular if first and last position of robot is same. A move can be one of the
    following:
    G- Go one unit
    L- Left turn, R- Right turn
    Input: path[] = "GLGLGLG"
    output: Given sequence of moves is circular
*/

#include<iostream>
using namespace std;
// Macros for North, East, South and West
#define N 0
#define E 1
#define S 2
#define W 3

//this function return true if the given path is circular otherwise false

bool isCircular(char path[])
{
    // initialize the starting point for robot as (0,0) and starting direction as North
    int x = 0, y = 0;
    int dir = N;
    // Traverse the given path for robot
    for(int i=0; path[i]; i++)
    {
        // find current move
        int move = path[i];
        // if move is Left or Right then change the direction
        if(move == 'R')
            dir = (dir+1) % 4;
        else if(move == 'L')
            dir = (dir +3) % 4; // (4+dir-1) % 4
        // if move is Go then, change x or y co-ordinate according to direction
        else
        {
            if(dir==N)
                y++;
            else if(dir==E)
                x++;
            else if(dir==S)
                y--;
            else
                x--;
        }


    }
    return( x==0 && y==0);
}

int main()
{
    char *moves = "GLLLG";
    if(isCircular(moves))
        cout<<" Given Sequence Of Moves is Circular"<<endl;
    else
        cout<<" Given Sequence of Moves is not Circular"<<endl;

    return 0;
}




