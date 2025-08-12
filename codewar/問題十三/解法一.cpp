#include <iostream>
#include <vector>
#include <numeric>  //accumulate
using namespace  std;
int findEvenIndex(const vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int leftSum = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        int rightSum = totalSum - leftSum - arr[i];
        if (leftSum == rightSum) {
            return static_cast<int>(i);
        }
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    vector<int> test1 = {1, 2, 3, 4, 3, 2, 1};
    vector<int> test2 = {1, 100, 50, -51, 1, 1};
    vector<int> test3 = {20, 10, -80, 10, 10, 15, 35};

    cout << "test1 結果索引: " << findEvenIndex(test1) << endl; // 3
    cout << "test2 結果索引: " << findEvenIndex(test2) << endl; // 1
    cout << "test3 結果索引: " << findEvenIndex(test3) << endl; // 0

    return 0;
}
