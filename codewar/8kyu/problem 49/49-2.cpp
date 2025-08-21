#include <iostream>
#include <vector>
#include <numeric>  
#include <functional>
#include <limits>    // 用於暫停功能
using namespace std;
long long grow(const vector<int>& arr)
{
    /* 使用accumulate 演算法來計算乘積。
     - arr.cbegin(), arr.cend(): 指定要計算的範圍是整個陣列。
     - 1LL: 這是初始值。使用 1LL (long long 型別的 1) 來確保整個計算過程
            都使用 long long，避免溢位。
     - multiplies<long long>(): 指定運算規則為「乘法」。
    return std::accumulate(arr.cbegin(), arr.cend(), 1LL, std::multiplies<long long>());*/
}

void run_test(const vector<int>& arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } => 輸出: " << grow(arr) << endl;
}

// --- 主程式：用來測試 grow 函式 ---
int main() {
    cout << "--- 陣列乘積測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1, 2, 3, 4}); // 預期輸出: 24
    run_test({4, 1, 1, 1, 4}); // 預期輸出: 16
    run_test({2, 2, 2, 2, 2, 2}); // 預期輸出: 64

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
