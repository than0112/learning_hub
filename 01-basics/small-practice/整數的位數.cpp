/*本題是要輸入一個三位數的整數將其各個位數顯示出來例如輸入239會顯示出 2 3 9*/
//輸入三位數的整數
//輸出 使用定位點輸出整數的各個位數
//解題方法
// 千位數=n/1000 百位數=n/100%10 十位數=n/10%10 個位數=n%10
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "請輸入一個三位數的整數：";
    cin >> n;

    // 確保輸入的是三位數
    if (n < 100 || n > 999) {
        cout << "請輸入有效的三位數整數！" << endl;
        return 1; // 返回錯誤碼
    }

    // 計算各位數
    int hundreds = n / 100; // 百位數
    int tens = (n / 10) % 10; // 十位數
    int units = n % 10; // 個位數

    // 輸出結果
    cout << "百位數：" << hundreds << endl;
    cout << "十位數：" << tens << endl;
    cout << "個位數：" << units << endl;

    return 0; // 程式正常結束
}