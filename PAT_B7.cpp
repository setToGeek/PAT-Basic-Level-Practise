#include <iostream>
#include <cmath>
using namespace std;

#define MAXSIZE 100000

int main(){
        int Nums = 0;
        int K;
        cin >> K;
        int IsPrime[MAXSIZE];
        IsPrime[2] = 1;
        for(int i = 3; i < MAXSIZE; i++){
                int j = 2;
                for(; j < sqrt(i); j++){
                        if(IsPrime[j] == 1 && i % j == 0){
                                IsPrime[i] = 0;
                                break;
                        }
                }
                if(j > sqrt(i))
                        IsPrime[i] = 1;
        }
        for(int i = 2; i < K - 1; i++){
                if(IsPrime[i] && IsPrime[i+2])
                        Nums++;
        }
        cout << Nums;
        return 0;
}
