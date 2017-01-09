#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
    int couples[100001] = {-1};
    int guest[100001] = {0};

    int n;
    cin >> n;
    while(n--){
        int m, f;
        cin >> m >> f;
        couples[m] = f;
        couples[f] = m;
    }

    cin >> n;
    while(n--){
        int t;
        cin >> t;
        guest[t] = 1;
    }

    int output[50000], len = 0;
    for(int i = 0; i < 100001; ++i){
        if(guest[i] == 1){
            if(couples[i] == -1){
                output[len++] = i;
            }
            else if(guest[couples[i]] == 0){
                output[len++] = i;
            }
            else{
                guest[couples[i]] = 0;
            }
        }
    }

    cout << len << endl;
    for(int i = 0; i < len; ++i){
        if(i != 0)
            cout << ' ';
        cout << setw(5) << setfill('0') << output[i];
    }

    return 0;
}
