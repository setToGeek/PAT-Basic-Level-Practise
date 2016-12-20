// 一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。
//
// 现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。
//
// 输入格式：
//
// 输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。
//
// 输出格式：
//
// 在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。

#include <iostream>
using namespace std;

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int GCDevisor(int &M, int &N){
    int Max = max(M, N);
    int Min = min(M, N);
    int r = Max % Min;
    while(r){
        Max = Min;
        Min = r;
        r = Max % Min;
    }
    return Min;
}
int main(){
    int Numerator1, Numerator2, Denominator1, Denominator2, K;
    int Tag = 0;
    cin >> Numerator1;
    cin.get();
    cin >> Denominator1;
    cin >> Numerator2;
    cin.get();
    cin >> Denominator2;
    cin >> K;
    if(Numerator1 * Denominator2 > Numerator2 * Denominator1){
      int tmp = Numerator1;
      Numerator1 = Numerator2;
      Numerator2 = tmp;
      tmp = Denominator1;
      Denominator1 = Denominator2;
      Denominator2 = tmp;
    }
    int j = Numerator2 / Denominator2 + 1;
    for(int i = 1; i < j * K; i++){
        if(GCDevisor(i, K) == 1 && i * Denominator1 > K * Numerator1 && i * Denominator2 < K * Numerator2){
            if(Tag)
                cout << " ";
            cout << i << "/" << K;
            Tag = 1;
        }
    }
    return 0;
}
