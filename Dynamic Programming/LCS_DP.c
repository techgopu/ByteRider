#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b)
{
    return (a>b) ? a:b;
}

int lcs(char *X, char *Y, int m, int n)
{
    int L[m+1][n+1];
    int i, j;

    for(i=0;i<=m;i++)
    {
        for(j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1]+1; // add one to the previous diagonal cell
            else
                L[i][j] = max(L[i-1][j],L[i][j-1]); // compare immediate left and immediate upper cell
        }
    }
    return L[m][n];//L[m][n] contains the length of the LCS of X[1..m] and Y[1...n]
}


int main()
{
    char X[] = "abcdfxys";
    char Y[] = "cfsdfsmx";

    int m = strlen(X);
    int n = strlen(Y);

    printf("\n LCS of the given string is:%d", lcs(X,Y,m,n));
    return 0;
}
