#include <iostream>
#include <cmath> // 用於 sqrt, pow
#include <numeric> // 在未來可能用於 numeric algorithms

// 使用 std 命名空間，讓程式碼更簡潔
using namespace std;

// --- 函式原型宣告 (Function Prototypes) ---
// 就像一本書的目錄，讓主程式知道有哪些章節(函式)可以查閱。
void problem1();
void problem2();
void problem3();
void problem4();
void problem6();
void problem7();

// --- 主程式：我們的指揮中心 ---
int main() {
    int choice;
    do {
        // 顯示互動式選單
        cout << "\n\n====================================\n";
        cout << "   C++ 函數應用題專家詳解\n";
        cout << "====================================\n";
        cout << "1. 判斷整數正負 (Sign Function)\n";
        cout << "2. 找出區間內的質數 (Prime Numbers in Range)\n";
        cout << "3. 計算平面兩點距離 (Distance Formula)\n";
        cout << "4. 最大公因數與最小公倍數 (GCD & LCM)\n";
        cout << "6. 存款與利率計算 (Compound Interest)\n";
        cout << "7. 找出親和數 (Friendly Numbers)\n";
        cout << "0. 離開程式\n";
        cout << "------------------------------------\n";
        cout << "請選擇要執行的題目: ";
        cin >> choice;

        // 根據使用者的選擇，呼叫對應的函式
        switch (choice) {
            case 1: problem1(); break;
            case 2: problem2(); break;
            case 3: problem3(); break;
            case 4: problem4(); break;
            case 6: problem6(); break;
            case 7: problem7(); break;
            case 0: cout << "感謝使用，程式結束。\n"; break;
            default: cout << "無效的選擇，請重新輸入。\n"; break;
        }
    } while (choice != 0);

    return 0;
}

// ===================================================================
//   第一題：判斷整數正負 (Sign Function)
// ===================================================================
/**
 * @brief 判斷一個整數的符號。
 * @param n 要判斷的整數。
 * @return int 1 代表正數, -1 代表負數, 0 代表零。
 */
int getSign(int n) {
    if (n > 0) {
        return 1;
    } else if (n < 0) {
        return -1;
    } else {
        return 0;
    }
}

void problem1() {
    cout << "\n--- 第一題：判斷整數正負 ---\n";
    cout << "生活化解釋：這就像一個裁判，看到正數就舉代表「加分」的牌子(1)，\n";
    cout << "看到負數就舉代表「扣分」的牌子(-1)，看到零分就表示「平手」(0)。\n\n";
    
    int num;
    cout << "請輸入一個整數: ";
    cin >> num;
    cout << "此數字的符號為: " << getSign(num) << endl;
}

// ===================================================================
//   第二題：找出區間內的質數 (Prime Numbers in Range)
// ===================================================================
/**
 * @brief 檢查一個數字是否為質數。
 * @param n 要檢查的數字。
 * @return bool true 代表是質數, false 代表不是。
 */
bool isPrime(int n) {
    if (n <= 1) return false; // 質數必須大於 1
    // 從 2 檢查到 n 的平方根即可
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // 發現因數，不是質數
        }
    }
    return true; // 都沒有因數，是質數
}

void problem2() {
    cout << "\n--- 第二題：找出區間內的質數 ---\n";
    cout << "生活化解釋：質數就像一個「孤僻」的數字，除了 1 跟它自己，\n";
    cout << "它不喜歡跟任何其他數字整除。我們的程式就像一個星探，\n";
    cout << "在一個數字範圍內，把這些特別的「孤僻數」找出來。\n\n";

    int m, n;
    cout << "請輸入區間的起始值 m: ";
    cin >> m;
    cout << "請輸入區間的結束值 n: ";
    cin >> n;

    cout << m << " 到 " << n << " 之間的質數有: ";
    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// ===================================================================
//   第三題：計算平面兩點距離 (Distance Formula)
// ===================================================================
/**
 * @brief 計算平面上兩點之間的直線距離。
 * @param x1, y1 第一個點的座標。
 * @param x2, y2 第二個點的座標。
 * @return double 兩點的距離。
 */
double calculateDistance(double x1, double y1, double x2, double y2) {
    // 使用畢氏定理: d = sqrt((x2-x1)^2 + (y2-y1)^2)
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void problem3() {
    cout << "\n--- 第三題：計算平面兩點距離 ---\n";
    cout << "生活化解釋：想像你在地圖上，想知道從你家到學校的「直線距離」。\n";
    cout << "你不能沿著街道走，而是像一隻鳥一樣直接飛過去。\n";
    cout << "這個函式就是幫你計算這條空中直線的長度。\n\n";

    double x1, y1, x2, y2;
    cout << "請輸入第一個點的座標 (a b): ";
    cin >> x1 >> y1;
    cout << "請輸入第二個點的座標 (c d): ";
    cin >> x2 >> y2;
    
    cout << "兩點之間的距離是: " << calculateDistance(x1, y1, x2, y2) << endl;
}

// ===================================================================
//   第四題：最大公因數與最小公倍數 (GCD & LCM)
// ===================================================================
/**
 * @brief 使用遞迴的輾轉相除法計算最大公因數 (GCD)。
 * @param m, n 兩個非負整數。
 * @return int 最大公因數。
 */
int gcd(int m, int n) {
    if (n == 0) {
        return m; // 基本情況：當 n 為 0，m 就是答案
    } else {
        return gcd(n, m % n); // 遞迴關係：問題規模縮小
    }
}

/**
 * @brief 計算最小公倍數 (LCM)。
 * @param a, b 兩個正整數。
 * @return int 最小公倍數。
 */
long long lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    // 使用公式: a * b = gcd(a, b) * lcm(a, b)
    // 為了避免溢位，先除再乘
    return static_cast<long long>(a) / gcd(a, b) * b;
}
/*為了計算最小公倍數，我們先將 a 除以最大公因數，再乘以 b（這是為了防止中間計算溢位）。同時，在整個計算開始前，先把 a 轉成容量更大的 long long 型別，以確保最終的巨大結果也能被正確儲存。」
*/

void problem4() {
    cout << "\n--- 第四題：最大公因數與最小公倍數 ---\n";
    cout << "生活化解釋 (GCD)：想像你有兩條不同長度的緞帶，\n";
    cout << "想把它們剪成「等長」且「最長」的小段，不能有剩餘。\n";
    cout << "這個「最長的小段長度」就是最大公因數。\n";
    cout << "遞迴就像一個聰明的裁縫，不斷用短的去量長的，把問題變小，直到完美解決。\n\n";
    cout << "生活化解釋 (LCM)：你和朋友繞著操場跑步，你跑一圈3分鐘，他跑一圈5分鐘。\n";
    cout << "你們想知道下一次在「起點」相遇是幾分鐘後？\n";
    cout << "這個時間點（15分鐘）就是最小公倍數。\n\n";

    int a, b, c;
    cout << "請輸入三個正整數 (a b c): ";
    cin >> a >> b >> c;

    // (1) 計算 a, b 的 GCD
    cout << a << " 和 " << b << " 的最大公因數 (GCD) 是: " << gcd(a, b) << endl;
    
    // (2) 計算 a, b 的 LCM
    cout << a << " 和 " << b << " 的最小公倍數 (LCM) 是: " << lcm(a, b) << endl;

    // (3) 計算 a, b, c 的 GCD 和 LCM
    int gcd_abc = gcd(gcd(a, b), c);
    long long lcm_abc = lcm(lcm(a, b), c);
    cout << a << ", " << b << ", " << c << " 的最大公因數是: " << gcd_abc << endl;
    cout << a << ", " << b << ", " << c << " 的最小公倍數是: " << lcm_abc << endl;
}

// ===================================================================
//   第六題：存款與利率計算 (Compound Interest)
// ===================================================================
/**
 * @brief 計算本利和。
 * @param principal 本金。
 * @param annualRate 年利率 (例如 0.05 代表 5%)。
 * @param days 存款天數。
 * @return double 本利和。
 */
double calculateFinalAmount(double principal, double annualRate, int days) {
    double dailyRate = annualRate / 365.0;
    return principal * pow(1 + dailyRate, days);
}
/**
 * @brief 根據本利和反推本金。
 * @param finalAmount 本利和。
 * @param annualRate 年利率。
 * @param days 存款天數。
 * @return double 需要的本金。
 */
double calculatePrincipal(double finalAmount, double annualRate, int days) {
    double dailyRate = annualRate / 365.0;
    return finalAmount / pow(1 + dailyRate, days);
}

void problem6() {
    cout << "\n--- 第六題：存款與利率計算 ---\n";
    cout << "生活化解釋：這就是「利滾利」的複利魔法！\n";
    cout << "你的存款就像一個小雪球，每天銀行給你的利息會讓雪球變大一點點，\n";
    cout << "隔天，這個稍大的雪球會滾到更多的雪(利息)。\n";
    cout << "這個函式可以幫你預測雪球滾了n天後會變多大，或者反推一開始需要多大的雪球。\n\n";

    double r, x;
    int n;
    cout << "請輸入年利率 r (例如輸入 0.02 代表 2%): ";
    cin >> r;
    cout << "請輸入存款天數 n: ";
    cin >> n;
    cout << "請輸入本金 x: ";
    cin >> x;

    double finalAmount = calculateFinalAmount(x, r, n);
    cout << "存入 " << x << " 元，" << n << " 天後，本利和會變成: " << finalAmount << " 元" << endl;
    
    double requiredPrincipal = calculatePrincipal(finalAmount, r, n);
    cout << "反推：若 " << n << " 天後想得到 " << finalAmount << " 元，需存入本金: " << requiredPrincipal << " 元" << endl;
}

// ===================================================================
//   第七題：找出親和數 (Friendly Numbers)
// ===================================================================
/**
 * @brief 計算一個數的所有真因數(不含本身)的和。
 * @param n 要計算的數字。
 * @return int 真因數和。
 */
int sumOfProperDivisors(int n) {
    if (n <= 1) return 0;
    int sum = 1; // 1 永遠是真因數
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) { // 避免重複加平方根
                sum += n / i;
            }
        }
    }
    return sum;
}

void problem7() {
    cout << "\n--- 第七題：找出親和數 ---\n";
    cout << "生活化解釋：親和數就像一對「知己」。\n";
    cout << "數字 A 所有的朋友(因數)加起來，剛好等於數字 B。\n";
    cout << "而神奇的是，數字 B 所有的朋友加起來，也剛好等於數字 A。\n";
    cout << "它們互相欣賞，構成一種數學上的友誼。我們的程式就是要找出這些特別的數字配對。\n\n";
    cout << "正在 1 到 500 的範圍內尋找親和數...\n";

    for (int a = 1; a <= 500; a++) {
        int b = sumOfProperDivisors(a);
        // 條件：b > a 是為了避免重複輸出 (例如 220,284 和 284,220)
        // 且 sumOfProperDivisors(b) == a 才構成親和數對
        if (b > a && sumOfProperDivisors(b) == a) {
            cout << "找到一對親和數: (" << a << ", " << b << ")" << endl;
        }
    }
}