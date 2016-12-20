// 输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。
//
// 输入格式：
//
// 输入在一行中依次给出3个整数A、B和D。
//
// 输出格式：
// 
// 输出A+B的D进制数。

#include <iostream>
using namespace std;

int main(){
        int A, B, D, Ptr = 0;
        int Result[32];
        cin >> A >> B;
        A += B;
        cin >> D;
        while(A / D){
                Result[Ptr] = A % D;
                ++Ptr;
                A /= D;
        }
        if(A != 0){
                Result[Ptr] = A;
                ++Ptr;
        }
        if(Ptr == 0)
        cout << 0;
        for(int i = Ptr - 1; i >= 0; --i){
                cout << Result[i];
        }
        return 0;
}
