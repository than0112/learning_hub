#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 檢查一個指定的元素 elem 是否存在於向量 seq 中。
 * @param seq 要搜尋的字串向量。
 * @param elem 要尋找的目標字串。
 * @return bool 如果找到了則回傳 true，否則回傳 false。
 */
bool check(const vector<string>& seq, const string& elem) {
   
    return find(seq.begin(), seq.end(), elem) != seq.end();
}

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
