#include <iostream>
#include <vector>
#include <cmath>     // 為了使用 sqrt() 函式
#include <algorithm> // 為了使用 sort() 函式

using namespace std;

int main() {
    int n;
    
    // 使用 while(cin >> n) 結構，可以重複輸入直到遇到無效輸入 (如 Ctrl+Z)
    cout << "請輸入一個正整數 (輸入非數字以結束): ";
    while (cin >> n) {
        if (n <= 0) {
            cout << "輸入無效，請輸入一個正整數。" << endl;
            cout << "\n請輸入一個正整數 (輸入非數字以結束): ";
            continue; // 繼續下一次迴圈
        }

        vector<int> factors; // 使用 vector 來儲存所有因數

        // 核心優化：迴圈只跑到 n 的平方根
        for (int i = 1; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                // i 是一個因數
                factors.push_back(i);

                // 計算 i 對應的另一個因數
                int pair_factor = n / i;

                // 如果 i 和它的配對因數不相等，才把配對因數也加入
                // (這是為了避免像 36 = 6*6 這種情況，6被重複加入)
                if (i != pair_factor) {
                    factors.push_back(pair_factor);
                }
            }
        }

        // 因為我們是成對找的，順序會亂掉，所以需要排序
        sort(factors.begin(), factors.end());

        // 輸出結果
        cout << n << " 的因數有：";
        for (int factor : factors) {
            cout << factor << " ";
        }
        cout << endl;

        cout << "\n請輸入一個正整數 (輸入非數字以結束): ";
    }

    return 0;
}