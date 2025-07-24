/*寫一個C++程式能輸入任一整數輸出此整數個個位數之和的值 
例如輸入203581,輸出2+0+3+5+8+1=19*/
#include <iostream>
#include <cmath>   // 使用 abs() 函式來處理負數
#include <limits> // 輸入驗證

using namespace std;

int main() {
    long long number; // 使用 long long 來處理更大範圍的整數

    cout << "請輸入一個整數：";
    cin >> number;

    // --- 輸入驗證 (確保輸入的是有效的整數) ---
    while (cin.fail()) {
        cout << "輸入無效，請重新輸入一個整數：";
        cin.clear(); // 清除 cin 的錯誤狀態
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除緩衝區中的錯誤輸入
        cin >> number;
    }

    int sum_of_digits = 0;
    long long temp_number = number; // 使用一個暫存變數來進行計算，以保留原始輸入值

    // 處理負數的情況，我們先取其絕對值
    temp_number = abs(temp_number);
    
    // 如果輸入是 0，它的位數和就是 0
    if (temp_number == 0) {
        sum_of_digits = 0;
    } else {
        // 使用 while 迴圈逐一拆解並加總每一位數
        while (temp_number > 0) {
            // 1. 取得最右邊的個位數，並加到總和中
            sum_of_digits += temp_number % 10;

            // 2. 移除最右邊的個位數，準備處理下一位
            temp_number /= 10;
        }
    }

    // 輸出結果
    cout << "整數 " << number << " 的各位數之和為: " << sum_of_digits << endl;

    return 0;
}
/*
核心演算法解說
這個程式的核心演算法與「反轉數字」和「找零錢」中的拆解數字技巧完全相同：

取得個位數 (% 10): temp_number % 10 可以取得任何整數的最後一位數。

移除個位數 (/= 10): temp_number /= 10 (整數除法) 可以有效地「砍掉」一個整數的最後一位數。

while 迴圈: 將這兩個步驟放在一個 while (temp_number > 0) 迴圈中，這樣程式就會不斷地重複「取得個位數並加總 -> 移除個位數」，直到 temp_number 變成 0 為止，此時所有的位數都已經被處理完畢。

以輸入 203581 為例的執行追蹤
迴圈次數	temp_number (開始時)	temp_number % 10 (取出的位數)	sum_of_digits (累計和)	temp_number /= 10 (更新後)
1	203581	1	0 + 1 = 1	20358
2	20358	8	1 + 8 = 9	2035
3	2035	5	9 + 5 = 14	203
4	203	3	14 + 3 = 17	20
5	20	0	17 + 0 = 17	2
6	2	2	17 + 2 = 19	0

匯出到試算表
迴圈結束後，sum_of_digits 的最終值就是 19。

程式碼重點
long long number: 使用 long long 而不是 int，可以讓你的程式處理更大範圍的整數（例如超過 21 億的數字），更符合「任一整數」的要求。

abs(temp_number): 使用 <cmath> 函式庫中的 abs() 函式。這一步確保了即使輸入是負數（例如 -123），程式也能正確計算出其位數和（1 + 2 + 3 = 6）
*/