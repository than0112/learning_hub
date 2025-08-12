#include <iostream>
#include <string>
#include <algorithm> // 引入 reverse 函式

using namespace std;

string add(const string& a, const string& b) {
    // --- 演算法邏輯：模擬直式加法 ---
    
    string result = "";
    int i = a.length() - 1; // a 的指針，從最右邊開始
    int j = b.length() - 1; // b 的指針，從最右邊開始
    int carry = 0;          // 進位，初始為 0

    // 迴圈會一直執行，直到兩個數字的所有位數都被處理完，且沒有進位為止
    while (i >= 0 || j >= 0 || carry) {
        // 1. 計算當前位的總和
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0'; // 取得 a 的當前位數，並將指針左移
        }
        if (j >= 0) {
            sum += b[j--] - '0'; // 取得 b 的當前位數，並將指針左移
        }

        // 2. 處理進位
        carry = sum / 10; // 新的進位是總和除以 10 的商
        
        // 3. 取得當前位的數字，並加到結果字串的前端
        // 總和除以 10 的餘數就是當前位的數字
        result += to_string(sum % 10);
    }

    // 4. 反轉結果
    // 因為我們是從個位數開始，將結果加到字串的末尾，
    // 所以最終得到的字串順序是反的 (例如 444 -> "444")，需要反轉回來。
    reverse(result.begin(), result.end());

    return result;
}
void run_test(const string& num1, const string& num2) {
    cout << "輸入: \"" << num1 << "\" + \"" << num2 << "\"" << endl;
    cout << "輸出: \"" << add(num1, num2) << "\"" << endl;
}

// --- 主程式：用來測試 add 函式 ---
int main() {
    cout << "--- 大數加法測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("123", "321"); // 預期輸出: "444"
    run_test("11", "99");   // 預期輸出: "110"

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test("999", "1");   // 預期輸出: "1000"
    run_test("1", "9999");  // 預期輸出: "10000"

    cout << "\n測試結束。\n";
    return 0;
}

