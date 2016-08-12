#include<bits/stdc++.h>
#define Row 4
#define Col 4
using namespace std;

void spiralPrint(int mat[][Col],int m, int n)
{
    int L=0, R = n-1;
    int T = 0, B = m-1;
    int dir = 0;
    while(L<=R && T<=B)
    {
            if(dir==0)
            {
                for(int K=L; K<=R; K++)
                   printf("%d ",mat[T][K]);
                T++;

            }

            else if(dir == 1)
            {
                for(int K=T; K<=B; K++)
                    cout<< mat[K][R]<<" ";
                R--;
            }
            else if(dir == 2)
            {
                for(int K=R; K>=L; K--)
                    cout<< mat[B][K]<<" ";
                B--;
            }
            else if(dir == 3)
            {
                for(int K = B; K>=T; K--)
                    cout<<mat[K][L]<<" ";
                L++;
            }
            dir = (dir+1)%4;
    }

}
int main()
{
    int mat[Row][Col] = {
                            {1,2,3,4},
                            {5,6,7,8},
                            {9,10,11,12},
                            {13,14,15,16}
                    };
    spiralPrint(mat,Row,Col);
    return 0;
}
