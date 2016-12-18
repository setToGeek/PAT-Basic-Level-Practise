#include <iostream>
using namespace std;

int main(){
        int T, X = 1;
        cin >> T;
        while(T--){
                // A B范围是[-2^31, 2^31] 正常int 4字节表示范围是[-2^31, 2^31 - 1] 所以必须要longlong 也可以用大整数处理方法做
                long long A, B, C;
                cin >> A >> B >> C;
                if(A + B > C)
                        cout << "Case #" << X++ <<": true" << endl;
                else
                        cout << "Case #" << X++ <<": false" << endl;
        }
        return 0;
}
