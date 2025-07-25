#include <iostream>
#include <vector>
#include <random> // 引入現代 C++ 隨機數函式庫

using namespace std;

int main(){
    const int n = 6; // 陣列大小，使用 const 是一個好習慣
    vector<int> a(n); // 使用 std::vector 取代 C-style 陣列，更安全且彈性

    // --- 現代 C++ 隨機數產生器設定 ---
    // 1. 從作業系統/硬體取得一個高品質的隨機種子
    random_device rd;
    // 2. mt19937作為亂數引擎，並用 rd 當作種子
    mt19937 generator(rd());
    // 3. 建立一個 1 到 6 的均勻整數分佈器 (就像一顆骰子)
    uniform_int_distribution<int> distribution(1, 6);

    // --- 使用迴圈初始化陣列 ---
    for(int i = 0; i < n; i++){
        // 呼叫分佈器並傳入引擎，來產生一個 1-6 的隨機數
        a[i] = distribution(generator);
    }

    // --- 輸出陣列內容 ---
    for(int i = 0; i < n; i++){
        cout << "[a" << i << "]" << a[i] << "\t";
    }
    cout << endl; // 加上換行讓輸出更整齊

    return 0;
}