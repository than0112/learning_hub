#include <iostream>
#include <string>
#include <vector>
#include <typeinfo> // 用於 typeid

// 使用 std 命名空間
using namespace std;

// --- 範例 1: 通用的 printValue 函數 ---
template <typename T>
void printValue(T value) {
    // typeid(value).name() 會回傳型別的內部名稱
    cout << "值: " << value << " [型別: " << typeid(value).name() << "]" << endl;
}

// --- 範例 2: 通用的 swapValues 函數 ---
template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// --- 範例 3: 通用的 printArray 函數 ---
template <typename T>
void printArray(const T arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
}

// --- 範例 4: 通用的 findMax 函數 ---
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// --- 範例 5: 通用的 getAverage 函數 ---
template <typename T, typename U>
auto getAverage(T a, U b) -> decltype((a + b) / 2.0) {
    return (a + b) / 2.0;
}


// --- 主程式：測試所有範本函數 ---
int main() {
    cout << "--- 1. 測試通用 printValue ---\n";
    printValue(100);
    printValue(3.14159);
    printValue("Hello, Template!");
    string myString = "C++";
    printValue(myString);

    cout << "\n--- 2. 測試通用 swapValues ---\n";
    int x = 5, y = 10;
    cout << "交換前: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "交換後: x = " << x << ", y = " << y << endl;

    string s1 = "蘋果", s2 = "香蕉";
    cout << "交換前: s1 = " << s1 << ", s2 = " << s2 << endl;
    swapValues(s1, s2);
    cout << "交換後: s1 = " << s1 << ", s2 = " << s2 << endl;

    cout << "\n--- 3. 測試通用 printArray ---\n";
    int intArr[] = {1, 2, 3, 4, 5};
    cout << "整數陣列: ";
    printArray(intArr, 5);

    double doubleArr[] = {1.1, 2.2, 3.3};
    cout << "浮點數陣列: ";
    printArray(doubleArr, 3);
    
    char charArr[] = {'H','E','L','L','O'};
    cout << "字元陣列: ";
    printArray(charArr, 5);

    cout << "\n--- 4. 測試通用 findMax ---\n";
    cout << "Max(10, 20) 的結果是: " << findMax(10, 20) << endl;
    cout << "Max(15.7, 15.2) 的結果是: " << findMax(15.7, 15.2) << endl;
    cout << "Max('A', 'Z') 的結果是: " << findMax('A', 'Z') << endl;

    cout << "\n--- 5. 測試通用 getAverage ---\n";
    cout << "Average(5, 10) 的結果是: " << getAverage(5, 10) << endl;
    cout << "Average(5, 10.5) 的結果是: " << getAverage(5, 10.5) << endl;
    
    return 0;
}