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
