#include <iostream>
using namespace std;
#define MAX_NUM 1000
int main(){
        int n, step = 0;
        cin >> n;
        while(n  != 1){
                if(n % 2 == 0)
                        n /= 2;
                else
                        n = (3 * n + 1) / 2;
                step++;
        }
        cout << step;
        return 0;
}
