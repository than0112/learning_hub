#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // 必須引入 <algorithm> 才能使用 std::generate

using namespace std;

int main() {
    const int n = 6;
    vector<int> a(n); // 先宣告一個有 n 個空間的 vector

    // --- 亂數產生器設定 (與之前相同) ---
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 6);

    // --- 核心步驟：使用 generate ---
    // 我們將一個「產生器函式」傳給 generate
    // generate 會呼叫這個函式 n 次，並將每一次的回傳值填入 vector 中
    generate(a.begin(), a.end(), [&]() {
        return distribution(generator);
    });

    // --- 輸出結果 ---
    cout << "使用generate 初始化的陣列：" << endl;
    for (int i = 0; i < n; i++) {
        cout << "[a" << i << "]" << a[i] << "\t";
    }
    cout << endl;

    return 0;
}