#include <iostream>
using namespace std;
int main(){
    int a;
    cout<<"請輸入一個數字"<<endl;
    //輸入一個數字
    cin>>a;
    if (a%2==0)
    {
        cout<<a<<"是偶數"<<endl; //如果是偶數則輸出
    }
    else
    {
        cout<<a<<"是奇數"<<endl; //如果是奇數則輸出
    }
    return 0;
}