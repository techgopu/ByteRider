#include<bits/stdc++.h>
#define MAX 10
using namespace std;


int sumOfElements(int x1, int y1, int z1, int x2, int y2, int z2, int arr[][MAX][MAX])
{
    int sum = 0;
    for(int i=x1; i<=x2; i++)
    {
        for(int j=y1; j<=y2; j++)
        {
            for(int k=z1; k<=z2; k++)
                sum += arr[i][j][k];

        }
    }
    return sum;
}
void updateIndex(int x1, int y1, int z1, int w1,int arr[][MAX][MAX])
{
    arr[x1][y1][z1] = w1;
}
int main()
{
    int m, n;
    int t;
    int x1, y1, z1, w1, x2,y2,z2;
    int arr[MAX][MAX][MAX] = {0};
    //cout<<arr[4][5][];

    cin>>t;
    while(t--)
    {
      cin>>n;
      cin>>m;
      while(m--)
      {


      }


    }

    return 0;
}
