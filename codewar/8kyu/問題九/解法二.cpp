#include <iostream>
#include <vector>
#include <string>

using namespace std;


char findMissingLetter(const vector<char>& chars)
{
    // --- 演算法邏輯 ---

    // 1. 建立完整的字母表作為「標準答案」。
    // 使用 static const 確保這兩個陣列只會在程式首次執行時建立一次，提高效率。
    static const vector<char> lowercase = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    static const vector<char> uppercase = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    // 2. 判斷輸入的字母是大寫還是小寫，並選擇對應的標準字母表。
    // 我們檢查第一個字元 chars[0] 是否在 'a' 到 'z' 的範圍內。
    const vector<char>& alphabet = (chars[0] >= 'a' && chars[0] <= 'z') ? lowercase : uppercase;

    // 3. 在標準字母表中，找到輸入序列的起始位置。
    size_t start_index = 0;
    for (size_t i = 0; i < alphabet.size(); i++) {
        if (alphabet[i] == chars[0]) {
            start_index = i;
            break; // 找到後就跳出迴圈
        }
    }

    // 4. 從起始位置開始，逐一比對輸入序列和標準字母表。
    for (size_t i = 0; i < chars.size(); i++) {
        // 如果在某個位置上，輸入的字母和標準字母表上的不符，
        // 那就代表標準字母表上的這個字母就是缺失的。
        if (chars[i] != alphabet[start_index + i]) {
            return alphabet[start_index + i];
        }
    }

    // 根據題目保證，一定會有一個缺失的字母，所以理論上不會執行到這裡。
    return ' ';
}


void run_test(const vector<char>& input) {
    cout << "輸入: { ";
    for(size_t i = 0; i < input.size(); i++) {
        cout << "'" << input[i] << "'";
        if (i < input.size() - 1) cout << ", ";
    }
    cout << " } -> 輸出: '" << findMissingLetter(input) << "'" << endl;
}

// --- 主程式：用來測試 findMissingLetter 函式 ---
int main() {
    cout << "--- 尋找消失的字母測試器 (查表比對法) ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({'a','b','c','d','f'}); // 預期輸出: 'e'
    run_test({'O','Q','R','S'});   // 預期輸出: 'P'

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({'X', 'Z'}); // 預期輸出: 'Y'

    cout << "\n測試結束。\n";
    return 0;
}
