#include <iostream>
using namespace std;

#define MAXSIZE 100

void Reverse(int Num[], int Left, int Right){
        for(int i = Left; i <= (Left + Right) / 2; i++){
                int Tmp = Num[i];
                Num[i] = Num[Left + Right - i];
                Num[Left + Right - i] = Tmp;
        }
}

int main(){
        int A[MAXSIZE];
        int N, M, Tag = 0;
        cin >> N >> M;
        for(int i = 0; i < N; i++){
                cin >> A[i];
        }
        //注意循环右移　Ｍ可能大于等于Ｎ　不处理的话部分测试点可能不通过
        if(M > N - 1)
                M %= N;
        if(M > 0){
                Reverse(A, 0, N - 1);
                Reverse(A, 0, M - 1);
                Reverse(A, M, N - 1);
        }
        for(int i = 0; i < N; i++){
                if(Tag)
                        cout << " ";
                cout << A[i];
                Tag = 1;
        }
        return 0;
}
