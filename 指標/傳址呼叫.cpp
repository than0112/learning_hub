#include <iostream>
#include <string>

// 使用 std 命名空間，讓程式碼更簡潔
using namespace std;

// --- 範例 1: 銀行臨櫃存款 ---
// 生活情境：你去銀行存錢，你告訴櫃員你的「帳戶號碼」(變數的位址)。
// 櫃員根據這個號碼，直接在你「真實的帳戶餘額」(原始變數) 上加上你存入的金額。
void depositToAccount(double* accountBalance, double amount) {
    cout << "  [函式內部] 櫃員拿到了帳戶的鑰匙(位址)。\n";
    cout << "  [函式內部] 正在操作帳戶，將存入 " << amount << " 元。\n";
    // 使用 * 運算子，找到鑰匙對應的倉庫，直接修改裡面的值
    *accountBalance = *accountBalance + amount;
    cout << "  [函式內部] 操作完成。\n";
}

// --- 範例 2: 交換倉庫中的貨物 ---
// 生活情境：倉庫管理員需要交換兩個貨箱的內容物。他不需要知道貨箱裡是什麼，
// 只需要知道這兩個貨箱的「位置」(位址)，就能直接進行交換。
void swapItems(string* boxA, string* boxB) {
    cout << "  [函式內部] 管理員拿到了兩個貨箱的鑰匙(位址)。\n";
    string temp = *boxA; // 先把 A 箱的東西拿出來暫放
    *boxA = *boxB;       // 把 B 箱的東西放進 A 箱
    *boxB = temp;        // 把暫放的東西放進 B 箱
    cout << "  [函式內部] 交換完成。\n";
}

// --- 範例 3: 訓練寵物學會新技能 ---
// 生活情境：你請了一位訓練師來教你的寵物。你把寵物「交給」(傳遞位址) 訓練師。
// 訓練師直接對你的「這隻寵物」進行訓練，牠的技能等級會真實地提升。
void trainPet(int* petSkillLevel) {
    cout << "  [函式內部] 訓練師正在訓練你的寵物...\n";
    (*petSkillLevel)++; // 將技能等級加 1
    cout << "  [函式內部] 叮！寵物學會了新技能！\n";
}

// --- 範例 4: 填寫訂單狀態 ---
// 生活情境：線上購物後，你的訂單狀態一開始是「處理中」。
// 當倉庫撿貨並出貨後，系統(函式)會直接找到你的「這筆訂單」(位址)，將狀態更新為「已出貨」。
void updateOrderStatus(string* currentStatus) {
    cout << "  [函式內部] 倉庫系統找到了訂單的位址。\n";
    *currentStatus = "已出貨";
    cout << "  [函式內部] 訂單狀態已更新。\n";
}

// --- 範例 5: 將設備重置為原廠設定 ---
// 生活情境：你的手機設定有點亂，你想要恢復原廠設定。
// 重置函式需要知道你「手機設定檔」的儲存位置(位址)，才能直接將它清除並寫入預設值。
void resetToFactorySettings(int* settingValue) {
    cout << "  [函式內部] 正在重置設備...\n";
    *settingValue = 0; // 將設定值恢復為預設的 0
    cout << "  [函式內部] 重置完成。\n";
}


// --- 主程式：我們的現實世界 ---
int main() {
    cout << "====== 傳址呼叫 (Call by Address) 生活化範例 ======\n";
    cout << "核心概念：函式拿到了「鑰匙」(指標/位址)，可以直接修改「正本」。\n";

    // --- 範例 1 ---
    cout << "\n--- 1. 銀行臨櫃存款 ---\n";
    double myBalance = 1000.0; // 我真實的帳戶餘額
    cout << "[主程式] 存款前，我的帳戶餘額為: " << myBalance << " 元。\n";
    depositToAccount(&myBalance, 500.0); // 將帳戶的「位址」(&)交給櫃員
    cout << "[主程式] 存款後，我的帳戶餘額變為: " << myBalance << " 元。\n";

    // --- 範例 2 ---
    cout << "\n--- 2. 交換倉庫中的貨物 ---\n";
    string box1 = "蘋果";
    string box2 = "橘子";
    cout << "[主程式] 交換前，貨箱1裝著: " << box1 << "，貨箱2裝著: " << box2 << "。\n";
    swapItems(&box1, &box2); // 將兩個貨箱的「位址」(&)交給管理員
    cout << "[主程式] 交換後，貨箱1裝著: " << box1 << "，貨箱2裝著: " << box2 << "。\n";

    // --- 範例 3 ---
    cout << "\n--- 3. 訓練寵物學會新技能 ---\n";
    int dogSkill = 3; // 我的狗狗的技能等級
    cout << "[主程式] 訓練前，狗狗的技能等級是: " << dogSkill << "。\n";
    trainPet(&dogSkill); // 將狗狗的「位址」(&)交給訓練師
    cout << "[主程式] 訓練後，狗狗的技能等級變為: " << dogSkill << "。\n";

    // --- 範例 4 ---
    cout << "\n--- 4. 填寫訂單狀態 ---\n";
    string myOrder = "處理中"; // 我的訂單正本
    cout << "[主程式] 出貨前，我的訂單狀態是: \"" << myOrder << "\"\n";
    updateOrderStatus(&myOrder); // 倉庫系統根據「位址」(&)來更新
    cout << "[主程式] 出貨後，我的訂單狀態變為: \"" << myOrder << "\"\n";

    // --- 範例 5 ---
    cout << "\n--- 5. 將設備重置為原廠設定 ---\n";
    int userSetting = 12345; // 我亂七八糟的設定
    cout << "[主程式] 重置前，我的設定值是: " << userSetting << "\n";
    resetToFactorySettings(&userSetting); // 執行重置，傳入設定檔的「位址」(&)
    cout << "[主程式] 重置後，我的設定值變為: " << userSetting << "\n";

    return 0;
}
