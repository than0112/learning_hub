#include <iostream>
#include <vector>
#include <numeric>  
#include <limits>    // 用於暫停功能
#include <iomanip>   // 用於設定輸出精度

using namespace std;
double calcAverage_loop(const vector<int>& values){
    if (values.empty()) {
        return 0.0;
    }

    // 1. 準備一個 long long 型別的變數，初始值為 0，用來儲存總和。
    long long sum = 0;
    
    // 2. 使用 for-each 迴圈，逐一處理陣列中的每一個數字。
    for (int value : values) {
        // 3. 將每一個數字累加到 sum 中。
        sum += value;
    }
    
    // 4. 計算平均值並回傳。
    return static_cast<double>(sum) / values.size();
}
void run_test(const vector<int>& arr) {
    cout << "輸入: [";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    
    cout << "  -> 迴圈法輸出: " << calcAverage_loop(arr) << endl;
}


int main() {
    cout << "--- 陣列平均值計算器 ---\n";

    // 設定輸出的浮點數精度
    cout << fixed << setprecision(2);

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test({1, 2, 3, 4, 5}); // 預期輸出: 3.00
    run_test({10, 20, 30, 40}); // 預期輸出: 25.00
    run_test({});              // 預期輸出: 0.00

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
