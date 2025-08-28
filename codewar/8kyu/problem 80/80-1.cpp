#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
using namespace std;
bool betterThanAverage(vector<int> classPoints, int yourPoints) {
    long long peers_sum = accumulate(classPoints.begin(), classPoints.end(), 0LL);
    long long total_sum = peers_sum + yourPoints;
    int total_students = classPoints.size() + 1;
    double average = static_cast<double>(total_sum) / total_students;
    return yourPoints > average;
}
void run_test(const vector<int>& arr, int my_score) {
    cout << "輸入: 同學分數 { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " }, 你的分數 " << my_score << " -> 輸出: " 
         << (betterThanAverage(arr, my_score) ? "true" : "false") << endl;
}



int main() {
    cout << "\n--- 範例測試 ---\n";
    run_test({100, 40, 34, 57, 29, 72, 57, 88}, 75); // 預期: true
    run_test({2, 3}, 5); // 預期: true
    run_test({12, 23, 34, 45, 56, 67, 78, 89, 90}, 69); // 預期: false

    cout << "\n測試結束。\n";
    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
