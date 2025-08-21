#include <iostream>
#include <vector>
#include <numeric>   
#include <limits>    // 用於暫停功能

using namespace std;
std::vector<int> MonkeyCount(int n) {
    // 1. 準備一個空向量，用來存放結果。
    vector<int> result;

    // 2. 使用 for 迴圈，從 1 開始，一直數到 n。
    for (int i = 1; i <= n; ++i) {
        // 3. 將每一個數字 i 加入到 result 向量中。
        result.push_back(i);
    }

    // 4. 迴圈結束後，回傳建立好的完整向量。
    return result;
}

void run_test(int n) {
    cout << "輸入: " << n << " --> 輸出: [";
    
    vector<int> result = MonkeyCount(n);
    
    for(size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

// --- 主程式：用來測試 MonkeyCount 函式 ---
int main() {
    cout << "--- 猴子計數測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(10);
    run_test(1);
    run_test(5);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
