#include <iostream>
#include<cmath>
using namespace std;
double powerOfSelf(double base) {
    // 使用 cmath 函式庫中的 pow(基底, 指數) 函數
    // 在這裡，基底和指數都是同一個數 base
    return pow(base, base);
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"值為"<<pow(a,b)<<endl;
    cout<<"值為"<<pow(b,c)<<endl;
    cout<<"值為"<<pow(b,c)<<endl;
    cout<<"值為"<<powerOfSelf(a)<<endl;
    cout<<"值為"<<powerOfSelf(b)<<endl;
    cout<<"值為"<<powerOfSelf(c)<<endl;
    return 0;
}