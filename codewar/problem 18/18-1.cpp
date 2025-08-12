#include <iostream>
#include <vector>
#include <string>
#include <utility> // 用於 std::pair
#include <unordered_map> // 高效的雜湊表，用於建立路線圖
#include <unordered_set> // 高效的集合，用於快速尋找起點

using namespace std;

/**
 * @brief 根據一系列被打亂的行程，拼湊出正確的旅行路線。
 * @param routes 一個包含多個行程片段的向量，每個片段都是一個 pair (起點, 終點)。
 * @return std::string 依正確順序排列的完整路線字串。
 */
string find_routes(const vector<pair<string, string>>& routes) {
    // --- 演算法邏輯 ---

    // 1. 建立兩個資料結構來幫助我們分析路線：
    //    a. 一個「路線圖」(雜湊表)，讓我們可以從一個城市快速查到下一個目的地。
    //    b. 一個「所有抵達點」的集合，用來快速判斷一個城市是不是別人的終點。
    unordered_map<string, string> route_map;
    unordered_set<string> arrival_cities;

    // 2. 遍歷所有行程片段，填充我們的路線圖和抵達點集合。
    for (const auto& route : routes) {
        route_map[route.first] = route.second; // 例如：route_map["USA"] = "BRA"
        arrival_cities.insert(route.second);   // 將所有抵達點加入集合
    }

    // 3. 找出整個旅程的唯一「起點」。
    //    起點的特徵是：它是一個出發點，但「絕對不是」任何一個行程的抵達點。
    string start_city = "";
    for (const auto& route : routes) {
        // 檢查這個行程的出發點 route.first 是否存在於「抵達點集合」中
        if (arrival_cities.count(route.first) == 0) {
            // 如果不在，代表它就是我們要找的唯一起點！
            start_city = route.first;
            break; // 找到後就跳出迴圈
        }
    }

    // 如果沒有找到起點 (雖然題目保證一定有)，直接回傳空字串
    if (start_city.empty()) {
        return "";
    }

    // 4. 從起點開始，一步步地拼湊出完整路線。
    string result = start_city;
    string current_city = start_city;

    // 只要當前的城市還能在我們的「路線圖」上找到下一個目的地，就繼續走
    while (route_map.count(current_city)) {
        current_city = route_map.at(current_city); // 前往下一站
        result += ", " + current_city;             // 將新地點加入結果中
    }

    return result;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param routes 要測試的行程向量。
 */
void run_test(const vector<pair<string, string>>& routes) {
    cout << "輸入的行程片段：" << endl;
    for (const auto& r : routes) {
        cout << "  [" << r.first << ", " << r.second << "]" << endl;
    }
    cout << "解密後的完整路線：" << endl;
    cout << "  \"" << find_routes(routes) << "\"" << endl;
}

// --- 主程式：用來測試 find_routes 函式 ---
int main() {
    cout << "--- 解密行程測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    vector<pair<string, string>> example_routes = {
        {"USA", "BRA"},
        {"JPN", "PHL"},
        {"BRA", "UAE"},
        {"UAE", "JPN"}
    };
    run_test(example_routes); 
    // 預期輸出: "USA, BRA, UAE, JPN, PHL"

    cout << "\n測試結束。\n";
    return 0;
}
