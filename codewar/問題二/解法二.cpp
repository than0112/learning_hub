#include <iostream>
#include <cmath> // 引入 cmath 函式庫，才能使用 sqrt() 和 fmod() 函式

using namespace std;

/**
 * @brief 使用 fmod 浮點餘數法，判斷一個整數是否為完全平方數。
 * @details 利用 fmod(x, 1.0) 可以取得浮點數 x 的小數部分的特性來判斷。
 * @param n 要檢查的整數。
 * @return bool 如果是完全平方數則回傳 true，否則回傳 false。
 */
bool is_square(int n) {
  
    if (n < 0) {
        return false;
    }

    // 2. 使用 fmod() 檢查平方根的小數部分是否為 0。
    //
    // a. sqrt(n): 計算 n 的平方根，得到一個浮點數 (double)。
    //    例如：sqrt(25) -> 5.0
    //          sqrt(26) -> 5.0990195...
    //
    // b. fmod(value, 1.0): 這是一個數學函式，用來計算浮點數 value 除以 1.0 後的「餘數」。
    //    一個數除以 1 的餘數，其實就是它的小數部分。
    //    例如：fmod(5.0, 1.0) -> 0.0
    //          fmod(5.099, 1.0) -> 0.099...
    //
    // c. 結論：如果一個數的平方根是整數 (例如 5.0)，那麼它的小數部分就是 0。
    //    因此，我們可以透過檢查這個餘數是否為 0 來判斷 n 是否為完全平方數。
    return fmod(sqrt(n), 1.0) == 0;
}


// --- 主程式：用來測試 is_square 函式 ---
int main() {
    cout << "--- 完全平方數判斷器 (fmod 餘數法) ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](int number) {
        cout << "數字 " << number << " 是完全平方數嗎? "
             << (is_square(number) ? "是 (true)" : "否 (false)") << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(-1);
    run_test(0);
    run_test(3);
    run_test(4);
    run_test(25);
    run_test(26);

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個您想測試的整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";
    return 0;
}
