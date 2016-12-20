// 本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。
//
// 输入格式：
//
// 输入在第1行给出不超过105的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。
//
// 输出格式：
//
// 在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

#include <iostream>
using namespace std;

#define MAXSIZE 101

int main(){
        int NumOfPeople[MAXSIZE];
        int N, K, Tag = 0;
        for(int i = 0; i < MAXSIZE; i++){
                NumOfPeople[i] = 0;
        }
        cin >> N;
        for(int i  = 0; i < N; i++){
                int Tmp;
                cin >> Tmp;
                NumOfPeople[Tmp]++;
        }
        cin >> K;
        while(K--){
                int Tmp;
                cin >> Tmp;
                if(Tag)
                cout << " ";
                cout << NumOfPeople[Tmp];
                Tag = 1;
        }
        return 0;
}
