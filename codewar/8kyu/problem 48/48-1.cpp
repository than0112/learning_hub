#include <iostream>
#include <vector>
#include <limits> // 用於暫停功能

using namespace std;
vector<int> divisible_by(vector<int> numbers, int divisor)
{
    // 1. 準備一個空向量，用來存放篩選後的結果。
    vector<int> result;

    // 2. 使用 for-each 迴圈，逐一檢查輸入陣列中的每一個數字。
    for (int number : numbers) {
        // 3. 使用模數運算子 (%) 檢查是否能被整除。
        //    如果一個數字除以 divisor 的餘數為 0，代表它可以被整除。
        if (number % divisor == 0) {
            // 4. 如果可以被整除，就將這個數字加入到 result 向量中。
            result.push_back(number);
        }
    }
    
    // 5. 迴圈結束後，回傳包含所有符合條件數字的 result 向量。
    return result;
}

void run_test(const vector<int>& arr, int div) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " }, " << div << " -> 輸出: { ";
    
    vector<int> result = divisible_by(arr, div);
    
    for(size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << " }" << endl;
}

// --- 主程式：用來測試 divisible_by 函式 ---
int main() {
    cout << "--- 整除篩選器測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1, 2, 3, 4, 5, 6}, 2);
    run_test({1, 2, 3, 4, 5, 6}, 3);
    run_test({0, 1, 2, 3, 4, 5, 6}, 4);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
