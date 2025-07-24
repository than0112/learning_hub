/*猜數字遊戲
隨機設定某一整數為答案讓使用者輸入猜想的數字若輸入值大於答案 提示輸入值太大若小於答案提示輸入值太小
直到輸入值等於答案 提示猜對了並結束遊戲
*/
#include <iostream>
using namespace std;
int main(){
    int i,sum=0,ans=15;
    while(1){
        cout<<"請輸入一個整數"<<endl;
        cin>>i;
        sum++;
        if(i==ans){
        cout<<"猜對了"<<endl;
            break;
    }
    else if(i>ans){
        cout<<"數值太大 請在輸入一次"<<endl;
    }
    else {
        cout<<"數值太小 請在輸入一次"<<endl;
    }
    }
    cout<<"共猜了"<<i<<"次"<<endl;
    return 0;
}
