#include <cstdio> // 引入 C 標準輸入輸出函式庫，其中包含了 scanf 和 printf

int main() {
    // 1. 宣告對應的變數來儲存輸入值
    int my_int;
    long long my_long; // 使用 long long 來確保能儲存64位元的整數
    char my_char;
    float my_float;
    double my_double;

    // 2. 使用 scanf 搭配對應的格式指定符，一次讀取所有輸入值
    // 注意 long long 對應的是 %lld
    scanf("%d %lld %c %f %lf", &my_int, &my_long, &my_char, &my_float, &my_double);

    // 3. 使用 printf 搭配指定的格式，將每個變數分別印在獨立的一行
    printf("%d\n", my_int);
    printf("%lld\n", my_long);
    printf("%c\n", my_char);
    
    // 對於 float，使用 %.3f 來格式化到小數點後三位
    printf("%.3f\n", my_float);
    
    // 對於 double，使用 %.9lf 來格式化到小數點後九位
    printf("%.9lf\n", my_double);

    return 0;
}
//程式碼解說
//#include <cstdio>: 引入 C 語言的標準輸入輸出標頭檔。雖然這是 C++ 程式，但 scanf 和 printf 是繼承自 C 語言的函式，所以需要引入這個檔案。

//long long my_long;: 題目要求 long 是 64 位元整數。在不同的系統上，long 的大小可能不同（有時是 32 位元）。為了確保能穩定地處理像 12345678912345 這樣大的數字，使用 long long 是最保險、最標準的做法。

//scanf(...): 我們將所有格式指定符放在一個字串中，並用空格隔開，scanf 會自動根據空格或換行來切分輸入的資料，並依次存入後面用 & (取址運算子) 指定的變數記憶體位置中。

//%lld: 這是 long long 型態對應的格式指定符。

//printf("%.3f\n", ...):

//%f 是用來印出 float。

//在 % 和 f 之間加上 .3 代表「固定顯示到小數點後三位」。如果原本的小數位數不夠，會自動補 0。

//printf("%.9lf\n", ...):

//%lf 是用來印出 double。

//同樣地，.9 代表固定顯示到小數點後九位