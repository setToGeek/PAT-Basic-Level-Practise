// 给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
//
// 例如，我们从6767开始，将得到
//
// 7766 - 6677 = 1089
// 9810 - 0189 = 9621
// 9621 - 1269 = 8352
// 8532 - 2358 = 6174
// 7641 - 1467 = 6174
// ... ...
//
// 现给定任意4位正整数，请编写程序演示到达黑洞的过程。
//
// 输入格式：
//
// 输入给出一个(0, 10000)区间内的正整数N。
//
// 输出格式：
//
// 如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    char integar[4], rintegar[4];
    cin >> integar;
    while(integar != "0000" && integar != "6174"){
        int tag = 0;
        sort(integar, integar + 4);
        for(int i = 0; i < 4; i++){
            rintegar[i] = integar[3 - i];
        }
        // cout << rintegar << " - " << integar << " = ";
        for(int i = 3; i > -1; i--){
            if(rintegar[i] + tag < integar[i]){
                integar[i] = tag + rintegar[i] + 10 - integar[i];
                tag = -1;
            } else
                integar[i] = rintegar[i] + tag - integar[i];
        }
        cout << integar << endl;
    }
    return 0;
}
