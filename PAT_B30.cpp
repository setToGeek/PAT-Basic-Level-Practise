#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 100010

int MaxN(int A[], int Len, double P){
        int Max = 1;
        for(int i = 0; i + Max < Len; i++){
                int j = i + Max;
                for(; j < Len; j++){
                        if(A[j] > A[i] * P)     break;
                        Max++;
                }
        }
        return Max;
}

int main(){
        int Array[MAXSIZE];
        int N;
        double P;//如果写成int，有一个测试点会答案错误，可能原因是
        // 12行 A[i] * P 当两个数太大时，结果强制转换成int会溢出，头被截，那么得到的结果
        // 可能会比A[j]大，结果会出错
        cin >> N >> P;
        for(int i = 0; i < N; i++){
                cin >> Array[i];
                // Array[i] = 1000000000;
        }
        sort(Array, Array + N);
        int Max = MaxN(Array, N, P);
        cout << Max;
        return 0;
}
