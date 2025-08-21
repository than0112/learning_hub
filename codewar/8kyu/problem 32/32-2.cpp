#include <iostream>
#include <vector>
#include <numeric>   // 雖然此版本未使用，但保留是個好習慣
#include <limits>    // 用於暫停功能
#include <iomanip>   // 用於設定輸出精度

using namespace std;

/**
 * @brief 使用 for 迴圈計算一個數字陣列中所有元素的總和。
 * @param nums 一個包含 double 型別數字的向量。
 * @return double 所有數字的總和。如果陣列為空，則回傳 0。
 */
double sum(const vector<double>& nums) {
    // 1. 準備一個 double 型別的變數，初始值為 0，用來儲存總和。
    double total = 0.0;
  
    // 2. 使用 for-each 迴圈，逐一處理 nums 陣列中的每一個數字。
    for(double number : nums) {
        // 3. 將每一個數字累加到 total 中。
        total += number;
    }
    
    // 4. 迴圈結束後，回傳最終的總和。
    return total;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param arr 要測試的向量。
 */
void run_test(const vector<double>& arr) {
    cout << "輸入: [";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << "] -> 輸出: " << sum(arr) << endl;
}

// --- 主程式：用來測試 sum 函式 ---
int main() {
    cout << "--- 陣列數字總和測試器 ---\n";
    
    // 設定輸出的浮點數精度
    cout << fixed << setprecision(3);

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1, 5.2, 4, 0, -1}); // 預期輸出: 9.2
    run_test({});                // 預期輸出: 0
    run_test({-2.398});          // 預期輸出: -2.398

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
