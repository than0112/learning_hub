#include <iostream>
#include <cmath> // 引入 cmath 函式庫，才能使用 sqrt() 函式

using namespace std;

/**
 * @brief 判斷一個整數是否為完全平方數。
 * @param n 要檢查的整數。
 * @return bool 如果是完全平方數則回傳 true，否則回傳 false。
 */
bool is_square(int n) {
    // --- 演算法邏輯 ---

    // 1. 處理負數的邊界情況。
    // 任何整數的平方都不會是負數，所以負數不可能是完全平方數。
    if (n < 0) {
        return false;
    }

    // 2. 計算平方根並檢查。
    // a. 使用 sqrt() 計算 n 的平方根，結果會是一個浮點數 (double)。
    // b. 使用 round() 將浮點數結果四捨五入到最接近的整數。
    //    這一步是為了處理浮點數可能的微小誤差，比直接轉換成 int 更穩健。
    //    使用 long long 來儲存 root，可以避免在下一步平方時發生溢位。
    long long root = round(sqrt(n));

    // c. 檢查這個整數的平方是否剛好等於原始的數字 n。
    //    如果是，代表 n 的平方根是一個整數，n 就是完全平方數。
    return root * root == n;
}

// --- 主程式：用來測試 is_square 函式 ---
int main() {
    cout << "--- 完全平方數判斷器 ---\n";

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
