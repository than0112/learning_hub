#include <iostream>
#include <string>

// 使用 std 命名空間，讓程式碼更簡潔
using namespace std;

// --- 範例 1: 試算食譜的糖量 ---
// 生活情境：你朋友想做蛋糕，但不喜歡太甜。你把你的食譜糖量告訴他，
// 他在腦中盤算著把糖量減半，但你書上的原始食譜並沒有因此被修改。
void checkRecipe(int sugarAmount) {
    cout << "   朋友拿到食譜的糖量影本: " << sugarAmount << " 克。\n";
    // 朋友在腦中把糖量減半來試算
    sugarAmount = sugarAmount / 2;
    cout << "  朋友在腦中試算，糖量減半為: " << sugarAmount << " 克。\n";
    cout << "  試算結束，影本被丟棄。\n";
}

// --- 範例 2: 使用優惠券計算商品價格 ---
// 生活情境：一件商品標價 500 元。你拿著 100 元的優惠券去結帳。
// 收銀機(函式)根據你報的價格和優惠券計算出應付金額，但商品上的原始標價不會被改變。
double calculateFinalPrice(double originalPrice, double couponValue) {
    cout << "  收銀機讀取到價格影本: " << originalPrice << " 元。\n";
    // 收銀機計算折扣後價格
    double finalPrice = originalPrice - couponValue;
    return finalPrice; // 回傳最終計算結果
}

// --- 範例 3: 健身 APP 預測體重 ---
// 生活情境：你目前的體重是 70 公斤。你打開一個健身 APP，輸入你的體重，
// APP 預測你運動一個月後體重可能會下降。這個預測結果並不會馬上改變你現在的體重。
void predictWeightLoss(double currentWeight) {
    cout << "   APP 接收到你的體重影本: " << currentWeight << " 公斤。\n";
    // APP 進行預測
    currentWeight = currentWeight - 2.5;
    cout << "   APP 預測一個月後，你的體重可能是: " << currentWeight << " 公斤。\n";
}

// --- 範例 4: 翻譯一個單字 ---
// 生活情境：你想知道 "Apple" 的中文是什麼。你把 "Apple" 這個字告訴翻譯員(函式)。
// 翻譯員告訴你答案是「蘋果」，但你原本想查的 "Apple" 這個字本身並沒有消失或改變。
string translateToChinese(string englishWord) {
    cout << "  翻譯員收到了單字影本: \"" << englishWord << "\"\n";
    if (englishWord == "Apple") {
        return "蘋果";
    } else {
        return "查無此字";
    }
}

// --- 範例 5: 遊戲角色的模擬升級 ---
// 生活情境：你的遊戲角色目前是 10 等。你進入一個「訓練模擬室」(函式)來看看升級後的能力。
// 在模擬室中，角色等級提升到 11 等，但當你離開模擬室後，你的角色實際等級仍然是 10 等。
void simulateLevelUp(int playerLevel) {
    cout << "   進入模擬室，角色等級影本為: " << playerLevel << " 等。\n";
    // 在模擬中升級
    playerLevel++;
    cout << "  模擬升級！等級變為: " << playerLevel << " 等。\n";
    cout << "   離開模擬室，模擬資料消失。\n";
}
// --- 主程式：我們的現實世界 ---
int main() {
    cout << "====== 傳值呼叫 (Call by Value) 生活化範例 ======\n";
    cout << "核心概念：函式處理的都是「影本」，不會影響到「正本」。\n";

    // --- 範例 1 ---
    cout << "\n--- 1. 試算食譜的糖量 ---\n";
    int myRecipeSugar = 100; // 我的食譜正本
    cout << "我的食譜正本，糖量為: " << myRecipeSugar << " 克。\n";
    checkRecipe(myRecipeSugar); // 將糖量「告訴」朋友 (傳遞影本)
    cout << " 朋友試算完，我的食譜正本糖量依然是: " << myRecipeSugar << " 克。\n";

    // --- 範例 2 ---
    cout << "\n--- 2. 使用優惠券計算商品價格 ---\n";
    double itemPrice = 500.0; // 商品上的標價正本
    double coupon = 100.0;
    cout << " 商品標價為: " << itemPrice << " 元。\n";
    double finalPrice = calculateFinalPrice(itemPrice, coupon); // 將價格告訴收銀機
    cout << " 收銀機算出最終應付: " << finalPrice << " 元。\n";
    cout << "結帳完，商品上的原始標價依然是: " << itemPrice << " 元。\n";

    // --- 範例 3 ---
    cout << "\n--- 3. 健身 APP 預測體重 ---\n";
    double myWeight = 70.0; // 我目前的體重正本
    cout << " 我目前的體重是: " << myWeight << " 公斤。\n";
    predictWeightLoss(myWeight); // 將體重輸入到 APP 中
    cout << " APP 預測完，我目前的實際體重依然是: " << myWeight << " 公斤。\n";

    // --- 範例 4 ---
    cout << "\n--- 4. 翻譯一個單字 ---\n";
    string originalWord = "Apple"; // 我想查的單字正本
    cout << " 我想查的單字是: \"" << originalWord << "\"\n";
    string translatedWord = translateToChinese(originalWord); // 把單字告訴翻譯員
    cout << "翻譯員告訴我結果是: \"" << translatedWord << "\"\n";
    cout << " 查完字典，我原本想查的單字依然是: \"" << originalWord << "\"\n";

    // --- 範例 5 ---
    cout << "\n--- 5. 遊戲角色的模擬升級 ---\n";
    int playerLevel = 10; // 角色的實際等級正本
    cout << " 角色實際等級為: " << playerLevel << " 等。\n";
    simulateLevelUp(playerLevel); // 進入模擬室
    cout << " 離開模擬室後，角色的實際等級依然是: " << playerLevel << " 等。\n";

    return 0;
}