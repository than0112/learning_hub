#include <iostream>
#include <string>
#include <cctype> // 為了使用 isalpha, islower, isupper

// 使用 std 命名空間，讓程式碼更簡潔
using namespace std;

/**
 * @brief 使用凱撒密碼解密一個字串
 * @param ciphertext 加密過的文字
 * @return 解密後的明文
 */
string decryptCaesar(const string& ciphertext) {
    // 這是我們的「鑰匙」，加密時往後移3，所以解密時要往前移3
    const int shift = 3; 
    string plaintext = ""; // 用來存放解密結果的空字串

    // 使用 for 迴圈遍歷加密字串中的每一個字元
    for (char c : ciphertext) {
        // 1. 判斷當前字元 c 是否為英文字母
        if (isalpha(c)) {
            // 2. 判斷是大寫還是小寫，以決定計算的基準 ('A' 或 'a')
            char base = islower(c) ? 'a' : 'A';

            // 3. 執行解密計算
            // (c - base): 先將字元轉換為 0-25 的數字 (A=0, B=1...)
            // - shift: 減去位移量 (向前移動)
            // + 26: 處理負數，確保結果恆為正，以便取模數
            // % 26: 取 26 的模數，處理循環 (例如 A(0) - 3 = -3 -> 23 -> X)
            // + base: 將 0-25 的數字轉換回 ASCII 字元
            char decrypted_char = static_cast<char>((c - base - shift + 26) % 26 + base);
            
            plaintext += decrypted_char; // 將解密後的字元附加到結果中
        } else {
            // 4. 如果不是英文字母，直接附加原字元
            plaintext += c;
        }
    }
    
    return plaintext; // 回傳完整的解密後字串
}

int main() {
    string encrypted_text;

    cout << "凱撒密碼解密器 (位移量為 3)" << endl;
    cout << "請輸入要解密的字串，每行一次。" << endl;
    cout << "若要結束程式，請按 Ctrl+Z (Windows) 或 Ctrl+D (Linux/Mac)。" << endl;
    cout << "========================================" << endl;

    // 這個迴圈會一行一行地讀取輸入，直到輸入結束
    while (getline(cin, encrypted_text)) {
        // 呼叫解密函式
        string decrypted_text = decryptCaesar(encrypted_text);

        // 輸出結果
        cout << "解密結果: " << decrypted_text << endl;
        cout << "----------------------------------------" << endl;
        cout << "請輸入下一行要解密的字串:" << endl;
    }

    cout << "\n程式已結束。" << endl;

    return 0;
}