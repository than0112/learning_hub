#include <iostream>
#include <cmath>     
#include <limits>    

using namespace std;


int cockroach_speed(double s)
{
    // --- 演算法邏輯 ---
    // 1. 單位換算常數：
    //    - 1 公里/小時 = 100000 公分 / 3600 秒 ≈ 27.778 公分/秒
    const double CONVERSION_FACTOR = 100000.0 / 3600.0;

    // 2. 計算轉換後的速度 (結果為浮點數)。
    double speed_in_cm_per_second = s * CONVERSION_FACTOR;

    // 3. 將浮點數結果轉換為整數。
    //    在 C++ 中，將 double 直接指派或轉換為 int，會自動捨去小數部分，
    //    這對於正數來說，效果等同於 floor()。
    return (int)speed_in_cm_per_second;
}


void run_test(double speed) {
    cout << "輸入: " << speed << " km/h -> 輸出: " << cockroach_speed(speed) << " cm/s" << endl;
}

// --- 主程式：用來測試 cockroach_speed 函式 ---
int main() {
    cout << "--- 蟑螂速度轉換器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(1.08); // 預期輸出: 30
    run_test(1.09); // 預期輸出: 30
    run_test(0);    // 預期輸出: 0

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    double user_input;
    cout << "請輸入一個您想測試的速度 (km/h) (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請繼續輸入 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
