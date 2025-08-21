#include <string>
#include <vector>
#include <iostream>
#include <limits> 
#include <stdexcept> 
using namespace std;
bool logicalCalc(const vector<bool>& items, const string& op) {
  bool result = items[0]; //因為題目保證第一個元素一定存在，所以可以直接使用
  for (size_t i = 1; i < items.size(); ++i) {
    if (op == "AND") {
      result = result && items[i];
    } else if (op == "OR") {
      result = result || items[i];
    } else if (op == "XOR") {
      result = result ^ items[i]; // XOR 的邏輯是兩個值不同時為真
    } else {
      throw invalid_argument("Invalid operator: " + op);
    }
  }

  return result;
}
void run_test (const vector<bool>& items, const string& op) {
    cout << "輸入: ";
    for (size_t i =0;i<items.size() ; ++i) {
        cout << (items[i] ? "true " : "false ")<<(i < items.size() - 1 ? ", " : "");
    }
    cout << "操作: " << op << " -> 輸出: " << (logicalCalc(items, op) ? "true" : "false") << endl;
}
int main (){
    cout<<"--- 邏輯計算器測試器 ---\n"<<endl;
    run_test({true, true, false}, "AND"); // 預期輸出: false
    run_test({true, true, false}, "OR");  // 預期輸出: true
    run_test({true, true, false}, "XOR"); // 預期輸出: false

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({true, true, true}, "AND");  // 預期輸出: true
    run_test({false, false}, "OR");       // 預期輸出: false
    run_test({true, false, true}, "XOR"); // 預期輸出: false

    cout << "\n測試結束。\n";
    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略輸入緩衝區中的所有內容
    cin.get(); // 等待使用者按下 Enter 鍵
    // --- 結束程式 ---
    // 這樣可以確保程式在執行完畢後不會立即關閉，讓使用者有時間查看結果。
    return 0;
}
/*執行流程範例
讓我們用 items = {true, true, false} 和 op = "AND" 來走一遍：

迴圈開始前: result 被設為 items[0]，所以 result 是 true。

第一次迴圈 (i = 1):

op 是 "AND"。

執行 result = result && items[1];，也就是 result = true && true;。

result 更新為 true。

第二次迴圈 (i = 2):

op 是 "AND"。

執行 result = result && items[2];，也就是 result = true && false;。

result 更新為 false。

迴圈結束: i 變成 3，不滿足 i < 3 的條件，迴圈停止。

函式最終回傳 result 的值，也就是 false。*/