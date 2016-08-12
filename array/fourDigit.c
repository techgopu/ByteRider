#include<stdio.h>
int main()
{
    int i, j, k, l;
    int num;
    for(i=1; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            for(k=j+1; k<9; k++)
            {
                for(l=k+1; l<9; l++)
                    printf("%d%d%d%d \n",i,j,k,l);
            }
        }
    }
    return 0;
}
