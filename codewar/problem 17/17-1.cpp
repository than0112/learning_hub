#include <iostream>
#include <vector>
#include <algorithm> // 引入 sort 函式
#include <numeric>   // 雖然此版本未使用，但保留是個好習慣

using namespace std;

/**
 * @brief 計算一個整數陣列中，最小的兩個數字的總和。
 * @param numbers 一個包含至少4個正整數的向量。
 * @return long 最小的兩個數字的總和。
 */
long sumTwoSmallestNumbers(vector<int> numbers) 
{
    // --- 演算法邏輯 ---

    // 1. 對陣列進行排序。
    // std::sort 會將 numbers 陣列由小到大重新排列。
    // 例如：[19, 5, 42, 2, 77] -> [2, 5, 19, 42, 77]
    sort(numbers.begin(), numbers.end());

    // 2. 取出最小的兩個數字並相加。
    // 排序後，最小的兩個數字會被放在陣列的最前面，也就是索引 0 和 1 的位置。
    // 我們將它們相加並回傳。使用 long 來儲存結果，以避免兩個較大的 int 相加時可能發生的溢位。
    return (long)numbers[0] + numbers[1];
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param arr 要測試的向量。
 */
void run_test(vector<int> arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } -> 輸出: " << sumTwoSmallestNumbers(arr) << endl;
}

// --- 主程式：用來測試 sumTwoSmallestNumbers 函式 ---
int main() {
    cout << "--- 最小兩數之和測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({19, 5, 42, 2, 77}); // 預期輸出: 7
    
    // 注意：題目範例中的 3453545353453 超出了 int 的範圍，
    // 這裡使用 int 範圍內的大數字來模擬。
    run_test({10, 343445353, 3453445, 3453545}); // 預期輸出: 3453555

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({5, 8, 12, 19, 22}); // 預期輸出: 13

    cout << "\n測試結束。\n";
    return 0;
}

