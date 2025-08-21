#include <iostream>
#include <string>
#include <limits> // 用於暫停功能

using namespace std;
int basicOp(char op, int val1, int val2) {
  // 使用 switch 判斷式來根據不同的運算符號執行對應的程式碼
  switch(op) {
    case '+': return val1 + val2;
    case '-': return val1 - val2;
    case '*': return val1 * val2;
    case '/': 
      // 使用三元運算子來處理除法，更為簡潔
      return val2 != 0 ? val1 / val2 : 0;
  }
  
  return 0; 
}

void run_test(char op, int v1, int v2) {
    cout << "輸入: ('" << op << "', " << v1 << ", " << v2 << ") -> 輸出: " << basicOp(op, v1, v2) << endl;
}

// --- 主程式：用來測試 basicOp 函式 ---
int main() {
    cout << "--- 基本數學運算測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test('+', 4, 7);
    run_test('-', 15, 18);
    run_test('*', 5, 5);
    run_test('/', 49, 7);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
