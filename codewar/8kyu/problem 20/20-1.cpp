#include <iostream>
#include<string>
#include<sstream>
#include    <limits>
using namespace std;
string number_to_string(int m){
    return to_string(m);
}
void run_test(int n) {
    cout << "輸入: " << n << " --> 輸出: " << number_to_string(n) << endl;
}
int main() {
    cout << "--- 整數轉字串 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(123);  // 預期輸出: "123"
    run_test(-456); // 預期輸出: "-456"
    run_test(0);    // 預期輸出: "0"

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test(2147483647); // 最大 int 值
    run_test(-2147483648); // 最小 int 值

   
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    // cin.ignore() 用來清除可能殘留在輸入緩衝區中的換行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    // cin.get() 會等待使用者按下 Enter 鍵
    cin.get(); 
    return 0;
}