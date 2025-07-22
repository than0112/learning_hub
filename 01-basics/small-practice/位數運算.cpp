//輸入兩個整數a,b 
//將此兩數以十六進位制方式進行and or xor 運算 ,a,b兩數也個別進行NOT運算並輸出各項結果
#include <iostream>
#include <iomanip> // 引入 iomanip 以使用 setprecision
using namespace std;
int main() {
    int a, b;
    cout << "請輸入兩個整數 a 和 b：";
    cin >> a >> b;

    // 輸出十六進位制格式
    cout << "a = " << hex << a << endl;
    cout << "b = " << hex << b << endl;

    // AND 運算
    cout << "a AND b = " << hex << (a & b) << endl;

    // OR 運算
    cout << "a OR b = " << hex << (a | b) << endl;

    // XOR 運算
    cout << "a XOR b = " << hex << (a ^ b) << endl;

    // NOT 運算
    cout << "~a = " << hex << (~a) << endl;
    cout << "~b = " << hex << (~b) << endl;

    return 0;
}