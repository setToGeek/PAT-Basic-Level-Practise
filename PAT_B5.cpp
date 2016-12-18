#include <iostream>
using namespace std;

#define MAXSIZE 300

int main(){
  int IfCovered[MAXSIZE];
  int Key[MAXSIZE];
  for(int i = 0; i < MAXSIZE; i++){
    IfCovered[i] = 0;
    Key[i] = 0;
  }
  IfCovered[1] = 1;
  int K, N, Tag = 0;
  cin >> K;
  while(K--){
    cin >> N;
    int Tmp = N;
    while(N != 1){
      if(N <= 100){
        if(IfCovered[N]){
          if(N == Tmp)  break;
          if(Key[N] == 1){
            Key[N] = 0;
          }
          Key[Tmp] = 1;
          break;
        }
      IfCovered[N] = 1;
      }
      if(N % 2 == 0)
        N /= 2;
      else
        N = (3 * N + 1) / 2;
    }
    if(N == 1)
      Key[Tmp] = 1;
  }
  for(int i = 100; i > 0; i--){
    if(Key[i]){
      if(Tag){
        cout << " ";}
      cout << i;
      Tag = 1;
    }
  }
  return 0;
}
