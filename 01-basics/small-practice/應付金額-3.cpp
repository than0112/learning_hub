//百貨公司周年慶推出消費每滿1000元就折抵100元。寫一程式輸入消費金額後 能輸出應付金額
#include <iostream>

using namespace std;

int main() {
    int purchaseAmount; // 用來儲存使用者輸入的消費金額

    // 提示使用者輸入
    cout << "請輸入消費總金額：";
    cin >> purchaseAmount;

    // --- 輸入驗證 (確保輸入的是有效的正整數) ---
    if (cin.fail() || purchaseAmount < 0) {
        cout << "輸入無效，請輸入一個非負整數。" << endl;
        return 1; // 提早結束程式並回傳錯誤碼
    }

    // 1. 計算消費金額 "滿 1000 元" 的次數
    //    使用整數除法，小數點後會自動被捨去
    int discountMultiples = purchaseAmount / 1000;

    // 2. 根據滿千的次數，計算總共可以折抵多少錢
    int discount = discountMultiples * 100;

    // 3. 計算最終應付金額
    int finalAmount = purchaseAmount - discount;

    // --- 輸出結果 ---
    cout << "--------------------------" << endl;
    cout << "原始金額: " << purchaseAmount << " 元" << endl;
    cout << "滿千折抵: -" << discount << " 元" << endl;
    cout << "應付金額: " << finalAmount << " 元" << endl;
    cout << "--------------------------" << endl;

    return 0;
}