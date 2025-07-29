#include <iostream>
#include <limits> // 用於 numeric_limits

// 使用 std 命名空間，這樣就不需要重複寫 std::
using namespace std;

// --- 函式原型宣告 (Function Prototypes) ---
// 這樣 main 函式才能在定義之前呼叫它們
void inputArray(int arr[], int size);
void printArray(const int arr[], int size);
int sumArray(const int arr[], int size);
int findMax(const int arr[], int size);


// --- 主程式進入點 ---
int main() {
    // 定義陣列的大小，方便未來修改
    const int ARRAY_SIZE = 5;
    int numbers[ARRAY_SIZE];

    cout << "歡迎使用陣列操作程式！\n";
    cout << "------------------------------------\n";

    // 1. 呼叫函式，讓使用者輸入陣列元素
    inputArray(numbers, ARRAY_SIZE);

    cout << "\n------------------------------------\n";

    // 2. 呼叫函式，印出使用者輸入的陣列內容
    cout << "你輸入的陣列是：";
    printArray(numbers, ARRAY_SIZE);

    // 3. 呼叫函式，計算總和並儲存結果
    int totalSum = sumArray(numbers, ARRAY_SIZE);
    cout << "陣列元素的總和是：" << totalSum << endl;

    // 4. 呼叫函式，找出最大值並儲存結果
    int maxValue = findMax(numbers, ARRAY_SIZE);
    cout << "陣列中的最大值是：" << maxValue << endl;

    return 0;
}


/**
 * @brief 函式 1: 讓使用者一一輸入陣列元素的值。
 * @param arr 要被填入數值的陣列。
 * @param size 陣列的大小。
 */
void inputArray(int arr[], int size) {
    cout << "請輸入 " << size << " 個整數：\n";
    for (int i = 0; i < size; ++i) {
        cout << "請輸入第 " << (i + 1) << " 個數字: ";
        cin >> arr[i];
        
        // 簡單的輸入錯誤處理
        while (cin.fail()) {
            cout << "輸入無效，請重新輸入一個整數: ";
            cin.clear(); // 清除錯誤旗標
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略掉這一行的錯誤輸入
            cin >> arr[i];
        }
    }
}

/**
 * @brief 函式 2: 輸出陣列所有元素的值。
 * @param arr 要被輸出的陣列。使用 const 保護陣列不被修改。
 * @param size 陣列的大小。
 */
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * @brief 函式 3: 計算並回傳陣列元素的和。
 * @param arr 要計算總和的陣列。使用 const 保護陣列不被修改。
 * @param size 陣列的大小。
 * @return int 回傳所有元素的總和。
 */
int sumArray(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i]; // 將每個元素累加到 sum 中
    }
    return sum;
}

/**
 * @brief 函式 4: 找出並回傳陣列中的最大值。
 * @param arr 要尋找最大值的陣列。使用 const 保護陣列不被修改。
 * @param size 陣列的大小。
 * @return int 回傳陣列中的最大值。
 */
int findMax(const int arr[], int size) {
    // 防呆：如果陣列是空的，回傳 0 或一個錯誤碼
    if (size <= 0) {
        return 0; 
    }

    // 假設第一個元素就是最大值
    int maxVal = arr[0];

    // 從第二個元素開始遍歷比較
    for (int i = 1; i < size; ++i) {
        // 如果發現有比當前最大值更大的數，就更新最大值
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}