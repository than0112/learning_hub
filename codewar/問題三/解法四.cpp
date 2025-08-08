#include <iostream>
#include <string>
#include <map> 

using namespace std;

/**
 * @brief 產生一條 DNA 鏈的互補鏈。
 * @details 使用 map 作為查詢表，將每個鹼基替換為其互補鹼基。
 * @param dna 原始的 DNA 字串。
 * @return string 互補的 DNA 字串。
 */
string DNAStrand(string dna) // 注意：這裡接收一個複本 (copy)，而非參考
{
    // 使用map 來建立鹼基對應表。
    static const map<char, char> complement_map = {
        {'A', 'T'},
        {'T', 'A'},
        {'C', 'G'},
        {'G', 'C'}
    };

    // 使用 for-each 迴圈，逐一處理 dna 字串複本中的每一個字元。
    // char& base 中的 '&' 非常關鍵，它代表「參考 (reference)」，
    // 讓我們可以直接修改 dna 字串複本中的字元。
    for (char& base : dna) {
        // 透過 map 找到對應的互補鹼基，並直接替換掉原有的字元。
        base = complement_map.at(base);
    }

    // 回傳已經被完整修改過的 dna 字串複本。
    return dna;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @details 這個函式取代了原本 main 函式中的 lambda 函式。
 * @param input 要測試的 DNA 字串。
 */
void run_test(const string& input) {
    cout << "輸入: \"" << input << "\" --> 輸出: \"" << DNAStrand(input) << "\"" << endl;
}

// --- 主程式：用來測試 DNAStrand 函式 ---
int main() {
    cout << "--- DNA 互補鏈產生器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    // 現在我們呼叫的是上面定義的常規函式
    run_test("ATTGC"); // 預期輸出: "TAACG"
    run_test("GTAT");  // 預期輸出: "CATA"

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一段 DNA 序列 (只包含 A, T, C, G): ";
    cin >> user_input;
    run_test(user_input);

    cout << "\n測試結束。\n";
    return 0;
}
