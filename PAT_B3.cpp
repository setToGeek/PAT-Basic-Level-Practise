// “答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
//
// 得到“答案正确”的条件是：
//
// 1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
// 2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
// 3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
//
// 现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
//
// 输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
// 输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
        int T, Len, Tag, Test[3];
        string Str;
        cin >> T;
        while(T--){
                cin >> Str;
                Tag = 0;
                for(int i = 0; i < 3; i++){
                        Test[i] = 0;
                }
                Len = Str.size();
                int Ptr, PPos, TPos;
                Ptr = PPos = TPos = 0;
                for(; Ptr < Len; Ptr++){
                        if(Str[Ptr] == 'P'){
                                Test[0]++;
                                PPos = Ptr;
                                continue;
                        }
                        if(Str[Ptr] == 'A'){
                                Test[1]++;
                                continue;
                        }
                        if(Str[Ptr] == 'T'){
                                Test[2]++;
                                TPos = Ptr;
                                continue;
                        }
                                break;
                }
                if(Ptr == Len && Test[0] == 1 && Test[2] == 1 && Test[1] >= 1){
                        int Mid = TPos - PPos - 1;
                        int Left = PPos;
                        int Right = Len - 1 - TPos;
                        if(Mid == 1 && Left == Right)   Tag = 1;
                        if(Mid >=2 && Right == Mid * Left) Tag = 1;
                }
                if(Tag)
                        cout << "YES" << endl;
                else
                        cout << "NO" <<endl;
        }
        return 0;
}
