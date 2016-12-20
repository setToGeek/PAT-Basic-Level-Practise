// 给定区间[-231, 231]内的3个整数A、B和C，请判断A+B是否大于C。
//
// 输入格式：
// 
// 输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。
//
// 输出格式：
//
// 对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。

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
