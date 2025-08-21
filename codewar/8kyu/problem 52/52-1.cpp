#include <iostream>
#include <vector>
#include <numeric>   
#include <limits>    // 用於暫停功能

using namespace std;
int square_sum(const vector<int>& numbers)
{
    // 1. 準備一個變數，初始值為 0，用來儲存總和。
    int sum = 0;

    // 2. 使用 for-each 迴圈，逐一處理陣列中的每一個數字。
    for (int number : numbers) {
        // 3. 將每一個數字平方 (number * number)，然後累加到 sum 中。
        sum += (number * number);
    }

    // 4. 迴圈結束後，回傳最終的總和。
    return sum;
}


void run_test(const vector<int>& arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } -> 輸出: " << square_sum(arr) << endl;
}

// --- 主程式：用來測試 square_sum 函式 ---
int main() {
    cout << "--- 平方和測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1, 2, 2}); // 預期輸出: 9
    run_test({0, 3, 4, 5}); // 預期輸出: 50

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
