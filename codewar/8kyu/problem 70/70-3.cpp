#include <iostream>
#include <string>
#include <algorithm> // 雖然此版本未使用，但保留是個好習慣
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 從一個給定的字串中，移除所有的空格字元。
 * @param x 原始字串。
 * @return std::string 移除了所有空格的新字串。
 */
std::string no_space(std::string x)
{    
    // 1. 準備一個空字串 temp，用來存放過濾後的結果。
    std::string temp="";
    
    // 2. 使用傳統的 for 迴圈，透過索引 i 遍歷原始字串 x。
    for(int i = 0; i < x.size(); i++){
      // 3. 檢查當前字元 x[i] 是否「不是」空格。
      if(x[i] != ' ')
        // 4. 如果不是空格，就將這個字元加到 temp 字串的末尾。
        temp += x[i];
    }
    
    // 5. 迴圈結束後，回傳建立好的、不含空格的新字串。
    return temp;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param input 要測試的字串。
 */
void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: \"" << no_space(input) << "\"" << endl;
}

// --- 主程式：用來測試 no_space 函式 ---
int main() {
    cout << "--- 移除空格測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("8 j 8   mBliB8g  imjB8B8  jl  B");
    run_test("8 8 Bi fk8h B 8 BB8B B B  B888 c hl8 BhB fd");
    run_test("8aaaaa dddd r     ");

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
