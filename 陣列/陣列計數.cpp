#include <iostream>
#include <random>   // 現代 C++ 隨機數函式庫
#include <vector>   // 用於儲存統計次數
#include <iomanip>  // 用於美化輸出格式

using namespace std;

int main() {
    const int NUMBER_OF_ROLLS = 10000; // 設定總共要擲的次數
    const int DIE_SIDES = 6;           // 骰子有 6 個面

    // --- 建立高品質的隨機數產生器 ---
    // 1. 能量源：從硬體取得真亂數種子
    random_device rd;
    // 2. 引擎：使用 Mersenne Twister 演算法，並用 rd 當作種子
    mt19937 generator(rd());
    // 3. 模具：建立一個 1 到 6 的均勻整數分佈器
    uniform_int_distribution<int> distribution(1, DIE_SIDES);

    // --- 建立統計次數的容器 ---
    // 我們建立一個大小為 7 的 vector，並全部初始化為 0
    // 這樣我們就可以直接使用索引 1 到 6 來對應點數 1 到 6，忽略索引 0
    vector<int> counts(DIE_SIDES + 1, 0);

    cout << "正在模擬擲骰子 " << NUMBER_OF_ROLLS << " 次..." << endl;

    // --- 執行模擬 ---
    for (int i = 0; i < NUMBER_OF_ROLLS; ++i) {
        // 擲一次骰子，得到一個 1-6 的隨機點數
        int roll = distribution(generator);
        
        // 將對應點數的計數器加一
        counts[roll]++;
    }

    // --- 輸出統計結果 ---
    cout << "\n--- 統計結果 ---" << endl;
    for (int i = 1; i <= DIE_SIDES; ++i) {
        double percentage = static_cast<double>(counts[i]) / NUMBER_OF_ROLLS * 100.0;
        cout << "點數 " << i << ": " 
             << setw(5) << counts[i] << " 次"
             << " (佔比: " << fixed << setprecision(2) << percentage << "%)" 
             << endl;
    }

    return 0;
}