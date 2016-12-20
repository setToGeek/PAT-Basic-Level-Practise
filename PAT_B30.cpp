// 给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。
//
// 现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。
//
// 输入格式：
//
// 输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。第二行给出N个正整数，每个数不超过109。
//
// 输出格式：
//
// 在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

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
