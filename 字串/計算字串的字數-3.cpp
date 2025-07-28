#include <iostream>
#include <string>
#include <sstream>     // 為了使用 stringstream
#include <iterator>    // 為了使用 istream_iterator
#include <algorithm>   // 為了使用 distance (在某些編譯器中需要)

using namespace std;

int main() {
    string text = "  Hello   world, this is C++!  ";

    // 1. 建立 stringstream
    istringstream iss(text);

    // 2. 使用 distance 和 istream_iterator 一行搞定計數
    int word_count = distance(istream_iterator<string>(iss), 
     istream_iterator<string>());
/*請計算一下，從 iss 這個文字串流的『開頭』開始，一個一個地讀取字串，直到『串流結束』為止，總共可以讀出多少個字串？」

執行流程：

distance 函式拿到了「起始書籤」和「結尾書籤」。

它在內部不斷地移動「起始書籤」（這會觸發從 iss 中讀取下一個字），並在一個計數器上加一。

這個過程一直持續，直到「起始書籤」讀完了所有字，其自身狀態變成了「結尾書籤」的狀態。

此時，distance 函式停止，並回傳計數器的最終值。*/

    cout << "原始字串是: \"" << text << "\"" << endl;
    cout << "總字數為: " << word_count << endl;

    return 0;
}