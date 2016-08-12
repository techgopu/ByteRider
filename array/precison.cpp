#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    int n;
    int neg=0, pos=0,zero=0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
            neg++;
        else if(arr[i]>0)
            pos++;
        else
            zero++;
    }
    float n2 = (n*10)/10.0;
    cout<<setprecision(6)<<pos/n2<<endl;
    cout<<setprecision(6)<<neg/n2<<endl;
    cout<<setprecision(6)<<zero/n2<<endl;
    return 0;
}
