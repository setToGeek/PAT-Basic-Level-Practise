// 英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数”E，即满足有E天骑车超过E英里的最大整数E。据说爱丁顿自己的E等于87。
//
// 现给定某人N天的骑车距离，请你算出对应的爱丁顿数E（<=N）。
//
// 输入格式：
//
// 输入第一行给出一个正整数N（<=105），即连续骑车的天数；第二行给出N个非负整数，代表每天的骑车距离。
//
// 输出格式：
//
// 在一行中给出N天的爱丁顿数。

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
