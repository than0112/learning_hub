#include <iostream>
#include <vector>
#include <string>
#include <limits> // 用於暫停功能

using namespace std;
string findNeedle(const vector<string>& haystack)
{
  
    for (size_t i = 0; i < haystack.size(); ++i)
    {
        // 2. 檢查當前的字串 haystack[i] 是否等於 "needle"。
        if (haystack[i] == "needle")
        {
            // 3. 如果找到了，就組合回傳的訊息並立刻結束函式。
            //   to_string(i) 會將整數索引 i 轉換為字串。
            return "found the needle at position " + to_string(i);
        }
    }

   
    return "";
}

void run_test(const vector<string>& arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << "\"" << arr[i] << "\"" << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } \n-> 輸出: \"" << findNeedle(arr) << "\"" << endl;
}

// --- 主程式：用來測試 findNeedle 函式 ---
int main() {
    cout << "--- 大海撈針測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({"hay", "junk", "hay", "hay", "moreJunk", "needle", "randomJunk"});

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
