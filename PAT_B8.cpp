// 一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
//
// 输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。

#include <iostream>
using namespace std;

#define MAXSIZE 100

void Reverse(int Num[], int Left, int Right){
        for(int i = Left; i <= (Left + Right) / 2; i++){
                int Tmp = Num[i];
                Num[i] = Num[Left + Right - i];
                Num[Left + Right - i] = Tmp;
        }
}

int main(){
        int A[MAXSIZE];
        int N, M, Tag = 0;
        cin >> N >> M;
        for(int i = 0; i < N; i++){
                cin >> A[i];
        }
        //注意循环右移　Ｍ可能大于等于Ｎ　不处理的话部分测试点可能不通过
        if(M > N - 1)
                M %= N;
        if(M > 0){
                Reverse(A, 0, N - 1);
                Reverse(A, 0, M - 1);
                Reverse(A, M, N - 1);
        }
        for(int i = 0; i < N; i++){
                if(Tag)
                        cout << " ";
                cout << A[i];
                Tag = 1;
        }
        return 0;
}
