#include <iostream>
#include <string>
#include <cmath>     // 引入 cmath 以使用 pow() 函式
#include <limits>    // 用於暫停功能
#include <iomanip>   // 用於設定輸出精度

using namespace std;

/**
 * @brief 根據體重和身高計算 BMI 指數，並回傳對應的健康狀況。
 * @param weight 體重 (公斤)。
 * @param height 身高 (公尺)。
 * @return std::string BMI 對應的健康狀況字串。
 */
string bmi(double weight, double height) {
    // 1. 計算 BMI 指數。
    //    公式：bmi = 體重 / (身高^2)
    double bmi_value = weight / pow(height, 2);

    // 2. 使用一系列的 if-else if 判斷式來回傳對應的健康狀況。
    if (bmi_value <= 18.5) {
        return "Underweight";
    } else if (bmi_value <= 25.0) {
        return "Normal";
    } else if (bmi_value <= 30.0) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param w 體重。
 * @param h 身高。
 */
void run_test(double w, double h) {
    cout << "輸入: (體重=" << w << "kg, 身高=" << h << "m) -> 輸出: \""
         << bmi(w, h) << "\"" << endl;
}

// --- 主程式：用來測試 bmi 函式 ---
int main() {
    cout << "--- BMI 健康狀況計算器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(50, 1.80);  // 預期: Underweight
    run_test(80, 1.80);  // 預期: Normal
    run_test(90, 1.80);  // 預期: Overweight
    run_test(110, 1.80); // 預期: Obese
    run_test(81.65, 1.8); // 剛好 25.2 -> Overweight

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
