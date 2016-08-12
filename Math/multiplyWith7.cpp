/*
program to multiply a number with 7 efficiently
Algo:
    Left shift the number by 3
    subtract the original number from the shifted one
*/

#include<iostream>
using namespace std;
int multiplyWith7(int num)
{
    return ((num<<3) - num);
}
int main()
{
    int num;
    cin>>num;
    cout<<multiplyWith7(num)<<endl;
    return 0;
}
