/*
Print all combinations of points that can compose a given number
You can win three kinds of basketball points, 1 point, 2 points, and 3 points. Given a total score n, print out all the combination to compose n.

Examples:
For n = 1, the program should print following:
1

For n = 2, the program should print following:
1 1
2

For n = 3, the program should print following:
1 1 1
1 2
2 1
3

For n = 4, the program should print following:
1 1 1 1
1 1 2
1 2 1
1 3
2 1 1
2 2
3 1

and so on …

Algorithm:
At first position we can have three numbers 1 or 2 or 3.
First put 1 at first position and recursively call for n-1.
Then put 2 at first position and recursively call for n-2.
Then put 3 at first position and recursively call for n-3.
If n becomes 0 then we have formed a combination that compose n, so print the current combination.
*/
#include<iostream>
#define SIZE 20
#define MAX_POINT 3
using namespace std;

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void printCompositions(int n, int i)
{
    static int arr[SIZE];
    if(n==0)
        printArray(arr,i);
    else if(n>0)
    {
        for(int k = 1; k<=MAX_POINT; k++)
        {
            arr[i] = k;
            printCompositions(n-k,i+1);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<"Different compositions of 1,2 and 3 of "<<n<<" is"<<endl;
    printCompositions(n,0);
    return 0;
}










