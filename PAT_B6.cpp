// 让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。
//
// 输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。
//
// 输出格式：每个测试用例的输出占一行，用规定的格式输出n。

#include <iostream>
#include <cstring>
using namespace std;
int main(){
  char cNum[3];
  int Num[3];
  int Len;
  cin >> cNum;
  Len = strlen(cNum);
  for(int i = 0; i < Len; i++){
    Num[i] = cNum[i] - 48;
  }
  if(Len == 3){
    for(int i = 0; i < Num[Len - 3]; i++){
        cout << 'B';
    }
  }
  if(Len >= 2){
    for(int i = 0; i < Num[Len - 2]; i++){
        cout << 'S';
    }
  }
  for(int i = 1; i <= Num[Len - 1]; i++){
      cout << i;
  }
  return 0;
}
