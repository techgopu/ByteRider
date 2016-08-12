#include<iostream>
using namespace std;

#define N 0
#define E 1
#define S 2
#define W 3



bool isCircular(char *path,int n)
{
    int x=0,y=0;
    int dir = N;
    int mov;

    for(int i=0; i<n; i++)
    {
        mov = path[i];
        if(mov=='R')
            dir = (dir+1)%4;
        else if(mov=='L')
            dir = (4+dir-1)%4;
        else
        {
            if(dir==N)
                y++;
            else if(dir==S)
                y--;
            else if(dir==E)
                x++;
            else
                x--;
        }
    }
    return (x==0 && y==0);
}

int main()
{
    char mov[] = {'G','L','G','L','G','L','G'};
    int n = sizeof(mov)/sizeof(mov[0]);
    if(isCircular(mov,n))
        cout<<"Yes! Given path is circular";
    else
        cout<<"No! Given path is not circular";
    return 0;
}
