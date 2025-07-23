#include <iostream>
using namespace std;
int main(){
    int a,b,c,max,min;
    cout<<"請輸入三個整數 分別為a,b,c"<<endl;
    cin>>a>>b>>c;
    if(a<b &&a<c){
        min=a; //如果a小於b和c則a是最小值
    }
    else if(b<c){
        min=b; //如果b小於a和c則b是最小值
    }
    else{
        min=c; //否則c是最小值
    }
    if(a>b &&a>c){
        max=a; //如果a大於b和c則a是最大值
    }
    else if(b>c){
        max=b; //如果b大於a和c則b是最大值
    }
    else{
        max=c; //否則c是最大值
    }
    cout<<"最大值為"<<max<<endl; //輸出最大值
    cout<<"最小值為"<<min<<endl; //輸出最小值
return 0;
}