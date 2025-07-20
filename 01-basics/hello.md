
In this cpp ，I will explain some simple concepts of C++.

1:C++ Variables
變數式儲存資料類型的容器

int - stores integers (whole numbers), without decimals, such as 123 or -123
double - stores floating point numbers, with decimals, such as 19.99 or -19.99
char - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
string - stores text, such as "Hello World". String values are surrounded by double quotes
bool - stores values with two states: true or false

Where type is one of C++ types (such as int), and variableName is the name of the variable (such as x or myName). The equal sign is used to assign values to the variable.
使用變數時需要指定類型

如果希望你的變數的值不希望改變，可以使用const ，宣告這個值維持不變
example 1:
const int myNum = 15;  // myNum will always be 15
myNum = 10;  // error: assignment of read-only variable 'myNum'

*/
//Both \n and endl are used to break lines. However, \n is most used.

//Examples of other valid escape sequences are:
// \t	Creates a horizontal tab
// \r	Carriage return
// \b	Backspace
// \\	Inserts a backslash character (\)	
// \"	Inserts a double quote character


//real life example
/*
// Create integer variables
int length = 4;
int width = 6;

// Calculate the area of a rectangle
int area = length * width;

// Print the variables
cout << "Length is: " << length << "\n";
cout << "Width is: " << width << "\n";
cout << "Area of the rectangle is: " << area << "\n";
*/

//Basic Data Types
/*The data type specifies the size and type of information the variable will store:

Data Type	Size	Description
boolean	1 byte	Stores true or false values
char	1 byte	Stores a single character/letter/number, or ASCII values
int	2 or 4 bytes	Stores whole numbers, without decimals
float	4 bytes	Stores fractional numbers, containing one or more decimals. Sufficient for storing 6-7 decimal digits
double	8 bytes	Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits
float vs. double

The precision of a floating point value indicates how many digits the value can have after the decimal point.
 The precision of float is only six or seven decimal digits, 
while double variables have a precision of about 15 digits. 
Therefore it is safer to use double for most calculations

The char data type is used to store a single character. 
The character must be surrounded by single quotes, like 'A' or 'c':

String Types
The string type is used to store a sequence of characters (text).
 This is not a built-in type, but it behaves like one in its most basic usage.
  String values must be surrounded by double quotes:
 
example 1;
  string greeting = "Hello";
cout << greeting;
*/

/*auto的用法
The auto keyword automatically detects the type of a variable based on the value you assign to it.

It helps you write cleaner code and avoid repeating types, especially for long or complex types.

For example: Instead of writing int x = 5;, you can write:

Example
auto x = 5; // x is automatically treated as int

Example with Different Types
Here's an example showing how auto can be used to create variables of different types, based on the values you assign:

Example
// Creating auto variables
auto myNum = 5; // int
auto myFloatNum = 5.99; // float
auto myDoubleNum = 9.98; // double
auto myLetter = 'D'; // char
auto myBoolean = true; // bool
auto myString = string("Hello"); // std::string


Important Notes
auto only works when you assign a value at the same time (You can't declare auto x; without assigning a value)
Once the type is chosen, it stays the same. See example below:
auto x = 5; // x is now an int
x = 10;     // OK - still an int
x = 9.99;   // Error - can't assign a double to an int

Assignment Operators
Assignment operators are used to assign values to variables.

In the example below, we use the assignment operator (=) to assign the value 10 to a variable called x:

Example
int x = 10;
The addition assignment operator (+=) adds a value to a variable:

Example
int x = 10;
x += 5;

Operator	Example	Same As	Try it
=	x = 5	x = 5	
+=	x += 3	x = x + 3	
-=	x -= 3	x = x - 3	
*=	x *= 3	x = x * 3	
/=	x /= 3	x = x / 3	
%=	x %= 3	x = x % 3	
&=	x &= 3	x = x & 3	
|=	x |= 3	x = x | 3	
^=	x ^= 3	x = x ^ 3	
>>=	x >>= 3	x = x >> 3	
<<=	x <<= 3	x = x << 3
Logical Operators
As with comparison operators, you can also test for true (1) or false (0) values with logical operators.

Logical operators are used to determine the logic between variables or values:

Operator	Name	Description	Example	Try it
&& 	Logical and	Returns true if both statements are true	x < 5 &&  x < 10	
|| 	Logical or	Returns true if one of the statements is true	x < 5 || x < 4	
!	Logical not	Reverse the result, returns false if the result is true	!(x < 5 && x < 10)


C++ 字串
字串用於儲存文本/字符。
例如，"Hello World" 是一個字串。
字串變數包含一組被雙引號包圍的字符：
Example 1
string greeting = "Hello";

在使用字串的時候需要導入<string>標頭檔

例子:
// Include the string library
#include <string>

// Create a string variable
string greeting = "Hello";

字串串連
可以使用 + 運算符將字串相加以製作新字串，這稱為串連。

Example
string firstName = "Yao ";
string lastName = "you hong";
string fullName = firstName + " "lastName;
cout << fullName;

 firstName 之後加了一個空格，以在輸出中創建 John 和 Doe 之間的空間。然而，您也可以使用引號（" " 或 ' '）來添加空格:


append()
在C++中，字符串實際上是一個對象，包含可以對字符串執行某些操作的函數。例如，您還可以使用append()函數來串聯字符串：
例子
string firstName = "John ";
string lastName = "Doe";
string fullName = firstName.append(lastName);
cout << fullName;

字串跟數字不可以進行相加 

如果要取得一個字串的長度時我們可以使用length()函數
Example
string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
cout << "The length of the txt string is: " << txt.length();

取得字串裡面的值可以使用索引值來進行



Example
string myString = "Hello";
cout << myString[0];
結果會出現"H"
字串裡面的索引值式從0開始

如果要印出最後一個字母可以這樣子:
string myString = "Hello";
cout << myString[myString.length() - 1];
// Outputs o

Change String Characters
To change the value of a specific character in a string, refer to the index number, and use single quotes:

Example
string myString = "Hello";
myString[0] = 'J';
cout << myString;
// Outputs Jello instead of Hello

The at() function
The <string> library also has an at() function that can be used to access characters in a string:

Example
string myString = "Hello";
cout << myString; // Outputs Hello

cout << myString.at(0);  // First character
cout << myString.at(1);  // Second character
cout << myString.at(myString.length() - 1);  // Last character

myString.at(0) = 'J';
cout << myString;  // Outputs Jello


字串 特殊字元
跳脫字元	Result	Description
\'	'	Single quote
\"	"	Double quote
\\	\	Backslash
The sequence \"  inserts a double quote in a string:

string fullName;
cout << "Type your full name: ";
getline (cin, fullName);
cout << "Your name is: " << fullName;

// Type your full name: John Doe
// Your name is: John Doe
為什麼需要 getline？(cin 的問題)
如果你想讀取一個包含空格的句子或姓名，cin 就會出問題。
因為 cin 預設會使用空白字元（包括空格、Tab、換行符）作為分隔符。一旦遇到空格，它就停止讀取。

C風格字串C風格字串是使用char類型而不是string類型創建的。名稱來自C語言，與許多其他程式語言不同，它沒有字符串類型來輕鬆創建字符串變量。因此，您必須使用char類型並創建字符數組以在C中創建一個“字符串”。隨著C++作為C的擴展而開發，它繼續支持這種在C++中創建字符串的方式：

string greeting1 = "Hello";  // Regular String
char greeting2[] = "Hello";  // C-Style String (an array of characters)


C math函數

Max and min
The max(x,y) function can be used to find the highest value of x and y:
the min(x,y) function can be used to find the lowest value of x and y:
Example
cout << max(5, 10);
cout << min(5, 10);

C++ <cmath> Library


Example
// Include the cmath library
#include <cmath>

cout << sqrt(64);
cout << round(2.6);
cout << log(2);

C++ Booleans布林值
在編寫程式碼的時候使用布林值可以用來判斷事情的正反
例子
YES / NO
ON / OFF
TRUE / FALSE
布林值在c++程式裡面通常是true(1)和false(0)代表的


Example
bool isCodingFun = true;
bool isFishTasty = false;
cout << isCodingFun;  // Outputs 1 (true)
cout << isFishTasty;  // Outputs 0 (false)
布林值在生活中的例子在這裡我使用了檢定是否有達到選舉的最低年齡的例子
int myAge = 25;
int votingAge = 18;

if (myAge >= votingAge) {
  cout << "Old enough to vote!";
} else {
  cout << "Not old enough to vote.";
}

// Outputs: Old enough to vote!


簡短的 if...else（條件運算子）也有一種簡寫形式，稱為條件運算子，因為它由三個操作數組成。它可以用來用一行代替多行代碼，並且通常用來替換簡單的 if else 語句：
variable = (condition) ? expressionTrue : expressionFalse;


C++ Switch Statements
Use the switch statement to select one of many code blocks to be executed.

switch(expression) {
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block}

程式碼解說
The switch expression is evaluated once(裡面的描述址評估一次)
The value of the expression is compared with the values of each case
If there is a match, the associated block of code is executed
int day = 4;
switch (day) {
  case 1:
    cout << "Monday";
    break;
  case 2:
    cout << "Tuesday";
    break;
  case 3:
    cout << "Wednesday";
    break;
  case 4:
    cout << "Thursday";
    break;
  case 5:
    cout << "Friday";
    break;
  case 6:
    cout << "Saturday";
    break;
  case 7:
    cout << "Sunday";
    break;
}
// Outputs "Thursday" (day 4)

c++迴圈
迴圈可以減少在執行時所要花費的時間

while (condition) {
  // code block to be executed
}

例子
int countdown = 3;

while (countdown > 0) {
  cout << countdown << "\n";
  countdown--;
}

cout << "Happy New Year!!\n";

Do/While Loop
do/while 迴圈是 while 迴圈的一種變體。此迴圈將在檢查條件是否為真之前執行代碼區塊一次。然後，只要條件為真，它將重複該迴圈。

下面的範例使用 do/while 迴圈。雖然條件為錯的，迴圈也會至少執行一次(這是因為do-while迴圈的特性)，因為在測試條件之前，程式碼區塊已經被執行了。

int i = 0;
do {
  cout << i << "\n";
  i++;
}
while (i < 5);

條件從一開始就是假的
在上面的範例中，條件 i < 5 在一開始是真的，所以迴圈執行了多次。但如果條件一開始就是假的呢？在下面的範例中，變數 i 從 10 開始，因此條件 i < 5 立即就是假的——不過 do/while 迴圈仍然執行了一次：
int i = 10;
do {
  cout << "i is " << i << "\n";
  i++;
} while (i < 5);

實際例子 1
int dice = 1;

while (dice <= 6) {
  if (dice < 6) {
    cout << "No Yatzy\n";
  } else {
    cout << "Yatzy!\n";
  }
  dice = dice + 1;
}
實際例子 2
// A variable with some specific numbers
int numbers = 12345;

// A variable to store the reversed number
int revNumbers = 0;

// Reverse and reorder the numbers
while (numbers) {
  // Get the last number of 'numbers' and add it to 'revNumbers'
  revNumbers = revNumbers * 10 + numbers % 10;
  // Remove the last number of 'numbers'
  numbers /= 10;
}

cout << "Reversed numbers: " << revNumbers << "\n";