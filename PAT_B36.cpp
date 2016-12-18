#include <iostream>
using namespace std;

void Output(char Ch, int n){
        for(int i = 0; i < n; i++){
                cout << Ch;
        }
}

int main(){
        int n;
        char Ch;
        cin >> n >> Ch;
        for(int i = 1; i <= (n - 1) / 2; ++i){
                if(i == 1){
                        Output(Ch, n);
                        cout << endl;
                }
                else{
                        cout << Ch;
                        Output(' ', n - 2);
                        cout << Ch << endl;
                }
        }
        Output(Ch, n);
        return 0;
}
