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
