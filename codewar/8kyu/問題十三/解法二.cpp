#include <iostream>
#include <vector>
#include <numeric> // 引入 accumulate 函式，方便計算總和

using namespace std;

/**
 * @brief 在一個整數陣列中，尋找一個平衡點索引 N，
 * 使得其左側元素的總和等於右側元素的總和 (暴力法)。
 * @details 此方法遍歷每一個可能的索引，並在每一步都重新計算
 * 該索引左側和右側所有元素的總和。
 * @note 效能分析：這個方法的效率較低 (時間複雜度約為 O(N²))，
 * 因為在主迴圈的每一步中，accumulate 都需要再次遍歷部分陣列。
 * 對於小陣列來說是可行的，但對於大陣列，單次遍歷法會快得多。
 * @param arr 輸入的整數向量。
 * @return int 平衡點的索引。如果不存在，則回傳 -1。
 */
int find_even_index(const vector<int>& arr) {
    // 1. 使用 for 迴圈，逐一測試每一個可能的平衡點索引。
    for (int i = 0; i < arr.size(); ++i) {
        
       
        long long left_sum = accumulate(arr.begin(), arr.begin() + i, 0LL);
        long long right_sum = accumulate(arr.begin() + i + 1, arr.end(), 0LL);
        if (left_sum == right_sum) {
            // 如果找到了，立刻回傳當前的索引 i。
            return i;
        }
    }

    // 5. 如果整個迴圈都跑完了還沒找到，代表不存在平衡點。
    return -1;
}


void run_test(const vector<int>& arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } -> 輸出: " << find_even_index(arr) << endl;
}

// --- 主程式：用來測試 find_even_index 函式 ---
int main() {
    cout << "--- 陣列平衡點測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1,2,3,4,3,2,1});      // 預期輸出: 3
    run_test({1,100,50,-51,1,1});   // 預期輸出: 1
    run_test({20,10,-80,10,10,15,35}); // 預期輸出: 0
    run_test({10,-80,10,10,15,35,20}); // 預期輸出: 6
    run_test({1,2,3,4,5,6});         // 預期輸出: -1
    run_test({-1,-2,-3,-4,-3,-2,-1}); // 預期輸出: 3

    cout << "\n測試結束。\n";
    return 0;
}
