#include <iostream>
#include <cmath> // 為了使用 pow()

using namespace std;

int main() {
    cout << "所有三位數的阿姆斯壯數有：" << endl;

    // 迴圈遍歷所有三位數 (從 100 到 999)
    for (int i = 100; i < 1000; ++i) {
        
        int sum_of_cubes = 0;
        int temp_num = i; // 使用暫存變數來拆解數字，保留 i 的原始值

        // 使用 while 迴圈來拆解數字的每一位
        while (temp_num > 0) {
            int digit = temp_num % 10; // 取得個位數
            
            // 將位數的 3 次方加到總和中
            // sum_of_cubes += pow(digit, 3); // 使用 pow() 函式
            sum_of_cubes += digit * digit * digit; // 手動乘三次效率更高
            
            temp_num /= 10; // 移除個位數
        }

        // 檢查各位數的立方和是否等於原始數字
        if (sum_of_cubes == i) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}