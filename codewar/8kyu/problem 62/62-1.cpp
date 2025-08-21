#include <iostream>
#include <vector>
#include <limits>    // 用於暫停功能

using namespace std;
std::vector<int> countBy(int x, int n) {
    // 1. 準備一個空向量，用來存放結果。
    vector<int> result;

    // 2. 使用 for 迴圈，從 1 執行到 n，總共執行 n 次。
    for (int i = 1; i <= n; ++i) {
        // 3. 在迴圈的每一步，計算 x 的第 i 個倍數 (x * i)，
        //    並將其加入到 result 向量中。
        result.push_back(x * i);
    }

    // 4. 迴圈結束後，回傳建立好的完整向量。
    return result;
}

void run_test(int x, int n) {
    cout << "輸入: (x=" << x << ", n=" << n << ") -> 輸出: [";
    
    vector<int> result = countBy(x, n);
    
    for(size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

// --- 主程式：用來測試 countBy 函式 ---
int main() {
    cout << "--- X 的倍數產生器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(1, 10);
    run_test(2, 5);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
