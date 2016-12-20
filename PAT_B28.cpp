// 某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
//
// 这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。
//
// 输入格式：
//
// 输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
//
// 输出格式：
//
// 在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxDate = 20140906;
const int minDate = 18140906;

int main(){
    int n, max = 20140906, min = 18140906, validNums = 0;
    char *oldest = NULL, *youngest = NULL;
    cin >> n;
    while(n--){
        int ptr = 0;
        char *name = new char[6];
        char ch, birthday[9];
        cin >> name;
        while((ch = cin.get()) != '\n'){
            if(ch >= '0' && ch <= '9')
                birthday[ptr++] = ch;
        }
        birthday[ptr] = '\n';
        int date = atoi(birthday);
        if(date >= minDate && date <= maxDate){
            validNums++;
            if(date < max){
                char *tmp = new char[6];
                delete []oldest;
                strcpy(tmp, name);
                max = date;
                oldest = tmp;
            }
            if(date > min){
                char *tmp = new char[6];
                delete []youngest;
                strcpy(tmp, name);
                min = date;
                youngest = tmp;
            }
            cout << validNums << " ";
        }
        delete []name;
        cout << oldest << " " << youngest << " ";
    }
    cout << validNums << " " << oldest << " " << youngest;
    delete oldest;
    delete youngest;
    return 0;
}
