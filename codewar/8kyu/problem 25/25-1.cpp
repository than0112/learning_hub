#include <iostream>
#include <limits> // 用於暫停功能

using namespace std;

/**
 * @brief 計算櫻花花瓣以指定速度 v 掉落所需的時間。
 * @param v 花瓣的掉落速度 (cm/s)。
 * @return double 掉落所需的時間 (秒)。如果速度為非正數，則回傳 0。
 */
double SakuraFall(double v) {
    // --- 演算法邏輯 ---

    // 1. 處理邊界情況：如果速度為非正數，無法計算時間，回傳 0。
    if (v <= 0) {
        return 0.0;
    }

    // 2. 根據題目給的基準案例，計算出固定的距離 (樹枝高度)。
    //    距離 = 速度 × 時間 = 5 cm/s * 80 s = 400 cm。
    const double distance = 400.0;

    // 3. 計算並回傳新的時間。
    //    時間 = 距離 / 速度
    return distance / v;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param speed 要測試的速度。
 */
void run_test(double speed) {
    cout << "輸入速度: " << speed << " cm/s -> 輸出時間: " << SakuraFall(speed) << " 秒" << endl;
}

// --- 主程式：用來測試 SakuraFall 函式 ---
int main() {
    cout << "--- 櫻花落下時間計算器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(5);  // 基準案例，預期輸出: 80
    run_test(10); // 速度加倍，時間減半，預期輸出: 40
    run_test(0);  // 邊界情況，預期輸出: 0
    run_test(-5); // 邊界情況，預期輸出: 0

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    double user_input;
    cout << "請輸入一個您想測試的速度 (cm/s) (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的速度 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}

