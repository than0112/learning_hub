/*sizeof 是一個 C/C++ 中的運算子，它的主要作用是在編譯時期，計算出一個資料型態或變數在記憶體中所佔用的空間大小，單位是位元組 (bytes)。

把它想像成一把尺，sizeof 不是用來測量變數裡面存的「值」有多大，而是用來測量儲存這個變數的「盒子」本身佔多大的空間。

## 實際用例：計算 C-Style 陣列的元素個數
在 C++ 中，傳統的 C-style 陣列（例如 int arr[]）本身並不記錄自己的長度。如果你想在程式中知道它有多少個元素，sizeof 就是最經典的解決方案。

核心思想：陣列總大小 (bytes) / 單一元素大小 (bytes) = 元素個數*/



#include <iostream>
using namespace std;

// 一個函式，用來展示 sizeof 的陷阱
void printArraySize(int arr[]) {
    // 錯誤！在這裡，arr 已經退化成一個指標 (pointer)
    cout << "在函式中，sizeof(arr) = " << sizeof(arr) << " bytes" << endl;
    cout << "  -> 這只是指標的大小，不是整個陣列的大小！" << endl;
}

int main() {
    // 宣告一個 C-style 整數陣列
    int scores[] = {88, 95, 72, 100, 68, 92, 85};

    // 1. 計算整個陣列佔用的總記憶體空間
    size_t total_size = sizeof(scores);
    cout << "整個 scores 陣列的大小: " << total_size << " bytes" << endl;

    // 2. 計算陣列中單一元素的大小 (這裡我們取第一個元素為代表)
    size_t element_size = sizeof(scores[0]);
    cout << "scores 陣列中一個元素的大小: " << element_size << " bytes" << endl;

    // 3. 計算陣列的元素個數
    int element_count = total_size / element_size;
    cout << "scores 陣列的元素個數: " << element_count << endl;

    cout << "\n--- 遍歷陣列 ---" << endl;
    // 現在我們可以用 element_count 來安全地遍歷陣列
    for (int i = 0; i < element_count; ++i) {
        cout << scores[i] << " ";
    }
    cout << endl;

    cout << "\n--- sizeof 的陷阱 ---" << endl;
    printArraySize(scores);

    return 0;
}
/*
程式碼解說
sizeof(scores): 在 64 位元系統上，一個 int 通常是 4 bytes。這個陣列有 7 個 int，所以總大小是 7 * 4 = 28 bytes。sizeof 會回傳 28。

sizeof(scores[0]): scores[0] 是陣列的第一個元素，它是一個 int。所以 sizeof 會回傳 4。

total_size / element_size: 28 / 4 的結果就是 7，這正是陣列中元素的確切數量。

重要陷阱：當你將一個 C-style 陣列作為參數傳遞給一個函式時（如 printArraySize 函式），它會**「退化」(decay) 成一個指向該陣列第一個元素的指標**。所以在函式內部，sizeof(arr) 計算的就不再是整個陣列的大小，而僅僅是一個指標本身的大小（在 64 位元系統上通常是 8 bytes），這就是為什麼這個技巧只在陣列被宣告的同一個作用域內有效。

## 總結：sizeof 是做什麼用的？
1. 計算 C-Style 陣列的元素數量 (最常用)

如上例所示，sizeof(array) / sizeof(array[0])。

2. 了解資料型態的記憶體佔用

檢查 int, double, char 或自訂的 struct 在你的系統上到底佔多少空間，這對於效能優化和底層程式設計很重要。

3. 動態記憶體配置

在 C 語言的 malloc 或 C++ 的 memset 等函式中，你需要明確告知要操作多少位元組的記憶體。例如：malloc(10 * sizeof(int)) 代表「請給我 10 個整數大小的記憶體空間」。

4. 跨平台程式設計

int 在某些系統上可能是 2 bytes，在另一些系統上是 4 bytes。sizeof 可以讓你的程式碼根據編譯的平台，自動獲取正確的大小，增加程式的可攜性。
*/