#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, tag = 0;
    char b[101];
    cin >> a >> b;
    int digits = strlen(b);
    if (digits % 2 == 1) {
        tag = 1;
    }
    for (int i = 0; i < digits; i++) {
        int tmp;
        if ((i + tag) % 2 == 1) {
            tmp = (b[i] - 48 + a) % 13;
            if (tmp >= 10) {
                cout << tmp << " ";
                b[i] = 64 + tmp;
            }
            else {
                b[i] = tmp + 48;
            }
        }
        else{
            tmp = b[i] - 48 - a;
            tmp %= 10;
            if(tmp < 0)
                tmp += 10;
            b[i] = tmp + 48;
        }
    }
    cout << b;
    return 0;
}
