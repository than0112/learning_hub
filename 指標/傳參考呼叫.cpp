#include <iostream>
#include <string>
#include <vector>


using namespace std;

// --- 範例 1: 主廚修改菜單 ---
// 生活情境：餐廳的行政主廚要更新菜單。他不是拿著菜單的影本，
// 而是直接在「公佈欄上的那份原始菜單」(原始變數) 上進行修改。
// 函式中的 recipeName 就是原始菜單的一個「綽號」。
void updateMenu(string &recipeName) {
    cout << "  [函式內部] 主廚拿到了菜單的「授權別名」。\n";
    cout << "  [函式內部] 正在將「今日特餐」改為「豪華海鮮披薩」...\n";
    recipeName = "豪華海鮮披薩"; // 直接透過綽號修改
    cout << "  [函式內部] 菜單更新完畢。\n";
}

// --- 範例 2: 團隊共編線上文件 ---
// 生活情境：你和同事在線上共編一份文件。你請同事幫你加上結論。
// 同事操作的不是文件的複本，而是直接在「雲端的那份共享文件」(原始變數) 上寫入內容。
void coEditDocument(string &document) {
    cout << "  [函式內部] 同事打開了共享文件的「編輯權限」。\n";
    document += "\n結論：這是一個非常有潛力的專案。"; // 透過綽號在文件末尾追加內容
    cout << "  [函式內部] 同事已將結論寫入。\n";
}

// --- 範例 3: 健身教練調整訓練計畫 ---
// 生活情境：你的健身教練認為你進步了，需要增加訓練強度。
// 他直接拿出你的「訓練日誌」(原始變數)，把深蹲的次數從 10 次改成 15 次。
void adjustWorkoutPlan(int &squatReps) {
    cout << "  [函式內部] 教練正在查看你的「訓練日誌」。\n";
    squatReps += 5; // 透過綽號直接增加次數
    cout << "  [函式內部] 深蹲次數已更新！\n";
}

// --- 範例 4: 為汽車加油 ---
// 生活情境：你的車快沒油了，開到加油站。加油員把油槍插入你的「油箱」(原始變數)，
// 直接增加了你車子的真實油量。
void refuelCar(double &fuelTankLevel) {
    cout << "  [函式內部] 油槍已連接到你的「油箱」。\n";
    fuelTankLevel = 100.0; // 直接將油箱加滿
    cout << "  [函式內部] 油已加滿！\n";
}

// --- 範例 5: 為手機充電 ---
// 生活情境：手機電量只剩 15%。你將充電線插入手機，
// 電流直接充入你的「手機電池」(原始變數)，使其電量百分比真實地增加。
void chargePhone(int &batteryPercentage) {
    cout << "  [函式內部] 充電器已連接到「手機電池」。\n";
    if (batteryPercentage < 100) {
        batteryPercentage += 50; // 增加 50% 電量
        if (batteryPercentage > 100) {
            batteryPercentage = 100; // 最多只能到 100%
        }
    }
    cout << "  [函式內部] 充電完成。\n";
}


// --- 主程式：我們的現實世界 ---
int main() {
    cout << "====== 傳參考呼叫 (Call by Reference) 生活化範例 ======\n";
    cout << "核心概念：函式取得了變數的「綽號」(引用)，操作即是修改「正本」。\n";

    // --- 範例 1 ---
    cout << "\n--- 1. 主廚修改菜單 ---\n";
    string todaySpecial = "今日特餐"; // 餐廳的原始菜單
    cout << "[主程式] 修改前，菜單上寫著: \"" << todaySpecial << "\"\n";
    updateMenu(todaySpecial); // 將菜單的「授權別名」交給主廚
    cout << "[主程式] 修改後，菜單上寫著: \"" << todaySpecial << "\"\n";

    // --- 範例 2 ---
    cout << "\n--- 2. 團隊共編線上文件 ---\n";
    string sharedDoc = "專案目標：提升使用者體驗。"; // 雲端上的共享文件
    cout << "[主程式] 修改前，文件內容是:\n" << sharedDoc << "\n";
    coEditDocument(sharedDoc); // 同事獲得文件的編輯權限
    cout << "[主程式] 修改後，文件內容是:\n" << sharedDoc << "\n";

    // --- 範例 3 ---
    cout << "\n--- 3. 健身教練調整訓練計畫 ---\n";
    int mySquats = 10; // 我的訓練日誌正本
    cout << "[主程式] 調整前，我的深蹲計畫是: " << mySquats << " 次。\n";
    adjustWorkoutPlan(mySquats); // 教練直接修改我的日誌
    cout << "[主程式] 調整後，我的深蹲計畫變為: " << mySquats << " 次。\n";

    // --- 範例 4 ---
    cout << "\n--- 4. 為汽車加油 ---\n";
    double myCarFuel = 20.0; // 我車子油箱的真實油量
    cout << "[主程式] 加油前，我的油量是: " << myCarFuel << "%。\n";
    refuelCar(myCarFuel); // 加油員直接操作我的油箱
    cout << "[主程式] 加油後，我的油量變為: " << myCarFuel << "%。\n";

    // --- 範例 5 ---
    cout << "\n--- 5. 為手機充電 ---\n";
    int phoneBattery = 15; // 手機的真實電量
    cout << "[主程式] 充電前，手機電量為: " << phoneBattery << "%。\n";
    chargePhone(phoneBattery); // 充電器直接為電池充電
    cout << "[主程式] 充電後，手機電量變為: " << phoneBattery << "%。\n";

    return 0;
}
