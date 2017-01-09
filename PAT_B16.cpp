// 正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
//
// 现给定A、DA、B、DB，请编写程序计算PA + PB。
//
// 输入格式：
//
// 输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
//
// 输出格式：
//
// 在一行中输出PA + PB的值。

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000
#define max(a, b) ((a > b) ? a : b)

int main(){
        char A[MAX], B[MAX];
        int Sum[MAX];
        int DA, DB, TA = 0, TB = 0, Tag = 0;//TA TB分别表示A B中出现DA DB的次数
        cin >> A >> DA;
        cin >> B >> DB;
        for(int i = 0; i < MAX; i++){
                Sum[i] = 0;
        }
        for(int i = 0; i < strlen(A); i++){
                int Tmp = A[i] - 48;
                if(Tmp == DA)   {
                        Sum[TA] += DA;
                        TA++;
                }
        }
        for(int i = 0; i < strlen(B); i++){
                int Tmp = B[i] - 48;
                if(Tmp == DB)   TB++;
        }
        int P = max(TA, TB);
        for(int i = 0; i < P; i++){
                int Tmp;
                if(i < TB){
                        Tmp = Sum[i] + DB + Tag;
                }
                else
                        Tmp = Sum[i] + Tag;
                if(Tmp / 10 == 1){
                        Tag = 1;
                }
                else
                        Tag = 0;
                Sum[i] = Tmp % 10;
        }
        if(Tag == 1)
                Sum[P] = 1;
        int Flag = 1;
        for(int i = P + Tag - 1; i > 0; i--){
                if(Flag && Sum[i] == 0)
                        continue;
                cout << Sum[i];
                Flag = 0;
        }
        cout << Sum[0];
        return 0;
}
