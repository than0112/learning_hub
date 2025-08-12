#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// 這裡放你剛剛的 pig_it 函式
string pig_it(string str)
{
    string punctuation = "!.,:;?"; // 定義標點符號
    string result = "";            // 儲存最終結果
    stringstream ss;
    ss << str; // 把輸入字串放進 stringstream

    // 用 get 一個一個讀字元
    for (char ch; ss.get(ch);) { 
        if (isspace(ch)) { 
            // 如果是空白，就原樣保留
            result += ch;
        } else {
            // 如果不是空白，就放回去，準備讀一整個單字
            ss.putback(ch);
            string word;
            ss >> word;

            // 判斷是不是標點符號
            if (find(punctuation.begin(), punctuation.end(), word[0]) == punctuation.end()) {
                // 轉成豬拉丁文
                word.push_back(word[0]);
                word.erase(word.begin());
                word += "ay";
            }
            result += word;
        }
    }
    return result;
}

int main()
{
    // 1. 提示使用者輸入句子
    cout << "請輸入一句英文句子（含空白或標點符號）：" << endl;
    
    // 2. 使用 getline 讀取整行（可以包含空白）
    string input;
    getline(cin, input);

    // 3. 呼叫 pig_it 函式進行轉換
    string output = pig_it(input);

    // 4. 輸出結果
    cout << "轉換成豬拉丁文的結果：" << endl;
    cout << output << endl;

    // 5. 程式結束
    return 0;
}
