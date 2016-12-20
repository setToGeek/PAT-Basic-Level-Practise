// 给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
//
// A1 = 能被5整除的数字中所有偶数的和；
// A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
// A3 = 被5除后余2的数字的个数；
// A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
// A5 = 被5除后余4的数字中最大数字。
// 输入格式：
//
// 每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
//
// 输出格式：
//
// 对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
//
// 若其中某一类数字不存在，则在相应位置输出“N”。

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
        int T, A[5], Tag[5], Flag = 0;
        int Coef = -1;
        for(int i = 0; i < 5; i++){
                A[i] = 0;
                Tag[i] = 0;
        }
        cin >> T;
        while(T--){
                int Input, Mod;
                cin >> Input;
                Mod = Input % 5;
                switch(Mod){
                        case 0:{
                                if(Input % 2 == 0){
                                        A[0] += Input;
                                        Tag[0] = 1;
                                }
                                break;
                        }
                        case 1:{
                                Tag[1] = 1;
                                Coef *= -1;
                                A[1] += Input * Coef;
                                break;
                        }
                        case 2:{
                                A[2]++;
                                Tag[2] = 1;
                                break;
                        }
                        case 3:{
                                A[3] += Input;
                                Tag[3]++;
                                break;
                        }
                        case 4:{
                                if(Input > A[4])
                                        A[4] = Input;
                                Tag[4] = 1;
                                break;
                        }
                }
        }
        float Modify = (float)A[3] / Tag[3];
        for(int i = 0; i < 5; i++){
                if(Flag)        cout << " ";
                if(!Tag[i]){
                        cout << 'N';
                        Flag = 1;
                        continue;
                }
                if(i == 3){
                        cout << setiosflags(ios::fixed) << setprecision(1) << Modify;
                }
                else
                        cout << A[i];
                Flag = 1;
        }
        return 0;
}
