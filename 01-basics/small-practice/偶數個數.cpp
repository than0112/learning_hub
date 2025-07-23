//能從某一範圍的連續整數中算出偶數的個數0 也是偶數 
//輸入 兩個由空白隔開的整數a,b(a<=b)
//輸出整數a,b之間(含a,b)的偶數個數

#include <iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"請輸入兩個由空白隔開的整數(a<=b):"<<endl;
    //輸入兩個整數
    cin>>a>>b;
    if (a%2)
    {
        a++; //如果a是奇數則加一
    }
    if (b % 2)
    {
        b--; //如果b是奇數則減一
    }
    //計算偶數個數
    cout<< "偶數個數為：" << (b - a) / 2 + 1 <<"個"<< endl;
    return 0;
}



