#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
string twoSort(vector<string> s)
{
    sort(s.begin(), s.end());
    string first = s[0];
    string result;
    for (size_t i = 0; i < first.size(); ++i) {
        result += first[i];
        if (i < first.size() - 1) {
            result += "***";
        }
    }
    return result;
}