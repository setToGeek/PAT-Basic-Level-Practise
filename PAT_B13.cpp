// 令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。
//
// 输入格式：
//
// 输入在一行中给出M和N，其间以空格分隔。
//
// 输出格式：
//
// 输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 104730

int main(){
        int N, M;
        cin >> M >> N;
        int IsPrime[MAX];
        int Pc = 1, Ptr = 2, Tag = 0, T = 0;
        while(Pc <= N){
                while(1){
                        int  j = 2;
                        for(; j < sqrt(Ptr); j++){
                                if(IsPrime[j] == 1 && Ptr % j == 0){
                                        IsPrime[Ptr++] = 0;
                                        break;
                                }
                        }
                        if(j > sqrt(Ptr)){
                                IsPrime[Ptr] = 1;
                                if(Pc >= M){
                                        T++;
                                        if(Tag)
                                                cout << " ";
                                        cout << Ptr;
                                        Tag = 1;
                                        if(T % 10 == 0){
                                                cout << endl;
                                                Tag = 0;
                                        }
                                }
                                // cout << Pc << ' ' << Ptr << ' ';可以看到第Pc个素数是多少
                                Pc++;
                                Ptr++;
                                break;
                        }
                        if(j == sqrt(Ptr)){
                                Ptr++;
                        }
                }
        }
        return 0;
}
