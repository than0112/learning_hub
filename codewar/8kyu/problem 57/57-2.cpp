#include <iostream>
#include <string>
#include <algorithm> 
#include <limits>    // 用於暫停功能

using namespace std;

std::string DNAtoRNA(std::string dna){
  // 使用傳統的 for 迴圈，透過索引 i 遍歷字串中的每一個位置。
  for (size_t i = 0; i < dna.size(); i++)
  {
    // 檢查目前位置上的字元是否為 'T'。
    if (dna[i] == 'T')
    {
      // 如果是，就直接將該位置的字元修改為 'U'。
      dna[i] = 'U';
    }
  }
  // 回傳已經被修改過的 dna 字串複本。
  return dna;
}

void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"  =>  輸出: \"" << DNAtoRNA(input) << "\"" << endl;
}

// --- 主程式：用來測試 DNAtoRNA 函式 ---
int main() {
    cout << "--- DNA 轉錄 RNA 測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("GCAT"); // 預期輸出: "GCAU"
    
    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test("TTTT"); // 預期輸出: "UUUU"
    run_test("GACCGCCGCC"); // 預期輸出: "GACCGCCGCC" (沒有 T)
    run_test(""); // 預期輸出: "" (空字串)

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
