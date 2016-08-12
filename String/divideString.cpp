#include<bits/stdc++.h>
using namespace std;

void divideString(string *str, int n)
{
    int str_size = str.strlen();

    /* check if string can be divide in equal parts */
    if(str_size % n != 0)
    {
        cout<<" String cant be divided into equal parts!"<<endl;
        return ;
    }

    int part_size = str_size/n;
    for(int i =0; i<n; i++)
    {
        if(part_size % i == 0)
            cout<<endl;
        cout<<str[i];

    }
}

int main()
{
    string *str = "a_simple_divide_string_quest";
    divideString(str,4);
    return 0;
}



