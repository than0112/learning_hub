#include <iostream>
#include <vector>
#include <numeric> // 引入 accumulate 函式，方便計算總和

using namespace std;
int find_even_index(const vector<int>& arr) {
    // 1. 初始化右側總和為整個陣列的總和，左側總和為 0。
    //    使用 long long 來避免溢位。
    long long right_sum = accumulate(arr.begin(), arr.end(), 0LL);
    long long left_sum = 0;

    // 2. 遍歷陣列的每一個索引 i。
    for (int i = 0; i < arr.size(); ++i) {
        // a. 在比較之前，先將當前元素從右側總和中扣除。
        //    這樣 right_sum 就代表了 i 右邊所有元素的和。
        right_sum -= arr[i];

        // b. 檢查左側總和是否等於更新後的右側總和。
        if (left_sum == right_sum) {
            return i; // 找到平衡點，回傳索引
        }

        // c. 將當前元素加到左側總和中，為下一次迴圈做準備。
        left_sum += arr[i];
    }

    // 3. 如果整個迴圈都跑完了還沒找到，代表不存在平衡點。
    return -1;
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
