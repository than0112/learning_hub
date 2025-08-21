#include <iostream>
#include <cmath>   // 引入 cmath 函式庫，才能使用 abs() 函式
#include <limits>  // 用於暫停功能

using namespace std;

/**
 * @brief 計算在多少年前/後，父親的年齡是兒子的兩倍。
 * @param dad 父親目前的年齡。
 * @param son 兒子目前的年齡。
 * @return int 所需的年數 (永遠為正數或零)。
 */
int twice_as_old(int dad, int son) {
    // --- 演算法邏輯 ---
    // 1. 計算出兒子年齡的兩倍。
    int son_age_doubled = son * 2;


    int difference = dad - son_age_doubled;

   
    return abs(difference);
}

void run_test(int dad_age, int son_age) {
    cout << "輸入: (父親 " << dad_age << " 歲, 兒子 " << son_age << " 歲) -> 輸出: " 
         << twice_as_old(dad_age, son_age) << " 年" << endl;
}

// --- 主程式：用來測試 twice_as_old 函式 ---
int main() {
    cout << "--- 父子年齡問題測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(36, 7);  // 預期輸出: 22 (未來)
    run_test(55, 30); // 預期輸出: 5 (過去)
    run_test(42, 21); // 預期輸出: 0 (現在)
    run_test(22, 1);  // 預期輸出: 20 (未來)
    run_test(29, 0);  // 預期輸出: 29 (未來)

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int dad, son;
    cout << "請輸入父親和兒子的年齡 (用空格隔開，輸入非數字結束): ";
    while (cin >> dad >> son) {
        run_test(dad, son);
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
