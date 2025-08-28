#include <iostream>
#include <vector>
#include <numeric>  
#include <limits>    

using namespace std;
vector<int> countPositivesSumNegatives(vector<int> input)
{
    
    if (input.empty()) {
        return {};
    }
    // 2. 準備兩個變數來分別儲存結果。
    int positives_count = 0;
    int negatives_sum = 0;
    for (int number : input) {
        if (number > 0) {
    
            positives_count++;
        } else if (number < 0) {
            negatives_sum += number;
        }
      
    }
    return {positives_count, negatives_sum};
}

void run_test(const vector<int>& arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    
    vector<int> result = countPositivesSumNegatives(arr);
    
    cout << " } -> 輸出: { ";
    for(size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << " }" << endl;
}

// --- 主程式：用來測試 countPositivesSumNegatives 函式 ---
int main() {
    cout << "--- 計數正數，加總負數測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15});

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({0, 2, 3, 0, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14});
    run_test({}); // 測試空陣列

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
