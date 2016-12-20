// 读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
//
// 输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。
//
// 输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

#include <iostream>
using namespace std;
#define MAXSIZE 100

void TurnIntoPinyin(int n){
        switch(n){
                case 1: cout << "yi";   break;
                case 2: cout << "er";   break;
                case 3: cout << "san";  break;
                case 4: cout << "si";   break;
                case 5: cout << "wu";   break;
                case 6: cout << "liu";  break;
                case 7: cout << "qi";   break;
                case 8: cout << "ba";   break;
                case 9: cout << "jiu";  break;
                case 0: cout << "ling"; break;
        }
}
int main(){
        char cBigN[MAXSIZE];
        int BigN[3], Sum = 0;
        cin >> cBigN;
        int Ptr = 0;
        while(cBigN[Ptr] != '\0'){
                Sum += cBigN[Ptr] - 48;
                Ptr++;
        }
        if(Ptr > 100){
                cerr << "输入整数过大";
                return -1;
        }
        Ptr = 0;
        while(Sum != 0){
                BigN[Ptr] = Sum % 10;
                Sum /= 10;
                Ptr++;
        }
        TurnIntoPinyin(BigN[Ptr - 1]);
        for(int i = Ptr - 2; i >= 0; i--){
                cout << " ";
                TurnIntoPinyin(BigN[i]);
        }
        return 0;
}
