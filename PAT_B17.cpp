// 本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
//
// 输入格式：
//
// 输入在1行中依次给出A和B，中间以1空格分隔。
//
// 输出格式：
//
// 在1行中依次输出Q和R，中间以1空格分隔。

#include <iostream>
#include <cstring>
using namespace std;

int main(){
        int B, Result[1001], Tag = 0, DigitNums = 0;
        char A[1001];
        cin >> A >> B;
        for(int  i = 0; i < strlen(A); ++i){
                int Tmp = Tag * 10 + (A[i] - 48);
                Tag = Tmp % B;
                Result[i] = Tmp / B;
                DigitNums++;
        }
        if(DigitNums == 1 && Result[0] == 0)
                cout << 0;
        int Ptr = 0;
        while(Result[Ptr] == 0){
                Ptr++;
        }
        for(; Ptr < DigitNums; ++Ptr){
                cout << Result[Ptr];
        }
        cout << " " << Tag;
        return 0;
}
