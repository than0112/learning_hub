#include <iostream>
#include <vector>
#include <string>

using namespace std;


char findMissingLetter(const std::vector<char>& chars)
{
  // 1. 讓「領隊」ret 站到隊伍的起始位置。
  char ret = chars.front();
  
  // 2. 讓隊伍中的每一個成員 c 上前報到。
  for(char c : chars)
  {
    // 3. 如果報到的成員 c 和領隊 ret 預期的不一樣，代表找到缺口。
    if(c != ret) {
        break; // 立刻停止點名。
    }
    // 4. 如果一樣，領隊就往前走一步，準備點名下一個。
    ++ret;
  }
  
  // 5. 迴圈停止時，ret 正好停在那個缺失字母的位置上。
  return ret;
}


/**
 * @brief 一個常規的具名函式，用來執行測試並漂亮地印出結果。
 * @param input 要測試的字元向量。
 */
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
    cout << "--- 尋找消失的字母測試器 (領隊法) ---\n";

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
