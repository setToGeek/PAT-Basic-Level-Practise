#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 100001

int main(){
        int Array[MAXSIZE];
        int N;
        cin >> N;
        for(int i = 1; i <= N; i++){
                cin >> Array[i];
        }
        sort(Array+1, Array + N + 1);
        if(Array[1] == Array[N] && (Array[1] == 1 || Array[1] == 0)){
                cout << 0;
                return 0;
        }
        int Left = 1, Right = N, Mid;
        while(Left != Right){
                Mid = (Left + Right) / 2;
                if(Array[Mid] <= N - Mid + 1){
                        Left = Mid + 1;
                }
                if(Array[Mid] > N - Mid + 1){
                        Right = Mid;
                }
        }
        cout << N - Left + 1;
        return 0;
}
