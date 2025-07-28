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