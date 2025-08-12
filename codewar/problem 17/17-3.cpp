#include <iostream>
#include <vector>
#include <algorithm> // 引入 nth_element
#include <numeric>   // 雖然此版本未使用，但保留是個好習慣
#include <string>    // 引入 string 以處理使用者輸入
#include <sstream>   // 引入 stringstream 以解析使用者輸入

using namespace std;

/**
 * @brief 計算一個整數陣列中，最小的兩個數字的總和 (nth_element 部分排序法)。
 * @details 此方法使用 C++ STL 中的 std::nth_element 演算法，
 * 這是一種比完整排序更高效的方法，因為它只對陣列進行部分排序。
 * @param numbers 一個包含至少4個正整數的向量。
 * @return long 最小的兩個數字的總和。
 */
long sumTwoSmallestNumbers(vector<int> numbers) 
{
    // --- 演算法邏輯 ---

    // 1. 使用 std::nth_element 進行部分排序。
    // 這行程式碼的目標是：將整個陣列中「第二小」的元素，
    // 準確地放到它如果被完整排序後應該在的位置（也就是索引 1）。
    //
    // std::nth_element(起始點, 目標位置, 結束點);
    //
    // 執行完畢後，C++ 標準保證：
    // a. 索引 1 的位置上，確實是整個陣列中第二小的元素。
    // b. 索引 1 左邊的所有元素 (也就是索引 0)，都小於或等於索引 1 的元素。
    //
    // 綜合 a 和 b，我們就成功地在陣列的前兩個位置 numbers[0] 和 numbers[1]
    // 篩選出了最小的兩個數字，而不需要對整個陣列進行完整排序。
    nth_element(numbers.begin(), numbers.begin() + 1, numbers.end());

    // 2. 取出最小的兩個數字並相加。
    // 現在，numbers[0] 和 numbers[1] 就是我們要找的兩個數。
    return (long)numbers[0] + numbers[1];
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param arr 要測試的向量。
 */
void run_test(vector<int> arr) {
    if (arr.size() < 2) {
        cout << "輸入錯誤：陣列至少需要包含兩個數字。\n";
        return;
    }
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

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string line;
    cout << "請輸入一排用空格隔開的數字 (例如 19 5 42 2 77)，輸入 'q' 結束: ";
    
    while (getline(cin, line) && line != "q") {
        vector<int> user_numbers;
        stringstream ss(line);
        int number;
        while (ss >> number) {
            user_numbers.push_back(number);
        }
        
        run_test(user_numbers);
        cout << "\n請繼續輸入 (輸入 'q' 結束): ";
    }

    cout << "\n測試結束。\n";
    return 0;
}
