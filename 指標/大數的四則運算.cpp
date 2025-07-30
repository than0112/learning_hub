#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // 用於 reverse
#include <stdexcept> // 用於錯誤處理

// 使用 std 命名空間
using namespace std;

// --- 函式原型宣告 ---
string addBigIntegers(string num1, string num2);
string subtractBigIntegers(string num1, string num2);
string multiplyBigIntegers(string num1, string num2);
pair<string, long long> divideBigIntegerByLong(string num, long long divisor);
bool isSmaller(string str1, string str2);


// --- 主程式：我們的大整數計算機展示中心 ---
int main() {
    cout << "--- 大整數運算展示 ---\n";

    string a = "23456789012345678901";
    string b = "9876543210987654321";

    cout << "大整數 A: " << a << endl;
    cout << "大整數 B: " << b << endl;
    cout << "------------------------------------\n";

    // 加法
    cout << "A + B = " << addBigIntegers(a, b) << endl;

    // 減法
    cout << "\nA - B = " << subtractBigIntegers(a, b) << endl;
    cout << "B - A = " << subtractBigIntegers(b, a) << endl;

    // 乘法
    string c = "12345";
    string d = "54321";
    cout << "\n--- 乘法測試 ---\n";
    cout << "C = " << c << endl;
    cout << "D = " << d << endl;
    cout << "C * D = " << multiplyBigIntegers(c, d) << endl;

    // 除法
    string e = "123456789123456789";
    long long f = 9876;
    cout << "\n--- 除法測試 ---\n";
    cout << "E = " << e << endl;
    cout << "f = " << f << endl;
    pair<string, long long> result = divideBigIntegerByLong(e, f);
    cout << "E / f 的商是: " << result.first << endl;
    cout << "E / f 的餘數是: " << result.second << endl;

    return 0;
}


// ===================================================================
//   大整數加法 (已在先前提供)
// ===================================================================
string addBigIntegers(string num1, string num2) {
    string sum = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int currentSum = digit1 + digit2 + carry;
        sum += to_string(currentSum % 10);
        carry = currentSum / 10;
    }
    reverse(sum.begin(), sum.end());
    return sum;
}

// ===================================================================
//   大整數減法
// ===================================================================
// 生活化解釋：就像「直式減法」。從個位數開始減，不夠減就跟前一位「借位」。
// 我們要先判斷哪個數字大，用大數減小數，如果順序是反的，最後再補上負號。

// 輔助函式：判斷 str1 是否小於 str2
bool isSmaller(string str1, string str2) {
    int n1 = str1.length(), n2 = str2.length();
    if (n1 < n2) return true;
    if (n2 < n1) return false;
    // 長度相同，從頭開始比較
    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i]) return true;
        if (str1[i] > str2[i]) return false;
    }
    return false; // 兩數相等
}

string subtractBigIntegers(string num1, string num2) {
    // 判斷結果是否為負
    bool isNegative = false;
    if (isSmaller(num1, num2)) {
        isNegative = true;
        swap(num1, num2); // 用大數減小數
    }

    string result = "";
    int n1 = num1.length(), n2 = num2.length();
    int i = n1 - 1, j = n2 - 1;
    int borrow = 0;

    while (j >= 0 || i >= 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        int currentSub = digit1 - digit2 - borrow;
        
        if (currentSub < 0) {
            currentSub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += to_string(currentSub);
    }

    // 去除結果前端多餘的 0
    reverse(result.begin(), result.end());
    size_t first_digit = result.find_first_not_of('0');
    if (string::npos != first_digit) {
        result = result.substr(first_digit);
    } else {
        return "0"; // 結果為 0
    }

    // 如果結果為負，加上負號
    if (isNegative) {
        return "-" + result;
    }
    return result;
}


// ===================================================================
//   大整數乘法
// ===================================================================
// 生活化解釋：模擬「直式乘法」。將第一個數的每一位，依序乘以第二個數，
// 然後將每次得到的結果，錯位相加。就像我們在紙上算的一樣。

string multiplyBigIntegers(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int n1 = num1.length();
    int n2 = num2.length();
    vector<int> result(n1 + n2, 0); // 結果最多為 n1+n2 位

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int digit1 = num1[i] - '0';
        i_n2 = 0;

        for (int j = n2 - 1; j >= 0; j--) {
            int digit2 = num2[j] - '0';
            int sum = digit1 * digit2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0) {
            result[i_n1 + i_n2] += carry;
        }
        i_n1++;
    }

    // 去除前導 0
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0) i--;
    if (i == -1) return "0";

    string s = "";
    while (i >= 0) s += to_string(result[i--]);

    return s;
}

// ===================================================================
//   大整數除以小整數 (long long)
// ===================================================================
// 生活化解釋：模擬「長除法」。從大數的最左邊開始，一位一位地取出數字，
// 看看夠不夠除。夠除就計算商和餘數，然後把餘數和下一位數字組合起來，
// 繼續往下除，直到大數的每一位都被處理完。

pair<string, long long> divideBigIntegerByLong(string num, long long divisor) {
    if (divisor == 0) {
        throw invalid_argument("除數不能為零");
    }

    string quotient = "";
    long long temp = 0;
    
    for (int i = 0; i < num.length(); i++) {
        temp = temp * 10 + (num[i] - '0');
        quotient += to_string(temp / divisor);
        temp = temp % divisor;
    }

    // 去除商的前導 0
    size_t first_digit = quotient.find_first_not_of('0');
    if (string::npos != first_digit) {
        quotient = quotient.substr(first_digit);
    } else {
        return {"0", temp}; // 商為 0
    }

    return {quotient, temp};
}
