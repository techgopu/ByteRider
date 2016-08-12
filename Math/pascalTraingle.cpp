// program to print pascal triangle in efficient way

#include<iostream>
using namespace std;

void pascal(int n)
{

    for(int line=1; line<=n; line++)
    {
        // For spaces
        for(int k = 0;k<n-line; k++)
        {
             cout<<" ";
        }
        int c = 1;
        for(int i = 1; i <= line; i++)
        {
            cout<<c;
            c = c*(line-i)/i;
            cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    pascal(n);
    return 0;

}
