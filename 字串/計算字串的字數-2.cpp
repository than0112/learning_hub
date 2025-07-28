#include <iostream>
#include <string>
#include <sstream> // 必須引用 sstream 標頭檔

using namespace std;

int main() {
    
    string text = "  Hello   world, this is C++!  ";
    int word_count = 0;

    // 1. 建立一個 istringstream 物件，並將我們的字串餵給它
    istringstream iss(text);

    // 2. 宣告一個暫存的 string 變數，用來接收分離出來的字
    string word;

    // 3. 使用 while 迴圈和 >> 運算子來提取字
    //    這個迴圈會一直執行，直到無法再從 iss 中提取出任何「字」為止
    while (iss >> word) {
        // 每成功提取一個字，計數器就加一
        word_count++;
        cout << "提取到第 " << word_count << " 個字: " << word << endl;
    }

    cout << "\n--------------------" << endl;
    cout << "原始字串是: \"" << text << "\"" << endl;
    cout << "總字數為: " << word_count << endl;

    return 0;
}