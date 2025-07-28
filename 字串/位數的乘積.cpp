#include <iostream>

using namespace std;

int main() {
    int num_test_cases;

    // 1. 先輸入一個整數，表示資料的組數
    cout << "請輸入資料組數: ";
    cin >> num_test_cases;

    // 2. 根據資料組數，執行對應次數的迴圈
    for (int i = 0; i < num_test_cases; ++i) {
        int number_to_process;
        cout << "\n請輸入第 " << i + 1 << " 組數字: ";
        cin >> number_to_process;

        // --- 將計算邏輯直接寫在這裡 ---

        // 乘積變數，每次處理新數字時都必須重設為 1
        long long product = 1; 

        // 處理特殊情況：如果輸入的數字本身就是 0，結果就是 0
        if (number_to_process == 0) {
            product = 0;
        } else {
            // 建立一個臨時變數來操作，避免修改原始輸入值
            int temp_num = number_to_process; 

            // 當數字還大於 0 時，持續迴圈
            while (temp_num > 0) {
                // 取出個位數
                int digit = temp_num % 10;
                
                // 如果遇到 0，最終乘積必為 0，可以直接跳出迴圈
                if (digit == 0) {
                    product = 0;
                    break; 
                }
                
                // 將個位數乘入總乘積
                product *= digit;

                // 移除已處理過的個位數
                temp_num /= 10;
            }
        }
        
        // 輸出這一輪的計算結果
        cout << "各位數的乘積為: " << product << endl;
    }

    return 0;
}