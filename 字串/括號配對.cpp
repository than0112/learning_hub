#include <iostream>
#include <string>
#include <stack> // 必須引用 stack 標頭檔

using namespace std;

/**
 * @brief 檢查一個包含括號的字串是否配對正確
 * @param s 要檢查的字串
 * @return 如果配對正確，回傳 true；否則回傳 false
 */
bool areBracketsBalanced(const string& s) {
    // 建立一個 char 型別的堆疊，用來存放左括號
    stack<char> st;

    // 使用 for 迴圈遍歷輸入字串中的每一個字元
    for (char c : s) {
        // 如果是左括號，就推入堆疊
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // 如果是右括號，就需要進行判斷
        else if (c == ')' || c == '}' || c == ']') {
            // 情況 1: 遇到右括號，但堆疊是空的，代表沒有對應的左括號
            if (st.empty()) {
                return false; // 不匹配，直接回傳 false
            }

            // 取出堆疊頂端的字元來比較
            char top = st.top();

            // 情況 2: 右括號和堆疊頂端的左括號類型不匹配
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; // 不匹配，直接回傳 false
            }

            // 如果匹配成功，就將堆疊頂端的左括號彈出
            st.pop();
        }
        // 如果不是括號字元，就直接忽略
    }

    // 遍歷完所有字元後，檢查堆疊是否為空
    // 如果堆疊是空的，表示所有括號都完美配對
    // 如果堆疊不是空的，表示有剩餘的左括號沒有被關閉
    return st.empty();
}

int main() {
    string input_str;

    cout << "括號配對檢查器" << endl;
    cout << "請輸入包含括號的字串，每行一次。" << endl;
    cout << "若要結束程式，請按 Ctrl+Z (Windows) 或 Ctrl+D (Linux/Mac)。" << endl;
    cout << "========================================" << endl;

    // 這個迴圈會一行一行地讀取輸入，直到輸入結束
    while (getline(cin, input_str)) {
        // 呼叫檢查函式
        if (areBracketsBalanced(input_str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        cout << "----------------------------------------" << endl;
        cout << "請輸入下一行要檢查的字串:" << endl;
    }

    cout << "\n程式已結束。" << endl;

    return 0;
}
/*括號配對檢查器
請輸入包含括號的字串，每行一次。
若要結束程式，請按 Ctrl+Z (Windows) 或 Ctrl+D (Linux/Mac)。
========================================
((()))
YES
----------------------------------------
請輸入下一行要檢查的字串:
{[]()}
YES
----------------------------------------
請輸入下一行要檢查的字串:
)(
NO
----------------------------------------
請輸入下一行要檢查的字串:
([)]
NO
----------------------------------------
請輸入下一行要檢查的字串:
((()
NO
----------------------------------------
請輸入下一行要檢查的字串:*/