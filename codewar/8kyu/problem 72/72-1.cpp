#include <iostream>
#include <vector>
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 將一個整數陣列中的每一個數字都加倍。
 * @param values 輸入的整數向量。
 * @return std::vector<int> 一個新的、包含所有加倍後數字的向量。
 */
vector<int> maps(const vector<int> & values) {
    // 1. 準備一個空向量，用來存放結果。
    vector<int> result;
    
    // 2. 使用 for-each 迴圈，逐一處理輸入陣列中的每一個數字。
    for (int value : values) {
        // 3. 將每一個數字乘以 2，並將結果加入到 result 向量中。
        result.push_back(value * 2);
    }
    
    // 4. 迴圈結束後，回傳建立好的完整向量。
    return result;
}


void run_test(const vector<int>& arr) {
    cout << "輸入: [";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    
    vector<int> result = maps(arr);
    
    cout << "] --> 輸出: [";
    for(size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

// --- 主程式：用來測試 maps 函式 ---
int main() {
    cout << "--- 陣列數字加倍測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1, 2, 3}); // 預期輸出: [2, 4, 6]
    run_test({4, 1, 1, 1, 4}); // 預期輸出: [8, 2, 2, 2, 8]

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
