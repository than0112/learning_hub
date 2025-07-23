//使用輾轉相除法 求兩數之最大公因數
#include <iostream>
using namespace std;
int main(){
    int a,b,temp;
    cout << "請輸入兩個正整數：" << endl;
    cin >> a >> b;
    while(a%b){
        temp = a % b; // 計算餘數
        a = b;        // 更新 a 為 b
        b = temp;    // 更新 b 為餘數
    }
    cout << "最大公因數為：" << b << endl; // 輸出最大公因數
    cout << "最小公倍數為：" << a * b / b << endl;// 輸出最小公倍數
    return 0;
}