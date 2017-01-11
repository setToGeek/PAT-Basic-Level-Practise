#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
    stack<int> input_a, input_b;
    stack<char> output;

    char c;
    while((c = cin.get()) != ' '){
        int t = c - 48;
        input_a.push(t);
    }
    while((c = cin.get()) != '\n'){
        int t = c - 48;
        input_b.push(t);
    }

    int i = 1;
    while(!input_a.empty() || !input_b.empty()){
        int a, b, t;
        char ch;
        if(!input_a.empty()){
            a = input_a.top();
            input_a.pop();
        }
        else
            a = 0;
        if(!input_b.empty()){
            b = input_b.top();
            input_b.pop();
        }
        else
            b = 0;
        if(i % 2 == 1){
            t = (a + b) % 13;
            if(t >= 10){
                switch(t){
                    case 10:
                        ch = 'J';
                        break;
                    case 11:
                        ch = 'Q';
                        break;
                    case 12:
                        ch = 'K';
                        break;
                }
            }
            else{
                ch = 48 + t;
            }
            output.push(ch);
        }
        else{
            t = (b - a + 10) % 10;
            ch = 48 + t;
            output.push(ch);
        }
        ++i;
    }

    // while(!input_b.empty()){
    //     int t;
    //     char ch;
    //     t = input_b.top();
    //     ch = t + 48;
    //     output.push(ch);
    //     input_b.pop();
    // }

    while(!output.empty()){
        char ch = output.top();
        cout << ch;
        output.pop();
    }

    return 0;
}
