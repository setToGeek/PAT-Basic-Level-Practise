// 大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
//
// 输入格式：
//
// 输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
//
// 输出格式：
//
// 在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define min(a, b) (a > b ? b : a)
typedef char CODE[60];
enum DAY {MON, TUE, WED, THU, FRI, SAT, SUN};

void SwitchToDay(char ch, DAY &day){
        day = (DAY)(ch - 65);
}
int main(){
        DAY Day;
        int Len, Ptr = 0, Hour, Minute;
        CODE Sentence[4];
        for(int i = 0; i < 4; i++){
                cin >> Sentence[i];
        }
        Len = min(strlen(Sentence[0]), strlen(Sentence[1]));
        while(Ptr != Len){
                char Ch;
                if(Sentence[0][Ptr] == Sentence[1][Ptr]){
                        Ch = Sentence[0][Ptr];
                        cout << Ch << endl;
                        SwitchToDay(Ch, Day);
                        Ptr++;
                        break;
                }
                Ptr++;
        }
        while(Ptr != Len){
                char Ch;
                if(Sentence[0][Ptr] == Sentence[1][Ptr]){
                        Ch = Sentence[0][Ptr];
                        cout << Ch << endl;
                        if(Ch >= 'A')
                                Hour = Ch - 55;
                        else
                                Hour = Ch - 48;
                        break;
                }
                Ptr++;
        }
        Ptr = 0;
        Len = min(strlen(Sentence[2]), strlen(Sentence[3]));
        while(Ptr != Len){
                if(Sentence[2][Ptr] == Sentence[3][Ptr]){
                        Minute = Ptr;
                        break;
                }
                Ptr++;
        }
        cout << Day << " " << Hour << ":" << setfill('0') << setw(2) << Minute;
        return 0;
}
