#include <iostream>
using namespace std;

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int GCDevisor(int &M, int &N){
    int Max = max(M, N);
    int Min = min(M, N);
    int r = Max % Min;
    while(r){
        Max = Min;
        Min = r;
        r = Max % Min;
    }
    return Min;
}
int main(){
    int Numerator1, Numerator2, Denominator1, Denominator2, K;
    int Tag = 0;
    cin >> Numerator1;
    cin.get();
    cin >> Denominator1;
    cin >> Numerator2;
    cin.get();
    cin >> Denominator2;
    cin >> K;
    if(Numerator1 * Denominator2 > Numerator2 * Denominator1){
      int tmp = Numerator1;
      Numerator1 = Numerator2;
      Numerator2 = tmp;
      tmp = Denominator1;
      Denominator1 = Denominator2;
      Denominator2 = tmp;
    }
    int j = Numerator2 / Denominator2 + 1;
    for(int i = 1; i < j * K; i++){
        if(GCDevisor(i, K) == 1 && i * Denominator1 > K * Numerator1 && i * Denominator2 < K * Numerator2){
            if(Tag)
                cout << " ";
            cout << i << "/" << K;
            Tag = 1;
        }
    }
    return 0;
}
