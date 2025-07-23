//輸入一個正整數n 輸出1加到n的總和
#include <iostream>
using namespace std;
int main() {
    int n,i,sum=0;
    cout << "請輸入一個正整數：";
    cin >> n;

    // 檢查輸入是否為正整數
    if (n <= 0) {
        cout << "請輸入一個正整數！" << endl;
        return 1; // 返回錯誤碼
    }

    // 計算從1到n的總和
    
    for ( i = 1; i <= n; i++) {
        sum += i;
    }
    //使用遞減的方式
    //for ( i = 100; i >0; i--) {
    //    sum += i;
    //}
    //計算從5+10+15+....+100
    //for ( i = 5; i <= 100; i+=5) {sum += i;}
    //初始值 條件式 更新值都可以是算術運算式
    //for(j=y;j<=2*x;j+=y)

    // 輸出結果
    cout << "從1到" << n << "的總和是：" << sum << endl;

    return 0;
}