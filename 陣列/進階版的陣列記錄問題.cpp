#include <iostream>
#include <vector>
#include <limits> // 用於輸入驗證

using namespace std;

int main() {
    int totalStudents, presentCount;

    cout << "請輸入班級總人數: ";
    cin >> totalStudents;
    cout << "請輸入實到人數: ";
    cin >> presentCount;

    // --- 輸入驗證 ---
    if (cin.fail() || totalStudents <= 0 || presentCount < 0 || presentCount > totalStudents) {
        cout << "輸入無效！請確保人數為正整數，且實到人數不大於總人數。" << endl;
        return 1;
    }

    // --- 使用 std::vector (核心改進) ---
    // 建立一個大小為「總人數+1」的布林向量，並全部初始化為 false (缺席)
    // 大小+1 是因為座號從 1 開始，我們想直接用索引 1~totalStudents 來對應
    vector<bool> attendance(totalStudents + 1, false);

    cout << "請依序輸入 " << presentCount << " 位實到同學的座號：" << endl;

    // --- 修正後的輸入迴圈 ---
    for (int i = 0; i < presentCount; i++) {
        int seatNumber;
        cin >> seatNumber;

        // 驗證座號是否在有效範圍內
        if (seatNumber > 0 && seatNumber <= totalStudents) {
            attendance[seatNumber] = true; // 將對應座號的旗標設為 true (出席)
        } else {
            cout << "座號 " << seatNumber << " 無效，已忽略。" << endl;
        }
    }

    cout << "\n缺席座號如下：" << endl;

    // --- 修正後的檢查迴圈 ---
    // 遍歷所有可能的座號 (從 1 到 總人數)
    bool anyAbsent = false;
    for (int i = 1; i <= totalStudents; i++) {
        // 如果該座號仍然是 false，代表缺席
        if (!attendance[i]) {
            cout << i << " ";
            anyAbsent = true;
        }
    }

    if (!anyAbsent) {
        cout << "全員到齊！" << endl;
    } else {
        cout << endl;
    }

    return 0;
}