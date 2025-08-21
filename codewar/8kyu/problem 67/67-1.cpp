#include <iostream>
#include <string>
#include <limits> // 用於暫停功能

using namespace std;
string even_or_odd(int number) {
 
    return (number % 2 == 0) ? "Even" : "Odd";
}
void run_test(int num) {
    cout << "輸入: " << num << " -> 輸出: \"" << even_or_odd(num) << "\"" << endl;
}

// --- 主程式：用來測試 even_or_odd 函式 ---
int main() {
    cout << "--- 奇偶數判斷器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(2);    // 預期: Even
    run_test(7);    // 預期: Odd
    run_test(-42);  // 預期: Even
    run_test(-7);   // 預期: Odd
    run_test(0);    // 預期: Even

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個您想測試的整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
