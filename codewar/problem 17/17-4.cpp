#include <iostream>
#include <vector>
#include <algorithm> // 引入 partial_sort_copy
#include <array>     // 引入 array 來儲存結果
#include <limits>   // 引入 limits 來處理可能的溢位
using namespace std;

long sumTwoSmallestNumbers(const vector<int>& numbers)
{
    // 1. 準備一個大小為 2 的小陣列，用來存放結果。
    //    這就像在桌上準備了兩個「優勝者」的空位。
    array<int, 2> lowest;

    // 2. 呼叫 std::partial_sort_copy。
    //    這個函式的意思是：「請查看 `numbers` 整個向量，找出最小的 2 個元素，
    //    排序後，將它們複製到 `lowest` 陣列中。」
    partial_sort_copy(numbers.begin(), numbers.end(), lowest.begin(), lowest.end());

    // 3. `lowest` 陣列現在包含了最小的兩個數字。
    //    lowest[0] 是最小值，lowest[1] 是次小值。
    //    我們將它們相加並回傳。使用 long 來確保結果不會溢位。
    return static_cast<long>(lowest[0]) + lowest[1];
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param arr 要測試的向量。
 */
void run_test(const vector<int>& arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } -> 輸出: " << sumTwoSmallestNumbers(arr) << endl;
}

// --- 主程式：用來測試 sumTwoSmallestNumbers 函式 ---
int main() {
    cout << "--- 最小兩數之和測試器 (partial_sort_copy 法) ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({19, 5, 42, 2, 77}); // 預期輸出: 7
    
    // 注意：題目範例中的 3453545353453 超出了 int 的範圍，
    // 這裡使用 int 範圍內的大數字來模擬。
    run_test({10, 343445353, 3453445, 3453545}); // 預期輸出: 3453555

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({5, 8, 12, 19, 22}); // 預期輸出: 13

    
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    // cin.ignore() 用來清除可能殘留在輸入緩衝區中的換行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    // cin.get() 會等待使用者按下 Enter 鍵
    cin.get(); 
    return 0;
}
