#include <iostream>
#include <vector>
#include <algorithm> // 引入 sort, min, max 函式
#include <numeric>   // 雖然此版本未使用，但保留是個好習慣

using namespace std;

/**
 * @brief 計算一個整數陣列中，最小的兩個數字的總和 (單次遍歷法)。
 * @details 此方法不排序陣列，而是遍歷一次，動態追蹤最小的兩個數字。
 * @param numbers 一個包含至少4個正整數的向量。
 * @return long 最小的兩個數字的總和。
 */
long sumTwoSmallestNumbers(vector<int> numbers) 
{
    // --- 演算法邏輯 ---

    // 1. 初始化：我們先假設前兩個數字是最小和次小的。
    //    min1 用來儲存當前找到的最小值。
    //    min2 用來儲存當前找到的次小值。
    long min1 = min(numbers[0], numbers[1]);
    long min2 = max(numbers[0], numbers[1]);
    
    // 2. 從第三個數字開始遍歷整個陣列。
    for (size_t i = 2; i < numbers.size(); ++i)
    {
      // 3. 檢查當前數字 numbers[i] 與我們紀錄的關係。
      if (numbers[i] < min1)
      {
        // a. 如果發現一個比當前最小值 min1 還要小的數字：
        //    - 原本的最小值 min1 就變成了次小值 min2。
        //    - 這個新發現的數字就成為新的最小值 min1。
        min2 = min1;
        min1 = numbers[i];
      }
      else if (numbers[i] < min2)
      {
        // b. 如果這個數字介於 min1 和 min2 之間：
        //    - 它就成為新的次小值 min2。
        min2 = numbers[i];
      }
    }
    
    // 4. 迴圈結束後，min1 和 min2 就是整個陣列中最小的兩個數。
    return min1 + min2;
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

