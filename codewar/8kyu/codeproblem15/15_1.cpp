#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <limits>    // 引入 numeric_limits

using namespace std;

// 建立一個靜態的、常數的 map 作為「單字-數值」的對照表。
// static const 確保這個 map 只會在程式首次執行時建立一次，效能極高。
static const unordered_map<string, long> WORD_TO_VALUE = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
    {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
    {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
    {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
    {"eighty", 80}, {"ninety", 90}, {"hundred", 100},
    {"thousand", 1000}, {"million", 1000000}
};

/**
 * @brief 將用英文單字表示的數字字串，轉換為 long 型別的整數。
 * @param number_str 英文數字字串。
 * @return long 轉換後的整數值。
 */
long parse_int(string number_str) {
    // --- 演算法邏輯 ---

    // 1. 預處理字串：將所有 '-' 替換為 ' '，方便後續拆解。
    for (char &c : number_str) {
        if (c == '-') c = ' ';
    }

    // 2. 使用 stringstream 來拆解單字。
    stringstream ss(number_str);
    string word;
    vector<string> tokens;
    while (ss >> word) {
        // 忽略可選的 "and"
        if (word != "and") {
            tokens.push_back(word);
        }
    }

    // 3. 核心解析邏輯
    long total_result = 0;
    long current_chunk_result = 0;

    for (const string& token : tokens) {
        long value = WORD_TO_VALUE.at(token);

        if (value == 100) {
            // 如果遇到 "hundred"，將當前區塊的結果乘以 100。
            // 例如 "two hundred" -> current_chunk_result (2) * 100 = 200
            current_chunk_result *= 100;
        } else if (value >= 1000) {
            // 如果遇到 "thousand" 或 "million"，代表一個大區塊的結束。
            // 1. 將當前區塊的結果乘以這個大單位 (1000 或 1000000)。
            // 2. 將其加到總結果中。
            // 3. 重設當前區塊結果為 0，準備處理下一個區塊。
            total_result += current_chunk_result * value;
            current_chunk_result = 0;
        } else {
            // 如果是普通的數字 (0-99)，直接加到當前區塊的結果中。
            current_chunk_result += value;
        }
    }

    // 4. 將最後一個區塊的結果 (千位數以下的部分) 加到總結果中。
    total_result += current_chunk_result;

    return total_result;
}

void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: " << parse_int(input) << endl;
}

// --- 主程式：用來測試 parse_int 函式 ---
int main() {
    cout << "--- 英文數字解析器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("one"); // 1
    run_test("twenty"); // 20
    run_test("two hundred forty-six"); // 246
    run_test("seven hundred eighty-three thousand nine hundred and nineteen"); // 783919
    run_test("one million"); // 1000000
    run_test("twenty-one"); // 21
     cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    // cin.ignore() 用來清除可能殘留在輸入緩衝區中的換行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    // cin.get() 會等待使用者按下 Enter 鍵
    cin.get(); 
    cout << "\n測試結束。\n";
    return 0;
}
