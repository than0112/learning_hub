#include <iostream>
#include <vector>
#include <numeric>  
#include <limits>    // 用於暫停功能

using namespace std;

int positive_sum (const vector<int>& arr){
    // 1. 準備一個變數，初始值為 0，用來儲存正數的總和。
    int sum = 0;

    // 2. 使用 for-each 迴圈，逐一檢查陣列中的每一個數字。
    for (int number : arr) {
        // 3. 檢查當前數字是否大於 0。
        if (number > 0) {
            // 如果是，就將它累加到 sum 中。
            sum += number;
        }
    }

    // 4. 迴圈結束後，回傳最終的總和。
    return sum;
}


void run_test(const vector<int>& arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } => 輸出: " << positive_sum(arr) << endl;
}
int main() {
    cout << "--- 正數總和測試器 ---\n";
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1, -4, 7, 12}); // 預期輸出: 20

    cout << "\n--- 其他邊界測試 ---\n";
    run_test({}); // 預期輸出: 0
    run_test({-1, -2, -3}); // 預期輸出: 0

    cout << "\n測試結束。\n";
    
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
