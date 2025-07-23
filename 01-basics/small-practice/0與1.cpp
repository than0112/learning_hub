#include <iostream>
using namespace std;

int main() {
    int input;
    cout << "Please input 0 or 1: ";
    cin >> input;
    
    // Print the opposite value
    cout <<input<<"的反值"<< !input << endl;
    
    return 0;
}

