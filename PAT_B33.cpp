#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
    char broken_key[100001], input[100001];
    cin >> broken_key >> input;
    // char broken_key[] = "";
    // char input[] = "7_This_iEsS_a_Ttest.";

    //cin >> broken_key >> input; broken_key输入为空行时会读取input作为它的输入
    //结果是错误的,应该改为while或者cin.getline(broken_key, 50);
    int if_broken[128] = {0};
    for(int i = 0; i < strlen(broken_key); ++i){
        int tmp = broken_key[i];
        if_broken[tmp] = 1;
        if_broken[tolower(tmp)] = 1;
    }
    if(if_broken['+'] == 1){
        for(int i = 65; i < 91; ++i)
            if_broken[i] = 1;
    }

    for(int i = 0; i < strlen(input); ++i){
        char ch = input[i];
        if(if_broken[ch] == 0)
            printf("%c", ch);
    }
    return 0;
}
