#include <iostream>
#include <string>
#include <sstream>   // 引入 stringstream，用於輕鬆拆解字串
#include <algorithm> // 引入 min 函式
#include <limits>    // 引入 numeric_limits

using namespace std;

/**
 * @brief 在一個字串中，找出最短單字的長度。
 * @param str 輸入的字串，由一或多個單字組成。
 * @return int 最短單字的長度。
 */
int find_short(string str)
{
    // --- 演算法邏輯 ---

    // 1. 建立一個 stringstream 物件來掃描輸入的句子。
    stringstream ss(str);
    string word; // 用來暫時存放掃描到的每一個單字。

    // 2. 初始化一個變數來記錄目前找到的最短長度。
    //    我們先將它設為一個非常大的數，確保第一個單字的長度一定會比它小。
    int shortest_length = numeric_limits<int>::max();

    // 3. 使用 while 迴圈逐一讀取每個單字。
    while (ss >> word) {
        // a. 取得當前單字的長度。
        int current_length = word.length();
        
        // b. 比較當前長度和紀錄中的最短長度，並更新紀錄。
        //    std::min 會回傳兩個數中較小的那一個。
        shortest_length = min(shortest_length, current_length);
    }

    // 4. 迴圈結束後，shortest_length 就是最終的答案。
    return shortest_length;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param sentence 要測試的句子。
 */
void run_test(const string& sentence) {
    cout << "輸入: \"" << sentence << "\" -> 輸出: " << find_short(sentence) << endl;
}

// --- 主程式：用來測試 find_short 函式 ---
int main() {
    cout << "--- 最短單字長度計算器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("bitcoin take over the world maybe who knows perhaps");
    run_test("turns out random test cases are easier than writing out basic ones");
    run_test("lets talk about javascript the best language");
    
    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個英文句子 (輸入 'q' 結束): ";
    while (getline(cin, user_input) && user_input != "q") {
        run_test(user_input);
        cout << "\n請繼續輸入 (輸入 'q' 結束): ";
    }

    cout << "\n測試結束。\n";
    return 0;
}
