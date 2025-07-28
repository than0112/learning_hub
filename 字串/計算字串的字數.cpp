#include <iostream>
#include <string>
#include <cctype> // 為了使用 isspace

using namespace std;

int main() {
    string text = "  Hello   world, this is C++!  ";
    int word_count = 0;
    bool in_word = false; // 狀態變數，初始為「不在字裡面」

    // 遍歷字串中的每一個字元
    for (char c : text) {
        // isspace() 函式可以判斷一個字元是否為空白字元
        if (isspace(c)) {
            // 如果是空格，就把狀態設為「不在字裡面」
            in_word = false;
        } else {
            // 如果不是空格
            // 且之前的狀態是「不在字裡面」
            if (in_word == false) {
                // 這表示一個新字的開始！
                word_count++;
                // 將狀態更新為「在字裡面」
                in_word = true;
            }
        }
    }

    cout << "原始字串是: \"" << text << "\"" << endl;
    cout << "總字數為: " << word_count << endl;

    return 0;
}