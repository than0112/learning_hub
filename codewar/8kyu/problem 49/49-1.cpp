#include <iostream>
#include <vector>
#include <numeric>   
#include <limits>    // 用於暫停功能

using namespace std;
long long grow(const vector<int>& arr)
{
    // 1. 準備一個 long long 型別的變數，初始值為 1，用來儲存乘積。
    //    使用 long long 可以避免因結果過大而產生溢位。
    //    初始值必須是 1，因為任何數乘以 1 都等於它自己。
    long long product = 1;

    // 2. 使用 for-each 迴圈，逐一處理陣列中的每一個數字。
    for (int number : arr) {
        // 3. 將每一個數字乘到 product 中。
        product *= number;
    }

    // 4. 迴圈結束後，回傳最終的乘積。
    return product;
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
