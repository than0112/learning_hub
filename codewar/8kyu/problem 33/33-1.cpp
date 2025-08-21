#include <iostream>
#include <vector>
#include <numeric>   // 使用 accumulate 函式
#include <limits>    // 用於暫停功能
using namespace std;
int arrayPlusArray(const vector<int>& a, const vector<int>& b) {
    // --- 演算法邏輯 ---
    long sum_a = accumulate(a.begin(), a.end(), 0L);

    // 2. 計算第二個陣列 b 的總和。
    long sum_b = accumulate(b.begin(), b.end(), 0L);

    // 3. 將兩個總和相加後回傳。
    return sum_a + sum_b;
}
void run_test(const vector<int>& arr1, const vector<int>& arr2) {
    cout << "輸入: {";
    for(size_t i = 0; i < arr1.size(); ++i) cout << arr1[i] << (i < arr1.size() - 1 ? "," : "");
    cout << "} + {";
    for(size_t i = 0; i < arr2.size(); ++i) cout << arr2[i] << (i < arr2.size() - 1 ? "," : "");
    cout << "} -> 輸出: " << arrayPlusArray(arr1, arr2) << endl;
}

// --- 主程式：用來測試 arrayPlusArray 函式 ---
int main() {
    cout << "--- 陣列元素總和測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test({1, 2, 3}, {4, 5, 6});       // 預期輸出: 21
    run_test({-1, -2, -3}, {-4, -5, -6}); // 預期輸出: -21
    run_test({0, 0, 0}, {4, 5, 6});       // 預期輸出: 15
    run_test({100, 200, 300}, {400, 500, 600}); // 預期輸出: 2100

    cout << "\n測試結束。\n";

    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
