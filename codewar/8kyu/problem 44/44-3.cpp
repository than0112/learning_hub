#include <iostream>
#include <string>
#include <limits>    // 用於暫停功能
#include <algorithm> // 雖然此版本未使用，但保留是個好習慣

using namespace std;

/**
 * @brief 校正一個因文字辨識錯誤而產生的字串 (for 迴圈與 switch 法)。
 * @details 規則：'5' -> 'S', '0' -> 'O', '1' -> 'I'
 * @param str 包含錯誤字元的原始字串。
 * @return std::string 校正後的新字串。
 */
string correct(string str) {
    // 使用傳統的 for 迴圈，透過索引 i 遍歷字串中的每一個字元。
    for(size_t i=0; i<str.size(); i++)
    {
      // 使用 switch 判斷式檢查當前的字元 str[i]。
      switch (str[i])
      {
        // 如果是 '1'，就地替換為 'I'。
        case '1': str[i]='I'; break; 
        // 如果是 '0'，就地替換為 'O'。
        case '0': str[i]='O'; break; 
        // 如果是 '5'，就地替換為 'S'。
        case '5': str[i]='S'; break; 
      }
    }
    // 回傳已經被完整修改過的字串。
    return str;
}
void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: \"" << correct(input) << "\"" << endl;
}

// --- 主程式：用來測試 correct 函式 ---
int main() {
    cout << "--- 文字辨識校正器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("L0ND0N");      // 預期輸出: "LONDON"
    run_test("DUBL1N");      // 預期輸出: "DUBLIN"
    run_test("51NGAP0RE");   // 預期輸出: "SINGAPORE"
    run_test("BUDAPE5T");   // 預期輸出: "BUDAPEST"
    run_test("PAR15");       // 預期輸出: "PARIS"

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
