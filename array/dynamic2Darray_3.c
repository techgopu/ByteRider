// create a dynamic 2-D array using pointer to pointer

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r = 3, c = 4;
    int count = 0,i,j;

    int **arr = (int **) malloc(r * sizeof(int*));
    for(i=0; i<r; i++)
        arr[i] = (int *) malloc(c * sizeof(int));

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            *(*(arr+i) +j ) = rand();
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    free(arr);
    return 0;
}
