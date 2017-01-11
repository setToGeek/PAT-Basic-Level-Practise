#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <assert.h>

using namespace std;

const string bits[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string tens[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void mars_to_earth(const string &num){
    if(num.size() < 5){
        int i = 0;
        for(; i < 12; ++i){
            if(num == tens[i]){
                cout << (i + 1) * 13 << endl;
                break;
            }
        }
        if(i == 12){
            for(int j = 0; j < 13; ++j){
                if(num == bits[j]){
                    cout << j << endl;
                    break;
                }
            }
        }
    }
    else{
        string e_t(num, 0, 3), e_b(num, 4);
        int t, b;
        int i;
        for(i = 0; i < 12; ++i){
            if(e_t == tens[i]){
                t = i + 1;
                break;
            }
        }
        // assert(i != 12);
        for(i = 0; i < 13; ++i){
            if(e_b == bits[i]){
                b = i;
                break;
            }
        }
        // assert(i != 13);
        cout << b + t * 13 << endl;
    }
}

void earth_to_mars(const int &e){
    if(e < 13){
        cout << bits[e] << endl;
    }
    else{
        int e_b = e % 13;
        int e_t = e / 13;
        cout << tens[e_t - 1];
        if(e_b != 0)
            cout <<' ' << bits[e_b];
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cin.get();

    while(n--){
        string nums;
        getline(cin, nums);
        char c = nums[0];
        if(c >= 48 && c <= 57){
            char num[4];
            strcpy(num, nums.c_str());
            int t = atoi(num);
            earth_to_mars(t);
        }
        else{
            mars_to_earth(nums);
        }
    }

    return 0;
}
