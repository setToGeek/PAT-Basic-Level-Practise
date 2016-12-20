// 为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。
//
// 输入格式：
//
// 输入在第1行给出不超过105的正整数N，即参赛人数。随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。
//
// 输出格式：
//
// 在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAXSIZE 100000
int main(){
        int T, Max, MaxSum = 0;
        int Score[MAXSIZE];
        for(int i = 0; i < MAXSIZE; i++){
                Score[i] = 0;
        }
        cin >> T;
        while(T--){
                int N, Point;
                cin >> N >> Point;
                Score[N - 1] += Point;
                if(Score[N - 1] > MaxSum){
                        Max = N;
                        MaxSum = Score[N - 1];
                }
        }
        cout << Max << " " << MaxSum;
        return 0;
}
