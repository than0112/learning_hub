#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm> // 引入 min 函式
#include <limits>    // 引入 numeric_limits

using namespace std;

// 使用 using 來建立一個型別別名，讓程式碼更清晰
using Ingredients = unordered_map<string, int>;
int cakes(const Ingredients& recipe, const Ingredients& available) {
    // 1. 初始化一個變數來追蹤最多可以做幾個蛋糕。
    //    我們使用 numeric_limits<int>::max() 來設定一個非常大的初始值，
    //    這樣在後續的計算中，任何實際的數量都會小於這個值。
    //    這樣可以確保我們在計算過程中，能夠找到最小的可做數量。
    int max_cakes_possible = numeric_limits<int>::max();

    // 2. 遍歷食譜中的每一樣必要食材。
    for (const auto& recipe_pair : recipe) {
        const string& ingredient = recipe_pair.first;
        int needed_amount = recipe_pair.second;

        // 3. 檢查我們手邊有沒有這項食材。
        //    available.count(ingredient) 會回傳 0 (沒有) 或 1 (有)。
        if (available.count(ingredient) == 0) {
            // 如果缺少任何一樣必要食材，連一個蛋糕都做不出來。
            return 0;
        }

        // 4. 取得我們現有的食材數量。
        int available_amount = available.at(ingredient);

        // 5. 計算光靠「這一種」食材，可以做出幾個蛋糕。
        //    C++ 的整數除法會自動捨去小數，這正是我們需要的。
        int possible_cakes = available_amount / needed_amount;

        // 6. 更新我們的「最多可做數量」。
        //    真正的可做數量，取決於那個最不夠用的「瓶頸食材」。
        //    所以我們在每一次計算後，都取當前最小值。
        max_cakes_possible = min(max_cakes_possible, possible_cakes);
    }
    return (max_cakes_possible == numeric_limits<int>::max()) ? 0 : max_cakes_possible;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param recipe 食譜。
 * @param available 現有食材。
 * @param expected_result 預期的結果。
 */
void run_test(const Ingredients& recipe, const Ingredients& available, int expected_result) {
    int result = cakes(recipe, available);
    cout << "計算結果: " << result 
         << " (預期: " << expected_result << ") -> " 
         << (result == expected_result ? "通過" : "失敗") << endl;
}

// --- 主程式：用來測試 cakes 函式 ---
int main() {
    cout << "--- 烘焙師皮特問題測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 範例測試案例 ---\n";

    // 測試案例 1
    Ingredients recipe1 = {{"flour", 500}, {"sugar", 200}, {"eggs", 1}};
    Ingredients available1 = {{"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}};
    run_test(recipe1, available1, 2);

    // 測試案例 2
    Ingredients recipe2 = {{"apples", 3}, {"flour", 300}, {"sugar", 150}, {"milk", 100}, {"oil", 100}};
    Ingredients available2 = {{"sugar", 500}, {"flour", 2000}, {"milk", 2000}};
    run_test(recipe2, available2, 0);

    cout << "\n測試結束。\n";
    return 0;
}
