string 是 C++ 標準函式庫中一個極其強大且方便的類別，用於處理文字資料。相較於傳統的 C 風格字元陣列 (char*)，string 提供了自動記憶體管理和豐富的內建函式，讓字串操作變得更安全、更直觀。

要使用 string，你必須先引入標頭檔：

C++

#include <string>
1. 定義字串 (Defining a String)
觀念講解
你可以用多種方式建立（或稱「初始化」）一個 string 物件。最常見的是直接用雙引號的字串字面值來賦值，或是建立一個空字串。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. 建立一個空字串
    string s1;

    // 2. 使用字串字面值初始化
    string s2 = "Hello, C++!";

    // 3. 使用另一種建構函式初始化
    string s3("I am a string.");

    // 4. 建立一個包含 5 個 'A' 字元的字串
    string s4(5, 'A');

    // 5. 使用另一個 string 物件來複製
    string s5 = s2;

    cout << "s1 (空字串): " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5 (s2的複製品): " << s5 << endl;

    return 0;
}```
2. 輸入/輸出字串 (Input/Output)
觀念講解
cin：用於讀取輸入，但它會以空白字元（空格、Tab、換行）為分隔符。因此，它只能讀取不含空格的單一詞彙。

getline(cin, str)：用於讀取一整行輸入，直到使用者按下 Enter 鍵為止。這是讀取可能包含空格的字串（如姓名、句子）的標準方法。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string word, sentence;

    cout << "請輸入一個單字: ";
    cin >> word; // cin 只會讀取到第一個空格前

    // 清除輸入緩衝區中殘留的換行符號
    cin.ignore(); 

    cout << "請輸入一個完整的句子: ";
    getline(cin, sentence); // getline 會讀取整行

    cout << "\n--- 結果 ---" << endl;
    cout << "你輸入的單字是: " << word << endl;
    cout << "你輸入的句子是: " << sentence << endl;

    return 0;
}```
3. 比較字串 (Comparing)
觀念講解
std::string 可以直接使用標準的比較運算子（==, !=, <, >, <=, >=）來進行比較。比較是基於「字典順序」（lexicographical order），也就是字母在字典中的先後順序。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "apple";
    string s2 = "banana";
    string s3 = "apple";

    // 檢查是否相等
    if (s1 == s3) {
        cout << "s1 和 s3 是相等的。" << endl;
    }

    // 檢查是否不相等
    if (s1 != s2) {
        cout << "s1 和 s2 是不相等的。" << endl;
    }

    // 字典順序比較
    if (s1 < s2) {
        cout << "s1 在字典中排在 s2 之前。" << endl;
    }

    return 0;
}```
4. 連接字串 (Concatenating)
觀念講解
使用 + 或 += 運算子可以非常直觀地將兩個字串或字串與字元字面值連接起來。這遠比 C 語言的 strcat 安全方便。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string first_name = "David";
    string last_name = "Wang";

    // 使用 + 運算子連接字串
    string full_name = first_name + " " + last_name;
    cout << "全名是: " << full_name << endl;

    // 使用 += 運算子附加字串
    string greeting = "Hello";
    greeting += ", ";
    greeting += full_name;
    greeting += "!";
    cout << "問候語: " << greeting << endl;

    return 0;
}```
5. 計算字串長度 (Length)
觀念講解
可以使用 .length() 或 .size() 成員函式來取得字串的長度（即字元個數）。這兩個函式的功能完全相同，回傳一個 size_t 型別的無正負號整數。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "C++ is powerful!";
    string empty_str = "";

    cout << "字串是: \"" << text << "\"" << endl;
    cout << "它的長度 (length) 是: " << text.length() << endl;
    cout << "它的長度 (size) 是: " << text.size() << endl;

    cout << "\n空字串的長度是: " << empty_str.length() << endl;

    return 0;
}```
6. 插入字串 (Inserting)
觀念講解
使用 .insert() 成員函式可以在字串的指定位置插入另一個字串。最常見的用法是 str.insert(position, string_to_insert)，其中 position 是從 0 開始的索引。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "Hello World!";
    cout << "原始字串: " << str << endl;

    // 在索引 6 的位置 (W的前面) 插入 "beautiful "
    str.insert(6, "beautiful ");
    
    cout << "插入後字串: " << str << endl;

    return 0;
}```
7. 刪除字串 (Deleting)
觀念講解
使用 .erase() 成員函式可以刪除字串中指定位置和長度的部分。常見用法是 str.erase(position, count)，刪除從 position 開始的 count 個字元。若要清空整個字串，可以使用 .clear()。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "This is a long sentence.";
    cout << "原始字串: " << str << endl;

    // 從索引 10 的位置開始，刪除 5 個字元 (" long")
    str.erase(10, 5);
    
    cout << "刪除後字串: " << str << endl;

    // 清空整個字串
    str.clear();
    cout << "清空後字串的長度: " << str.length() << endl;

    return 0;
}```
8. 提取字串 (Substring)
觀念講解
使用 .substr() 成員函式可以從原始字串中提取一部分，並回傳一個新的 string 物件，原始字串不會被改變。用法是 str.substr(position, length)。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "apple,banana,orange";
    
    // 從索引 6 的位置開始，提取 6 個字元
    string fruit = str.substr(6, 6);

    cout << "原始字串: " << str << endl;
    cout << "提取出的子字串是: " << fruit << endl;

    return 0;
}```
9. 搜尋字串 (Finding)
觀念講解
使用 .find() 成員函式可以在一個字串中搜尋指定的子字串。

如果找到了，它會回傳子字串第一次出現的起始索引（從 0 開始）。

如果沒找到，它會回傳一個特殊的值 string::npos。

npos 是 "not a position" 的縮寫，是一個非常大的無正負號整數。檢查回傳值是否等於 string::npos 是判斷搜尋是否成功的標準方法。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "Learning C++ is fun, C++ is great!";

    string search_for = "C++";

    // 搜尋 "C++"
    size_t found_pos = text.find(search_for);

    if (found_pos != string::npos) {
        cout << "找到了 '" << search_for << "'，第一次出現的位置在索引: " << found_pos << endl;
    } else {
        cout << "沒有找到 '" << search_for << "'。" << endl;
    }
    
    // 搜尋一個不存在的字串
    found_pos = text.find("Java");
    if (found_pos == string::npos) {
        cout << "\n搜尋 'Java' ... 結果是: 沒找到！" << endl;
    }

    return 0;
}```
10. 讀取字串的方式 (Accessing Characters)
觀念講解
有幾種方式可以存取或遍歷字串中的單一字元：

[] 運算子：像陣列一樣使用中括號和索引來存取。速度快，但不進行邊界檢查，如果索引超出範圍，可能導致程式錯誤。

.at() 函式：與 [] 類似，但它會進行邊界檢查。如果索引無效，它會拋出一個 out_of_range 異常，程式會終止（除非你用 try-catch 處理），更安全。

範圍-based for 迴圈 (C++11)：這是最現代、最推薦的遍歷方式，既簡潔又安全。

範例
```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";

    // 1. 使用 [] 運算子
    cout << "使用 []:" << endl;
    cout << "  第一個字元是: " << s[0] << endl;
    cout << "  第四個字元是: " << s[3] << endl;
    // 修改字元
    s[0] = 'J';
    cout << "  修改後字串: " << s << endl;

    s = "Hello"; // 還原

    // 2. 使用 .at() 函式
    cout << "\n使用 .at():" << endl;
    cout << "  第二個字元是: " << s.at(1) << endl;
    
    // 3. 使用範圍-based for 迴圈遍歷 (唯讀)
    cout << "\n使用 for 迴圈遍歷:" << endl;
    cout << "  ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}```