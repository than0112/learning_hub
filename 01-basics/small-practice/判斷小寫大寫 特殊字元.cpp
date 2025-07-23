//判斷輸入的字元是小寫字母 大寫字母 或數字 如果都不是 輸出"特殊字元"
#include <iostream>
#include <cctype> // 引入 cctype 函式庫，用來處理字元分類

using namespace std;

int main() {
    char input_char;

    cout << "請輸入一個字元：";
    cin >> input_char;

    // 使用 if-else if-else 結構來進行判斷
    
    // 1. 判斷是否為小寫字母
    if (islower(input_char)) {
        cout << "小寫字母" << endl;
    }
    // 2. 如果不是小寫，再判斷是否為大寫字母
    else if (isupper(input_char)) {
        cout << "大寫字母" << endl;
    }
    // 3. 如果也不是大寫，再判斷是否為數字
    else if (isdigit(input_char)) {
        cout << "數字" << endl;
    }
    // 4. 如果以上都不是，則為特殊字元
    else {
        cout << "特殊字元" << endl;
    }

    return 0;
}

/*
程式碼解說
#include <cctype>

這是 C++ 中專門用來處理「字元類型 (character type)」的標準函式庫。引入它之後，我們就可以使用一系列方便的函式來檢查字元的屬性。

islower(char)

這個函式會檢查傳入的字元是否為小寫英文字母（'a' 到 'z'）。如果是，它會回傳 true；否則回傳 false。

isupper(char)

這個函式會檢查傳入的字元是否為大寫英文字母（'A' 到 'Z'）。

isdigit(char)

這個函式會檢查傳入的字元是否為數字字元（'0' 到 '9'）。

if-else if-else 結構

程式會按照順序進行判斷：

先用 islower() 檢查。如果成立，就印出「小寫字母」並結束判斷。

如果不成立，才接著用 isupper() 檢查。如果成立，就印出「大寫字母」並結束。

如果再不成立，才用 isdigit() 檢查。如果成立，就印出「數字」並結束。

如果以上所有條件都不成立，程式最後會執行 else 區塊，印出「特殊字元」。



*/