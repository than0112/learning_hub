#include <iostream>
#include <vector>
#include <string>
#include <numeric>   // 引入 numeric 以便未來使用
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 將一個單字陣列組合成一個用空格分隔的句子。
 * @param words 包含多個單字的向量。
 * @return std::string 組合後且格式正確的句子。
 */
std::string smash(const std::vector<std::string>& words)
{
  // 1. 處理邊界情況：如果陣列是空的，直接回傳空字串。
  if(words.empty()) return "";
  
  // 2. 準備一個空字串，用來存放結果。
   string result = "";
   size_t size = words.size();
  
  // 3. 使用 for 迴圈，將每一個單字和一個空格都加到結果中。
   for(size_t i = 0; i < size; i++)
     {
       result += words[i] + " ";
     }
  
  // 4. 迴圈結束後，結果的末尾會多出一個空格 (例如 "hello world ")。
  //    使用 pop_back() 將這個多餘的空格移除。
  result.pop_back();
  
  // 5. 回傳最終的結果。
  return result;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param arr 要測試的向量。
 */
void run_test(const vector<string>& arr) {
    cout << "輸入: [";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << "'" << arr[i] << "'" << (i < arr.size() - 1 ? ", " : "");
    }
    cout << "]  =>  輸出: '" << smash(arr) << "'" << endl;
}

// --- 主程式：用來測試 smash 函式 ---
int main() {
    cout << "--- 單字組合測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({"hello", "world", "this", "is", "great"});

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({"hello"}); // 測試單一單字
    run_test({});    // 測試空陣列

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
