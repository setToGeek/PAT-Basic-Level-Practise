// C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：
//
// 0. 冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
// 1. 排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
// 2. 其他人将得到巧克力。
//
// 给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。
//
// 输入格式：
//
// 输入第一行给出一个正整数N（<=10000），是参赛者人数。随后N行给出最终排名，每行按排名顺序给出一位参赛者的ID（4位数字组成）。接下来给出一个正整数K以及K个需要查询的ID。
//
// 输出格式：
//
// 对每个要查询的ID，在一行中输出“ID: 奖品”，其中奖品或者是“Mystery Award”（神秘大奖）、或者是“Minion”（小黄人）、或者是“Chocolate”（巧克力）。如果所查ID根本不在排名里，打印“Are you kidding?”（耍我呢？）。如果该ID已经查过了（即奖品已经领过了），打印“ID: Checked”（不能多吃多占）。

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {
    int id[10000] = {0};
    int visited[10000] = {0};
    int ifPrime[10001];
    for (int i = 2; i < 10001; i++) {
        if(i == 2){
            ifPrime[i] = 1;
            continue;
        }
        int j = 2;
        for(; j < sqrt(i); j++){
            if(ifPrime[j] == 1 && i % j == 0){
                ifPrime[i] = 0;
                break;
            }
        }
        if(j > sqrt(i))
            ifPrime[i] = 1;
    }
    int n, rank = 1;
    cin >>n;
    while(n--){
        int tmp;
        cin >> tmp;
        id[tmp] = rank;
        rank++;
    }
    cin >> n;
    while(n--){
        int inquiry;
        cin >> inquiry;
        if(id[inquiry] == 0){
            cout << setw(4) << setfill('0') << inquiry << ": Are you kidding?";
        } else if(visited[inquiry] == 1){
            cout << setw(4) << setfill('0') << inquiry << ": Checked";
        } else if (id[inquiry] == 1) {
            cout << setw(4) << setfill('0') << inquiry << ": Mystery Award";
        } else if (ifPrime[id[inquiry]]) {
            cout << setw(4) << setfill('0') << inquiry << ": Minion";
        } else {
            cout << setw(4) << setfill('0') << inquiry << ": Chocolate";
        }
        visited[inquiry] = 1;
        cout << endl;
    }
    return 0;
}
