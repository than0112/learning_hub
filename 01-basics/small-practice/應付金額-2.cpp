//小明到商店購物 花了 n元 (<= 1000）、 他拿出一張千元紙鈔 
//,請寫一 程式、能輸出最多要找回幾張 500, 100 元紙鈔：幾個 50, 10,5,1 元銅板。
#include <iostream>

using namespace std;

int main() {
    int cost;
    cout << "請輸入消費金額 (n元，n <= 1000)：";
    cin >> cost;

    // --- 輸入驗證 ---
    if (cin.fail() || cost < 0 || cost > 1000) {
        cout << "輸入無效，請輸入 0 到 1000 之間的整數。" << endl;
        return 1; // 結束程式
    }

    // 1. 計算總共要找回的金額
    int change = 1000 - cost;
    cout << "找零總額: " << change << " 元" << endl;
    cout << "--------------------------" << endl;

    // 2. 計算 500 元紙鈔的張數
    int count500 = change / 500;
    change = change % 500; // 更新剩餘的找零金額

    // 3. 計算 100 元紙鈔的張數
    int count100 = change / 100;
    change = change % 100;

    // 4. 計算 50 元銅板的個數
    int count50 = change / 50;
    change = change % 50;

    // 5. 計算 10 元銅板的個數
    int count10 = change / 10;
    change = change % 10;

    // 6. 計算 5 元銅板的個數
    int count5 = change / 5;
    change = change % 5;

    // 7. 剩下的就是 1 元銅板的個數
    int count1 = change;

    // --- 輸出結果 ---
    cout << "500 元紙鈔需要: " << count500 << " 張" << endl;
    cout << "100 元紙鈔需要: " << count100 << " 張" << endl;
    cout << "50 元銅板需要 : " << count50 << " 個" << endl;
    cout << "10 元銅板需要 : " << count10 << " 個" << endl;
    cout << "5 元銅板需要  : " << count5 << " 個" << endl;
    cout << "1 元銅板需要  : " << count1 << " 個" << endl;

    return 0;
}

/*核心觀念與程式碼解說
這個演算法的核心是一種「貪婪演算法 (Greedy Algorithm)」。它的策略非常直觀：永遠先用最大面額的錢去找零，找完後，再用剩下的錢去處理次大面額的，依此類推，直到找完為止。

int change = 1000 - cost;

首先，我們計算出顧客應該拿回的總找零金額。

int count500 = change / 500;

整數除法 (/) 在這裡用來計算「最多能找幾張」。例如，如果找零是 888 元，888 / 500 的結果是 1，代表最多能找一張 500 元。

change = change % 500;

模數運算 (%) 在這裡用來計算「用大鈔找完後，還剩下多少錢要找」。例如，888 % 500 的結果是 388。

我們將 change 變數的值更新為這個餘數，然後帶著這個新的、較小的金額，去進行下一個面額的計算。

這個「除法取商數，模數取餘數更新」的模式會一直重複，直到最後處理完 1 元銅板為止，非常有效率。
*/