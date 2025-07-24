/*進階版的猜數字遊戲
猜測次數限制：玩家只有有限的機會。

難度選擇：玩家可以選擇不同的數字範圍和猜測次數。

遊戲紀錄：顯示玩家過去猜過的數字。

再次遊玩：遊戲結束後，可以選擇再玩一局。
最下面有random寫法的解釋以及清除輸入的解釋
*/
#include <iostream>
#include <random>
#include <vector>
#include <limits>
#include <algorithm> // 為了使用 sort

using namespace std;

void playGame() {
    int max_number = 100;
    int max_guesses = 7;
    int difficulty;

    cout << "\n--- 新遊戲 ---" << endl;
    cout << "請選擇難度: (1)簡單 1-50 (2)普通 1-100 (3)困難 1-200" << endl;
    cin >> difficulty;
    
    if (difficulty == 1) {
        max_number = 50;
        max_guesses = 6;
    } else if (difficulty == 3) {
        max_number = 200;
        max_guesses = 8;
    }
    // 其他輸入都視為普通難度

    // --- 使用 <random> 產生亂數 ---
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, max_number);
    int answer = distribution(generator);
    
    int guess = 0;
    int guess_count = 0;
    bool guessed_correctly = false;
    vector<int> guess_history; // 儲存猜過的數字

    cout << "我已經想好了一個 1 到 " << max_number << " 之間的數字。" << endl;
    cout << "你有 " << max_guesses << " 次機會。" << endl;

    // --- 主遊戲迴圈 (用 for 迴圈來限制次數) ---
    for (guess_count = 1; guess_count <= max_guesses; guess_count++) {
        cout << "\n第 " << guess_count << " 次猜測，請輸入你的數字: ";
        




        // --- 輸入驗證 ---
        while (!(cin >> guess)) {
            cout << "輸入無效，請重新輸入一個整數: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
/*cin.ignore(numeric_limits<streamsize>::max(), '\n');這行程式碼其實是呼叫了 cin 的 ignore() 函式，並傳給它兩個參數。

1. cin.ignore(...)
這是 cin 物件的一個成員函式，意思是「請忽略接下來的輸入」。它會從輸入緩衝區中讀取並丟棄字元。

2. numeric_limits<streamsize>::max() (第一個參數：數量)
這是 ignore 的第一個參數，用來指定最多要忽略多少個字元。

numeric_limits<streamsize>::max() 是一個 C++ 標準函式庫 <limits> 中的固定寫法，它會回傳 streamsize 型別所能表示的最大值。

簡單來說：它就是 C++ 語言中，代表「一個非常非常大的數字」的標準寫法，你可以把它理解成「無限大」。

在比喻中：我們告訴清理人員：「你最多可以清理掉天文數字那麼多的商品...」

3. '\n' (第二個參數：停止字元)
這是 ignore 的第二個參數，稱為分隔符 (delimiter) 或「停止字元」。

ignore() 函式會一直讀取並丟棄字元，直到它讀到並丟棄了這個 '\n' 字元為止，然後就會立刻停下來。\n 就是你按下 Enter 鍵時產生的換行符號。

在比喻中：「只要你一看到『換行符號』這個商品，就立刻收工停下來。」*/

        guess_history.push_back(guess); // 記錄這次的猜測

        if (guess > answer) {
            cout << "太大了！" << endl;
        } else if (guess < answer) {
            cout << "太小了！" << endl;
        } else {
            cout << "恭喜你，猜對了！" << endl;
            cout << "你在第 " << guess_count << " 次猜中了答案 " << answer << "。" << endl;
            guessed_correctly = true;
            break; // 猜對了，跳出迴圈
        }
        
        // 顯示猜過的數字
        cout << "你已經猜過: ";
        sort(guess_history.begin(), guess_history.end());
        for (int num : guess_history) {
            cout << num << " ";
        }
        cout << endl;
    }

    // --- 遊戲結束判斷 ---
    if (!guessed_correctly) {
        cout << "\n遊戲結束！你已經用完了所有機會。" << endl;
        cout << "正確的答案是 " << answer << "。" << endl;
    }
}

int main() {
    char play_again = 'y';

    cout << "歡迎來到猜數字遊戲！" << endl;

    // --- 再次遊玩迴圈 ---
    do {
        playGame(); // 執行一局遊戲
        cout << "\n你要再玩一局嗎? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');
    
    cout << "感謝遊玩！" << endl;
    return 0;
}






/*1. random_device rd;
這是什麼？：「真亂數設備 (True Random Device)」

作用：這是獲取高品質隨機種子 (seed) 的來源。它會向作業系統或硬體索取一個非確定性的亂數。這個數字的來源可能包含了環境噪音、滑鼠移動的時間間隔、網路封包的延遲等等，因此被認為是「真正的」亂數。

比喻：它就像是用一個物理上絕對公平的機器來擲第一次骰子，得到一個無法預測的初始點數。

2. mt19937 generator(rd());
這是什麼？：「偽亂數引擎 (Pseudo-random number engine)」

作用：mt19937 (梅森旋轉演算法) 是一個非常優秀的演算法，它接收一個「種子」(來自 rd())，然後可以產生一長串在統計上看起來非常隨機的數字序列。

generator：根據這個演算法建立出來的一個「產生器」物件。

比喻：generator 就像一個技巧高超的發牌員。你給了他一副用真亂數洗好的牌（rd() 種子），之後他就可以按照一個極其複雜但固定的順序來發牌（產生數字）。如果你給他一副同樣順序的牌，他發出來的牌序也必定相同。

3. uniform_int_distribution<int> distribution(1, max_number);
這是什麼？：「分佈器 (Distribution)」

作用：亂數引擎 (generator) 產生的原始數字通常是一個非常大的整數，範圍不固定。分佈器的作用就是將這些原始亂數，轉換並映射到你指定的範圍和分佈中。

uniform_int_distribution<int>(1, max_number)：代表想要一個「整數」的「均勻分佈」，且範圍落在 1 到 max_number 之間（包含兩端）。「均勻分佈」保證了這個範圍內的每個數字被抽中的機率都是相等的。

比喻：分佈器就像一個「規則轉換器」。發牌員（引擎）可能給你一張很大的牌，例如「黑桃 K」，但你想要的只是一個 1 到 6 的骰子點數。分佈器就會根據公平的規則，將「黑桃 K」轉換成一個 1 到 6 之間的數字。

4. int answer = distribution(generator);
這是什麼？：「產生最終亂數」

作用：這是將前面三樣東西組合起來，實際產出成果的步驟。

流程：

呼叫 distribution 物件。

將 generator 引擎傳給它。

distribution 會向 generator 索取下一個原始亂數。

distribution 根據自己的規則（均勻分佈在 1 到 max_number），將這個原始亂數轉換成最終結果。

將這個符合所有要求的亂數，賦值給 answer。*/