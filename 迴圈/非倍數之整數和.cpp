//求1到1000非三以及非七之倍數的和
#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i % 3 != 0 && i % 7 != 0) {
            sum += i;
        }
    }
    cout << "1到1000非三以及非七之倍數的和為: " << sum << endl;
    return 0;
}