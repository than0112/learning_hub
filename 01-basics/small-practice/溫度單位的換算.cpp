#include <iostream>
#include <iomanip> // 引入 iomanip 以使用 setprecision
using namespace std;
int main (){
    int a,b,c;
    cin>>a;
    b=9/5*a+32; //華氏溫度=攝氏溫度*9/5+32
    cout<<"華氏溫度是"<<fixed<<setprecision(2)<<b<<endl;
    
    // fixed 用於確保輸出為固定小數點格式
    return 0;
    // fixed 用於確保輸出為固定小數點格式
}