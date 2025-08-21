#include <iostream>
#include <string>
#include <limits> // 用於暫停功能

using namespace std;


bool set_alarm(const bool& employed, const bool& vacation) {
   
    return employed && !vacation;
}

void run_test(bool emp, bool vac) {
    // 使用三元運算子將 bool 值轉為 "true" 或 "false" 字串來顯示
    cout << "輸入: (在職=" << (emp ? "true" : "false") 
         << ", 休假=" << (vac ? "true" : "false") << ")"
         << " -> 輸出: " << (set_alarm(emp, vac) ? "true" : "false") << endl;
}

// --- 主程式：用來測試 set_alarm 函式 ---
int main() {
    cout << "--- 設定鬧鐘測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(true, true);
    run_test(true, false);
    run_test(false, true);
    run_test(false, false);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
