#include <iostream>
#include <string>
#include <algorithm> // 可選，用於其他可能的字串操作

using namespace std;

/**
 * @brief 產生一條 DNA 鏈的互補鏈。
 * @details 根據規則 A-T, C-G 進行配對。
 * @param dna 原始的 DNA 字串。
 * @return string 互補的 DNA 字串。
 */
string DNAStrand(const string& dna)
{
    // 準備一個空字串，用來存放我們建立的互補鏈。
    string complement = "";

    // 使用 for-each 迴圈，逐一檢查原始 DNA 鏈上的每一個鹼基 (字元)。
    for (char base : dna) {
        // 使用 switch 判斷式來決定要配對的鹼基。
        // 這比使用多個 if-else 更清晰且效率更高。
        switch (base) {
            case 'A':
                complement += 'T'; // 如果是 A，就加上 T
                break;
            case 'T':
                complement += 'A'; // 如果是 T，就加上 A
                break;
            case 'C':
                complement += 'G'; // 如果是 C，就加上 G
                break;
            case 'G':
                complement += 'C'; // 如果是 G，就加上 C
                break;
            // 根據題目，不會有其他字元，所以不需要 default。
        }
    }

    // 回傳建立好的完整互補鏈。
    return complement;
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
