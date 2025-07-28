//找出一串整數中的最大值及其出現位置
#include <iostream>
#include <vector>
#include <utility> // 為了使用 pair

using namespace std;

pair<int, int> findMaxValueAndPosition(const vector<int>& data) {
    if (data.empty() || data[0] == 0) {
        return {-1, -1};
    }

    int count = data[0];
    int max_value = data[1];
    int max_position = 1;

    for (int i = 1; i < count; ++i) {
        if (data[i + 1] > max_value) {
            max_value = data[i + 1];
            max_position = i + 1;
        }
    }
    return {max_value, max_position};
}

int main() {
    vector<int> input_data = {5, 1, 9, 6, 8, 3};
    
    cout << "輸入資料: ";
    for(size_t i = 1; i < input_data.size(); ++i) {
        cout << input_data[i] << " ";
    }
    cout << endl;
    
    pair<int, int> result = findMaxValueAndPosition(input_data);

    if (result.first != -1) {
        cout << "最大值為: " << result.first << endl;
        cout << "出現位置為: " << result.second << endl;
    } else {
        cout << "無有效資料" << endl;
    }

    return 0;
}