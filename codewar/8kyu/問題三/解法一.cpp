#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;


string DNA_strand(const string& dna) {
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
           
        }
    }

    // 回傳建立好的完整互補鏈。
    return complement;
}


int main() {
    cout << "--- DNA 互補鏈產生器 ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](const string& input) {
        cout << "輸入: \"" << input << "\" --> 輸出: \"" << DNA_strand(input) << "\"" << endl;
    };

    cout << "\n--- 題目範例測試 ---\n";
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
