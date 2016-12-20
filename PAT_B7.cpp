// 让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
//
// 现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。
//
// 输入格式：每个测试输入包含1个测试用例，给出正整数N。
//
// 输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

#include <iostream>
#include <cmath>
using namespace std;

#define MAXSIZE 100000

int main(){
        int Nums = 0;
        int K;
        cin >> K;
        int IsPrime[MAXSIZE];
        IsPrime[2] = 1;
        for(int i = 3; i < MAXSIZE; i++){
                int j = 2;
                for(; j < sqrt(i); j++){
                        if(IsPrime[j] == 1 && i % j == 0){
                                IsPrime[i] = 0;
                                break;
                        }
                }
                if(j > sqrt(i))
                        IsPrime[i] = 1;
        }
        for(int i = 2; i < K - 1; i++){
                if(IsPrime[i] && IsPrime[i+2])
                        Nums++;
        }
        cout << Nums;
        return 0;
}
