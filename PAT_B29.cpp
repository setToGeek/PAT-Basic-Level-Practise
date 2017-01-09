#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
    char dest_out[81], real_out[81], output[81];
    // char output[81];
    int ptr = 0;
    cin >> dest_out >> real_out;
    // char real_out[] = "_hs_s_a_es";
    // char dest_out[] = "7_This_is_a_test";

    sort(real_out, real_out + strlen(real_out));
    for(int i = 0; i < strlen(dest_out); ++i){
        char ch;
        if(!binary_search(real_out, real_out + strlen(real_out), dest_out[i])){
            ch = toupper(dest_out[i]);
            if(find(output, output + ptr, ch) == output + ptr){
                output[ptr++] = ch;
                cout << ch;
            }
        }
    }
    return 0;
}
