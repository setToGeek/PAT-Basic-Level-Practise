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
