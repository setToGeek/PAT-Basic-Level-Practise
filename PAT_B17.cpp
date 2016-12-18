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
