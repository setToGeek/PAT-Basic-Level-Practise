#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAXSIZE 100000
int main(){
        int T, Max, MaxSum = 0;
        int Score[MAXSIZE];
        for(int i = 0; i < MAXSIZE; i++){
                Score[i] = 0;
        }
        cin >> T;
        while(T--){
                int N, Point;
                cin >> N >> Point;
                Score[N - 1] += Point;
                if(Score[N - 1] > MaxSum){
                        Max = N;
                        MaxSum = Score[N - 1];
                }
        }
        cout << Max << " " << MaxSum;
        return 0;
}
