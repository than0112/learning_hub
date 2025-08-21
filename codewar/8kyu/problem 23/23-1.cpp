#include <iostream>
#include <limits> // 用於暫停功能

using namespace std;

/**
 * @brief 根據給定的年份，回傳其所在的世紀。
 * @param year 一個正整數年份。
 * @return int 該年份所在的世紀。
 */
int centuryFromYear(int year) 
{
    // --- 演算法邏輯 ---
    // 這是一個處理世紀問題的經典數學技巧，可以優雅地處理邊界情況。
    //
    // 1. (year - 1): 先將年份減 1。
    //    - 對於非整百的年份 (如 1705)，變成 1704。
    //    - 對於整百的年份 (如 1900)，變成 1899。
    //
    // 2. / 100: 接著做整數除法。
    //    - 1704 / 100 = 17
    //    - 1899 / 100 = 18
    //
    // 3. + 1: 最後將結果加 1。
    //    - 17 + 1 = 18 (第18世紀)
    //    - 18 + 1 = 19 (第19世紀)
    //
    // 這個方法巧妙地將所有年份的計算統一成一個公式。
    return (year - 1) / 100 + 1;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param year 要測試的年份。
 */
void run_test(int year) {
    cout << "輸入: " << year << " --> 輸出: " << centuryFromYear(year) << endl;
}

// --- 主程式：用來測試 centuryFromYear 函式 ---
int main() {
    cout << "--- 世紀計算器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(1705); // 預期輸出: 18
    run_test(1900); // 預期輸出: 19
    run_test(1601); // 預期輸出: 17
    run_test(2000); // 預期輸出: 20
    run_test(2742); // 預期輸出: 28

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個您想測試的年份 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的年份 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
