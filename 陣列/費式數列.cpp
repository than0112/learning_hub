#include <iostream>

using namespace std;

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1;

    long long a = 1;
    long long b = 1;
    long long temp;

    for (int i = 3; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n = 10;
    long long fib_val = fibonacci(n);
    cout << "費氏數列的第 " << n << " 項是: " << fib_val << endl;
    
    n = 45;
    fib_val = fibonacci(n);
    cout << "費氏數列的第 " << n << " 項是: " << fib_val << endl;

    return 0;
}