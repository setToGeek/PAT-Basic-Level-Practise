// 读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
//
// 输入格式：每个测试输入包含1个测试用例，格式为
//
//   第1行：正整数n
//   第2行：第1个学生的姓名 学号 成绩
//   第3行：第2个学生的姓名 学号 成绩
//   ... ... ...
//   第n+1行：第n个学生的姓名 学号 成绩
// 其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
// 输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

#include <iostream>
#include <cstring>
using namespace std;

struct STUDENT{
        char Name[11];
        char Id[11];
        int Score;
        STUDENT operator=(STUDENT &Stu){
                strcpy(Name, Stu.Name);
                strcpy(Id, Stu.Id);
                Score = Stu.Score;
                return *this;
        }
};

int main(){
        int N;
        STUDENT MaxStu, MinStu, Tmp;
        MaxStu.Score =  0;
        MinStu.Score = 101;
        cin >> N;
        for(int i = 0; i < N; i++){
                cin >> Tmp.Name;
                cin >> Tmp.Id;
                cin >> Tmp.Score;
                if(Tmp.Score > MaxStu.Score){
                        MaxStu = Tmp;
                }
                if(Tmp.Score < MinStu.Score){
                        MinStu = Tmp;
                }
        }
        cout << MaxStu.Name << " " << MaxStu.Id << endl;
        cout << MinStu.Name << " " << MinStu.Id;
        return 0;
}
