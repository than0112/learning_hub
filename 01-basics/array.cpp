/*An array is a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.

For arrays of a known size,  in this case, use the following declaration:

int arr[10]; //Declares an array named arr of size 10, i.e, you can 
store 10 integers.
Note Unlike C, C++ allows dynamic allocation of arrays at runtime without special calls like malloc(). If , int arr[n] will create an array with space for  integers.

Accessing elements of an array:

Indexing in arrays starts from 0.So the first element is stored at 
arr[0],the second element at arr[1] and so on through arr[9].
You will be given an array of  integers and you have to print the integers in the reverse order.
*/
//這題主要做的是陣列反轉

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    // Get array size from user
    int n;
    cin >> n;

    // Create vector to store numbers
    vector<int> numbers(n); 

    // Read numbers from user input
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Reverse the vector
    reverse(numbers.begin(), numbers.end());

    // Print reversed numbers with spaces between them
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}