#include <iostream>
#include <string>
#include <vector>
#include <array>     
#include <limits>    // 用於暫停功能

using namespace std;
int points(const array<string, 10>& games) {
    // 1. 準備一個變數，初始值為 0，用來儲存總積分。
    int total_points = 0;

    // 2. 使用 for-each 迴圈，逐一處理每一場比賽的結果。
    for (const string& game : games) {
        // a. 從 "x:y" 格式的字串中，解析出我方和我方的得分。
        //    - game[0] 是我方的得分 (字元 'x')。
        //    - game[2] 是對方的得分 (字元 'y')。
   
        int our_score = game[0] - '0';
        int opponent_score = game[2] - '0';

        // b. 根據比賽規則計算積分。
        if (our_score > opponent_score) {
            // 如果獲勝，加 3 分。
            total_points += 3;
        } else if (our_score == opponent_score) {
            // 如果平手，加 1 分。
            total_points += 1;
        }
        // 如果輸了 (our_score < opponent_score)，則不加分。
    }

    // 3. 迴圈結束後，回傳最終的總積分。
    return total_points;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param games_array 要測試的比賽結果陣列。
 */
void run_test(const array<string, 10>& games_array) {
    cout << "輸入: [";
    for(size_t i = 0; i < games_array.size(); ++i) {
        cout << "\"" << games_array[i] << "\"" << (i < games_array.size() - 1 ? ", " : "");
    }
    cout << "] -> 輸出: " << points(games_array) << endl;
}

// --- 主程式：用來測試 points 函式 ---
int main() {
    cout << "--- 聯賽積分計算器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    array<string, 10> games = {"1:0","2:0","3:0","4:0","2:1","3:1","4:1","3:2","4:2","4:3"};
    run_test(games); // 預期輸出: 30

    array<string, 10> games2 = {"1:1","2:2","3:3","4:4","2:2","3:3","4:4","3:3","4:4","4:4"};
    run_test(games2); // 預期輸出: 10

    array<string, 10> games3 = {"0:1","0:2","0:3","0:4","1:2","1:3","1:4","2:3","2:4","3:4"};
    run_test(games3); // 預期輸出: 0
    
    array<string, 10> games4 = {"1:0","2:0","3:0","4:4","2:2","3:3","1:4","2:3","2:4","3:4"};
    run_test(games4); // 預期輸出: 12

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
