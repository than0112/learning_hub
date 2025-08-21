#include <iostream>
#include <limits>    // 用於暫停功能
#include <iomanip>   // 用於設定輸出精度

using namespace std;

/**
 * @brief 計算一個長方體的體積。
 * @param length 長方體的長度。
 * @param width  長方體的寬度。
 * @param height 長方體的高度。
 * @return double 長方體的體積。
 */
double getVolumeOfCuboid(double length, double width, double height) {
   
    return length * width * height;
}


void run_test(double l, double w, double h) {
    cout << "輸入: (長=" << l << ", 寬=" << w << ", 高=" << h << ")" << endl;
    cout << "輸出體積: " << getVolumeOfCuboid(l, w, h) << endl;
}

// --- 主程式：用來測試 getVolumeOfCuboid 函式 ---
int main() {
    cout << "--- 長方體體積計算器 ---\n";
    
    // 設定輸出的浮點數精度
    cout << fixed << setprecision(2);

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(1, 2, 2);   // 預期輸出: 4.00
    run_test(6.3, 2, 5); // 預期輸出: 63.00

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    double l, w, h;
    cout << "請輸入長、寬、高 (用空格隔開，輸入非數字結束): ";
    while (cin >> l >> w >> h) {
        run_test(l, w, h);
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
