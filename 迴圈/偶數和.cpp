#include <iostream>
using namespace std;
int main(){
    int a,b,sum=0;
    cout << "請輸入兩個整數：";
    cin >> a >> b;
    for(int i=a ;i<= b; i++){
        if(!(i % 2)) { // 檢查是否為奇數
            sum += i; 
        }
    }
    //用if寫的話
    //if (a % 2) a++;        
    //if (a % 2) b--; 
    //sum = (a + b) * (b – a + 1) / 2 / 2;
    cout << "從 " << a << " 到 " << b << " 兩數間偶數總和是：" << sum << endl;





    return 0;
}