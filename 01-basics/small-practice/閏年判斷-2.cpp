/*判斷某年是閏年或是平年 閏年的規則是 四年 一閏 逢百不閏 四百再閏  」
 因此判斷的條件是 1. 西元年能被 400 整除 為閏年 
西元年能被 4整除 
但不能被 100 整除 為閏年 。 
閏年外 , 其餘皆為平年 。 
輸入 . 西元年 
輸出 . 閏年或平年*/
#include <iostream>
#include <limits> // 用於輸入驗證

using namespace std;

// 將閏年判斷邏輯封裝成一個獨立的函式，回傳 true 或 false
bool isLeapYear(int year) {
    // 使用可讀性更高的條件式
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    int year;
    cout << "請輸入西元年: ";
    cin >> year;

    // --- 輸入驗證 ---
    while (cin.fail() || year <= 0) {
        cout << "輸入無效，請輸入一個正整數的西元年份：";
        cin.clear(); // 清除 cin 的錯誤狀態
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除緩衝區
        cin >> year;
    }

    // 在 main 函式中，直接呼叫 isLeapYear 函式來進行判斷
    if (isLeapYear(year)) {
        cout << year << " 年是閏年" << endl;
    } else {
        cout << year << " 年是平年" << endl;
    }

    return 0;
}
// 程式碼解說
/*
1. cin.fail() - 偵測問題
作用：這是一個函式，用來檢查 cin 是否處於「錯誤狀態」。

情境：當 cin 試圖讀取 int 卻收到了 hello 時，讀取失敗，cin 內部的一個錯誤旗標 (flag) 就會被設定。此時，cin.fail() 就會回傳 true。

在 while 迴圈中：while (cin.fail()) 的意思就是：「只要 cin 還在錯誤狀態，就持續執行這個迴圈」。

2. cin.clear() - 重設狀態
作用：清除 cin 的錯誤旗標，讓它恢復到可以正常工作的狀態。

比喻：這就像是跟 cin 說：「我知道錯了，請你忘掉剛才的錯誤，回到可以正常工作的狀態，準備接收下一次的輸入。」

注意：cin.clear() 只會重設旗標，它不會清除卡在緩衝區裡的 "hello"。

3. cin.ignore(...) - 清空緩衝區
作用：這一步才是真正用來丟棄無效輸入的。

語法解析: cin.ignore(numeric_limits<streamsize>::max(), '\n');

numeric_limits<streamsize>::max(): 這是一個 C++ 的標準用法，代表「一個非常非常大的數字」。它告訴 ignore 函式，我們要忽略的字元數量上限是「基本上無限多」。

'\n': 這是「停止字元」。ignore 會一直丟棄字元，直到它找到並丟棄了這個換行符號 (\n，也就是 Enter 鍵) 為止。

整體意思：「忽略並丟棄輸入緩衝區中，從現在開始直到使用者按下 Enter 鍵為止的所有字元。」
*/


/*為什麼需要輸入驗證？
想像一下，你的程式要求使用者輸入年齡 int age;，但使用者卻輸入了 "hello"。會發生什麼事？

cin 期望讀取一個數字，但它看到了字母 h。

讀取失敗！cin 會進入一個「錯誤狀態 (error state)」。

age 變數沒有被賦予任何有效的值。

更糟的是，"hello" 這個無效的輸入仍然卡在輸入緩衝區裡。

在「錯誤狀態」下，cin 會拒絕之後所有的讀取操作。如果你把這個 cin 放在一個迴圈裡，它會因為不斷讀取到卡住的 "hello" 而造成無限迴圈，程式就當掉了。

輸入驗證的目的，就是為了優雅地處理這種情況：偵測到錯誤 -> 恢復 cin -> 清理錯誤輸入 -> 讓使用者再試一次。
*/