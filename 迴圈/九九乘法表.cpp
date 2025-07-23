//使用多重for迴圈顯示九九乘法表
#include <iostream>
#include <iomanip> // 為了使用 setw 來美化排版

using namespace std;

int main() {
    // 外層迴圈，控制被乘數 (從 1 到 9)
    for (int i = 1; i <= 9; ++i) {
        
        // 內層迴圈，控制乘數 (也是從 1 到 9)
        for (int j = 1; j <= 9; ++j) {
            
            // 使用 iomanip 來格式化輸出，讓版面更整齊
            // left: 文字靠左對齊
            // setw(n): 設定下一次輸出的欄位寬度為 n
            cout << left << setw(2) << j 
                 << " * " << setw(2) << i 
                 << " = " << setw(2) << i * j << "   ";
        }
        
        // 每當內層迴圈跑完一輪 (也就是一行結束)，就換行
        cout << endl;
    }

    return 0;
}

