#include <iostream>
#include <vector>
#include <algorithm> // 必須引入 <algorithm> 才能使用 max_element

using namespace std;

int main() {
    vector<int> numbers = {12, 45, 23, 6, 99, 78, 55};

    if (numbers.empty()) {
        cout << "陣列是空的，沒有最大值。" << endl;
        return 0;
    }

    // --- 核心步驟 ---
    // 1. 呼叫 max_element 函式，它會回傳一個指向最大值元素的「迭代器」
    auto max_iterator = max_element(numbers.begin(), numbers.end());

    // 2. 使用 * 運算子來取得迭代器指向的實際數值
    int max_value = *max_iterator;

    // 印出最終結果
    cout << "陣列中的最大值是: " << max_value << endl;

    return 0;
}
/*
核心概念：委託一位專業的「圖書管理員」

你的 vector<int> numbers：假設是一整排巨大、擺滿了書的書架。
每一本書的封面上都寫著一個數字（戰鬥力）。

你的目標：找到這排書架上，封面數字最大的那本書。

你自己寫 for 迴圈：就像是你親自從第一本書開始，一本一本地看，不斷比較，
直到你看完最後一本為止。費時又燒腦



而max_element(...) 函式 像是一位受過專業訓練、動作極其迅速的圖書管理員。

numbers.begin() 和 numbers.end()：是你遞給管理員的兩張精確的書籤。

auto max_iterator = ...：是管理員完成任務後，遞還給你的一張便條紙，上面寫著那本書的精確位置。

所以，auto max_iterator = max_element(numbers.begin(), numbers.end()); 這整句話的完整翻譯就是：

「嘿，專業的圖書管理員 (max_element)，請你去這個書架 (numbers)，從我給你的『起始書籤』 (begin()) 開始，一直找到『結束書籤』 (end()) 的範圍內，
找出數字最大的那本書。找到後，不用把書拿給我，只要把它的『位置』寫在這張便條紙 (max_iterator) 上交給我就可以了。」

max_element(...) - 專業的圖書管理員
這是一個來自 <algorithm> 標頭檔的「泛型演算法」。所謂「泛型」，是指它不只對 vector 有效，對 list, deque 甚至 C-style 傳統陣列都有效。它是一個身經百戰、懂得如何在任何序列中找最大值的專家。

numbers.begin() 與 numbers.end() - 精確的書籤
這是整個 STL 中最核心的概念：「迭代器 (Iterator)」。你可以把它們看作是比指標更安全、更通用的「智慧指標」或「位置標記」。

numbers.begin()：一個迭代器，它精確地指向 vector 的第一個元素。就像你放在第一本書前面的書籤。

numbers.end()：另一個迭代器，它指向的是最後一個元素的「下一個」位置。這非常重要！它不是指向最後一本書，而是指向最後一本書後面的那個空位。就像你放在最後一本書後面的書籤。

[begin, end) 區間：在 C++ STL 中，所有演算法處理的都是像這樣「包含開頭，不包含結尾」的半開半閉區間。
管理員會搜尋從 begin 開始，直到 end 之前的所有書。

auto max_iterator = ... - 紀錄位置的便條紙
auto: 這是現代 C++ 的一個關鍵字，意思是「編譯器，我懶得寫這個變數的完整型別了，
請根據等號右邊的結果，自動推導出它的型別」。
在這裡，max_iterator 的真實型別其實是 vector<int>iterator，用 auto 既省時又準確。

max_iterator: 這個變數裡儲存的不是數字 99，而是 99 在 vector 中的記憶體位置。
這就是那張寫著正確答案的便條紙。

## 如何從「便條紙」拿到「書」？
既然 max_iterator 只是位置，要如何取得真正的數值 99 呢？答案是使用 * 解參考 (dereference) 運算子，就跟使用指標一樣。
*/