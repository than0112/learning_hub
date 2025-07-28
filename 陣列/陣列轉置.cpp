#include <iostream>
#include <vector>
#include <string>
#include <utility> // 為了使用 std::swap

using namespace std;

// 使用二維 vector 來表示矩陣
using Matrix = vector<vector<int>>;

// 輔助函式：印出矩陣 (這個函式很有用，我們保留它)
void printMatrix(const Matrix& matrix, const string& title) {
    cout << title << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    Matrix A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printMatrix(A, "原始矩陣:");
    cout << endl;

    // === 原地轉置的核心邏輯 ===
    // 檢查是否為方陣，確保 matrix.size() 和 matrix[0].size() 相同
    if (!A.empty() && A.size() == A[0].size()) {
        size_t n = A.size();
        for (size_t i = 0; i < n; ++i) {
            // 內層迴圈從 i + 1 開始，這是關鍵！
            for (size_t j = i + 1; j < n; ++j) {
                // 交換對角線兩側的元素
                swap(A[i][j], A[j][i]);
            }
        }
    }
    
    // 直接印出被修改後的矩陣 A
    printMatrix(A, "轉置後矩陣:");

    return 0;
}

/*
size_t 是一種專門用來表示「大小」或「數量」的整數型別。它是一種「無正負號的整數」(Unsigned Integer)。

我們來看看它的幾個關鍵特點和為什麼要用它。

1. 它是「無正負號」的 (Unsigned)
int 可以是正數、負數、或零 (例如: 10, -5, 0)。

size_t 只能是正數或零。

為什麼這樣設計？因為「大小」或「數量」在邏輯上永遠不可能是負數。一個 vector 的大小可以是 5，也可以是 0，但絕對不可能是 -3。所以 size_t 這個型別從根本上就防止了用負數來表示大小的錯誤。

2. 它的大小是「可變的」，能保證夠用
這是 size_t 最重要的特性之一。

在 32 位元的作業系統上，size_t 通常是 unsigned int (最大約 42 億)。

在 64 位元的作業系統上，size_t 通常是 unsigned long long (一個非常非常大的數字)。

這代表什麼？代表你不需要自己去煩惱在不同電腦上要用 unsigned int 還是 unsigned long long。只要你用 size_t，C++ 編譯器就會自動幫你選擇最適合的、保證足夠大的型別，來儲存任何可能物件的大小。

它被設計來保證能儲存你的電腦記憶體中「最大可能物件的大小」。

3. 為什麼在迴圈中推薦使用它？
在你的程式碼中：

C++

for (size_t i = 0; i < n; ++i)
這裡使用 size_t i 是一個非常好的程式設計習慣。

因為 n 的值來自於 A.size()，而所有 C++ 標準容器（像 vector, string）的 .size() 方法回傳的型別就是 size_t。

所以，讓迴圈變數 i 的型別與 .size() 的回傳型別保持一致，可以避免一些潛在的問題，例如：

避免編譯器警告：如果用 int i 來和 A.size() (一個 size_t) 比較，有些編譯器會發出「signed/unsigned mismatch」(有號數與無號數型別不匹配) 的警告。

避免極端情況下的錯誤：如果一個 vector 真的大到超過 int 的上限（雖然很少見，但在 64 位元系統上是可能的），使用 int 會導致迴圈出錯。

總結
可以把 size_t 和 int 這樣區分：

特性	int	size_t
用途	用於一般的數值計算，例如溫度、分數、座標等。	專門用來表示陣列索引、物件大小、元素數量。
正負號	有正負號 (Signed)	無正負號 (Unsigned)
可攜性	大小固定 (通常是 4 bytes)	大小依系統而定，但保證夠用。
範例	int score = -10;	size_t length = my_vector.size();




*/