#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    char integar[4], rintegar[4];
    cin >> integar;
    while(integar != "0000" && integar != "6174"){
        int tag = 0;
        sort(integar, integar + 4);
        for(int i = 0; i < 4; i++){
            rintegar[i] = integar[3 - i];
        }
        // cout << rintegar << " - " << integar << " = ";
        for(int i = 3; i > -1; i--){
            if(rintegar[i] + tag < integar[i]){
                integar[i] = tag + rintegar[i] + 10 - integar[i];
                tag = -1;
            } else
                integar[i] = rintegar[i] + tag - integar[i];
        }
        cout << integar << endl;
    }
    return 0;
}
