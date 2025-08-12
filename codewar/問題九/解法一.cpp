#include <iostream>
#include <vector>
#include <string>

using namespace std;

char findMissingLetter(const vector<char>& chars)
{
    
    for (size_t i = 1; i < chars.size(); ++i)
    {

        if (chars[i] != chars[i-1] + 1)
        {
            // 3. 回傳缺失的字母。
            // 缺失的字母就是前一個字母的「下一個」。
            // 例如，如果 chars[i-1] 是 'd'，chars[i] 是 'f'，
            // 那麼 'd' + 1 的結果就是 'e'。
            return chars[i-1] + 1;
        }
    }
    return ' ';
}


void run_test(const vector<char>& input) {
    cout << "輸入: { ";
    for(size_t i = 0; i < input.size(); ++i) {
        cout << "'" << input[i] << "'";
        if (i < input.size() - 1) cout << ", ";
    }
    cout << " } -> 輸出: '" << findMissingLetter(input) << "'" << endl;
}

// --- 主程式：用來測試 findMissingLetter 函式 ---
int main() {
    cout << "--- 尋找消失的字母測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    // 現在我們呼叫的是上面定義的常規函式
    run_test({'a','b','c','d','f'}); // 預期輸出: 'e'
    run_test({'O','Q','R','S'});   // 預期輸出: 'P'

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({'X', 'Z'}); // 預期輸出: 'Y'

    cout << "\n測試結束。\n";
    return 0;
}
