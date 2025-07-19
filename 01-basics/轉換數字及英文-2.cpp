#include <iostream>

// Use the standard namespace to avoid writing "std::" before cin, cout, etc.
using namespace std;

int main() {
    // Declare an integer variable 'n' to store user input.
    int n;

    // Read a single integer from the user.
    cin >> n;

    // --- Logic without using an array ---
    // Use a series of if-else if statements to check the value of n one by one.

    if (n == 1) {
        cout << "one" << endl;
    }
    else if (n == 2) {
        cout << "two" << endl;
    }
    else if (n == 3) {
        cout << "three" << endl;
    }
    else if (n == 4) {
        cout << "four" << endl;
    }
    else if (n == 5) {
        cout << "five" << endl;
    }
    else if (n == 6) {
        cout << "six" << endl;
    }
    else if (n == 7) {
        cout << "seven" << endl;
    }
    else if (n == 8) {
        cout << "eight" << endl;
    }
    else if (n == 9) {
        cout << "nine" << endl;
    }
    else {
        // If n is not any of the numbers from 1 to 9,
        // it must be greater than 9 according to the problem description.
        cout << "Greater than 9" << endl;
    }

    // Indicate that the program finished successfully.
    return 0;
}