#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

class WeightSort
{
public:
    static string orderWeight(const string &strng) {
        
        istringstream iss(strng);
        vector<string> nums;
        string temp;
        
        // 1. 分割數字字串（自動忽略多餘空白）
        while (iss >> temp) {
            nums.push_back(temp);
        }

        // 2. 自訂排序
        std::sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
            int wa = digitSum(a);
            int wb = digitSum(b);
            if (wa == wb)
                return a < b; // 權重相同 → 字串比較
            return wa < wb;   // 權重小的在前
        });

        // 3. 組合成輸出字串
        ostringstream oss;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0) oss << " ";
            oss << nums[i];
        }

        return oss.str();
    }

private:
    // 計算數字字串的位數總和
    static int digitSum(const string &s) {
        int sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        return sum;
    }
};
int main() {
    cout << WeightSort::orderWeight("56 65 74 100 99 68 86 180 90") << endl;
    // 預期輸出: "100 180 90 56 65 74 68 86 99"

    cout << WeightSort::orderWeight("  56  65 74  100 99   ") << endl;
    // 預期輸出: "100 56 65 74 99"
}