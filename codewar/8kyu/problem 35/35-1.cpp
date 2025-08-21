#include <iostream>
#include <string>
#include <cctype>   // 引入 tolower() 函式，用於處理大小寫
#include <limits>   // 用於暫停功能

using namespace std;

bool isPalindrom(const string& str)
{
    // --- 演算法邏輯：雙指標法 ---
    
    // 1. 建立兩個「指標」(索引)，一個指向字串的開頭，一個指向結尾。
    int left = 0;
    int right = str.length() - 1;

    // 2. 使用 while 迴圈，只要左指標還在右指標的左邊，就繼續比較。
    while (left < right) {
        // 3. 比較兩端對應的字元。
        //    為了不區分大小寫，我們先用 tolower() 將兩個字元都轉為小寫再比較。
        if (tolower(str[left]) != tolower(str[right])) {
            // 如果在任何時候，兩端的字元不相等，那它就不是迴文，立刻回傳 false。
            return false;
        }

        // 4. 如果字元相等，就將兩個指標向中間移動。
        left++;
        right--;
    }

    // 5. 如果整個迴圈都跑完了，都沒有發現不相等的字元，
    //    那就代表這個字串是迴文，回傳 true。
    return true;
}

void run_test(const string& text) {
    cout << "輸入: \"" << text << "\" -> 輸出: " 
         << (isPalindrom(text) ? "true" : "false") << endl;
}

// --- 主程式：用來測試 isPalindrom 函式 ---
int main() {
    cout << "--- 迴文判斷器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("madam");   // 預期: true
    run_test("racecar"); // 預期: true
    run_test("Aba");     // 預期: true (不分大小寫)
    run_test("hello");   // 預期: false
    run_test("a");       // 預期: true
    
    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個您想測試的單字: ";
    cin >> user_input;
    run_test(user_input);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
