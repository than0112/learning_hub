#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>    // 用於暫停功能

using namespace std;


bool check(const vector<string>& seq, const string& elem) {
    // --- 演算法邏輯 ---
    // 使用 for-each 迴圈，逐一檢查向量中的每一個元素。
    for (const auto& item : seq) {
        // 如果發現有任何一個元素與目標 elem 相等...
        if (item == elem) {
            // ...就立刻回傳 true，並結束函式。
            return true;
        }
    }
    // 如果整個迴圈都跑完了還沒找到，代表不存在，回傳 false。
    return false;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param arr 要測試的向量。
 * @param element 要尋找的元素。
 */
void run_test(const vector<string>& arr, const string& element) {
    cout << "在 { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << "\"" << arr[i] << "\"" << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } 中尋找 \"" << element << "\" -> 輸出: " 
         << (check(arr, element) ? "true" : "false") << endl;
}

// --- 主程式：用來測試 check 函式 ---
int main() {
    cout << "--- 檢查元素是否存在測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test({"what", "a", "great", "kata"}, "kata"); // 預期: true
    run_test({"a", "b", "c"}, "d");                   // 預期: false
    run_test({"e", "f", "g", "h"}, "h");             // 預期: true
    
    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
