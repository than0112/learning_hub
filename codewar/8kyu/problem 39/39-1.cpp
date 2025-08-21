#include <iostream>
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 計算從午夜到指定時間 (h, m, s) 總共經過了多少毫秒。
 * @param h 小時 (0-23)。
 * @param m 分鐘 (0-59)。
 * @param s 秒 (0-59)。
 * @return int 總共的毫秒數。
 */
int past(int h, int m, int s) {
  
    return h * 3600000 + m * 60000 + s * 1000;
}


void run_test(int hours, int minutes, int seconds) {
    cout << "輸入: (" << hours << "h, " << minutes << "m, " << seconds << "s) -> 輸出: " 
         << past(hours, minutes, seconds) << "ms" << endl;
}

// --- 主程式：用來測試 past 函式 ---
int main() {
    cout << "--- 午夜後的毫秒數計算器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(0, 1, 1);  // 預期輸出: 61000
    run_test(1, 1, 1);  // 預期輸出: 3661000
    run_test(0, 0, 0);  // 預期輸出: 0
    run_test(1, 0, 1);  // 預期輸出: 3601000

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
