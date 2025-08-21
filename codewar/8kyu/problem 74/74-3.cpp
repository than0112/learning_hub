#include <iostream>
#include <vector>
#include <algorithm> // 雖然此版本未使用，但保留是個好習慣
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 計算一個布林值陣列中 true 的數量 (手動迴圈法)。
 * @param arr 一個包含布林值的向量。
 * @return int 陣列中 true 的總數。
 */
int count_sheep(const vector<bool>& arr) 
{
    
    int c = 0;
    for (int i = 0; i < arr.size(); i++){
      // 3. 檢查目前位置 i 上的元素 arr[i] 是否為 true。
      if (arr[i]== true) {
        // 如果是，就將計數器加一。
        c += 1;
      }
    }
    
    // 4. 迴圈結束後，回傳最終的計數結果。
    return c;
}


void run_test(const vector<bool>& sheep_array) {
    cout << "輸入陣列 -> 輸出: " << count_sheep(sheep_array) << endl;
}

// --- 主程式：用來測試 count_sheep 函式 ---
int main() {
    cout << "--- 羊群計數器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    vector<bool> arr = { 
      true,  true,  true,  false,
      true,  true,  true,  true,
      true,  false, true,  false,
      true,  false, false, true,
      true,  true,  true,  true,
      false, false, true,  true 
    };
    run_test(arr); // 預期輸出: 17

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({false, false, false}); // 預期輸出: 0
    run_test({}); // 預期輸出: 0

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
