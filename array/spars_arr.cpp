#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int q;
    int count;
    cin>>n;

    string str[n];
    string quer;
    for(int i=0;i<n;i++)
        cin>>str[i];
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>quer;
        count=0;
        for(int i=0;i<n; i++)
        {
            if(str[i].compare(quer)== 0)
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
