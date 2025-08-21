#include <iostream>
#include <limits>    // 用於暫停功能

using namespace std;


int summation(int num){
   
    return num * (num + 1) / 2;
}

void run_test(int number) {
    cout << "輸入: " << number << " -> 輸出: " << summation(number) << endl;
}

// --- 主程式：用來測試 summation 函式 ---
int main() {
    cout << "--- 連加總和測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(2); // 預期輸出: 3
    run_test(8); // 預期輸出: 36
    run_test(1); // 預期輸出: 1

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個您想測試的正整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的正整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
