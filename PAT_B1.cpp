#include <iostream>
using namespace std;
#define MAX_NUM 1000
int main(){
        int N, Step = 0;
        cin >> N;
        while(N  != 1){
                if(N % 2 == 0)
                        N /= 2;
                else
                        N = (3 * N + 1) / 2;
                Step++;
        }
        cout << Step;
        return 0;
}
